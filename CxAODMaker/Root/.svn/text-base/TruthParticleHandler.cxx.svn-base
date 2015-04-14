#include <iostream>

// truth specific includes
#include "CxAODMaker/TruthParticleHandler.h"

TruthParticleHandler::TruthParticleHandler(const std::string& name, ConfigStore & config,
                                           xAOD::TEvent * event, EventInfoHandler & eventInfoHandler) :
  ObjectHandler(name, config, event, eventInfoHandler)
{

  // don't need element links for truth (and it's very slow)
  m_createElementLinks = false;

  // do not store original container for truth particles
  m_storeOrig = false;
  
  // set container name
  m_config.getif<std::string>("truthParticleContainer",m_containerName);
}


TruthParticleHandler::~TruthParticleHandler()
{

}


EL::StatusCode TruthParticleHandler::initializeTools() 
{

  return EL::StatusCode::SUCCESS; 
}


EL::StatusCode TruthParticleHandler::setObjects() 
{

  if (!m_eventInfoHandler.get_isMC()) {
    return EL::StatusCode::SUCCESS;
  }

  if (!m_event->retrieve(m_vtxContainer, "TruthVertex").isSuccess()) {
     Error("ObjectHandler::setObjects()", ("Failed to retrieve particle container '" + m_containerName + "'").c_str());
     return EL::StatusCode::FAILURE;
  }
  return ObjectHandler::setObjects();
}


void print(xAOD::TruthParticle * part, int select) {

  // debugging output

  return;

  std::cout << std::fixed;
  std::cout << "\tbar=" << std::setw(7) << part->barcode();
  std::cout << "\tpdgId=" << std::setw(4) << part->pdgId();
  std::cout << "\tstatus=" << std::setw(2) << part->status();
  std::cout << "\tpt=" << std::setprecision(1) << part->pt();
  std::cout << "\teta=" << std::setprecision(3) << part->eta();
  std::cout << "\tphi=" << std::setprecision(3) << part->phi();
  std::cout << "\tE=" << std::setprecision(1) << part->e();
  std::cout << "\tnPar=" << part->nParents();
  std::cout << " ( ";
  for (unsigned int i = 0; i < part->nParents(); ++i) std::cout << part->parent(i)->barcode() << " ";
  std::cout << ")";
  std::cout << "\tnChi=" << part->nChildren();
  std::cout << " ( ";
  for (unsigned int i = 0; i < part->nChildren(); ++i) std::cout << part->child(i)->barcode() << " ";
  std::cout << ")";

  if (select > 0) std::cout << " * (" << select << ")" << std::endl;
  else std::cout << std::endl;
  
}

/**
 * This function decides if a particle should be saved or not
 */
bool TruthParticleHandler::checkPassSel(xAOD::TruthParticle * part) 
{

  // TODO: check for MC channel number to make it robust against generator changes
    
  // speed up
  if (!(part->status() == 1 || part->status() == 2 || part->status() == 3 || part->status() == 23 || part->status() == 62)) return false;
    
  // check top decay
  // 1) powheg, acerMC:
  //    - status==3 for hard process
  //    - require part->status() == 3 for all particles;

  if (part->isTop() && part->status() == 3) { print(part, 1); return true; }
  for (unsigned int i = 0; i < part->nParents(); ++i) {
      auto parent = part->parent(i);
      // check if parent is top
      if (parent->isTop() && part->status() == 3) { print(part, 2); return true; }
      if (parent->isW() && part->status() == 3) {
          // check is grandparent is top and parent is not bottom (not interested in bottom decay)
          for (unsigned int j = 0; j < parent->nParents(); ++j) {
              auto grandparent = parent->parent(j);
              if (grandparent->isTop() && part->status() == 3) { print(part, 3); return true; }
          }
      }
  }
  // check bottom from W->tb for single top diagrams
  if (part->absPdgId() == 5 && part->status() == 3) {
      for (unsigned int i = 0; i < part->nParents(); ++i) {
          auto parent = part->parent(i);
          // check if parent is top
          for (unsigned int j = 0; j < parent->nChildren(); ++j) {
              auto sibling = parent->child(j);
              // check if sibling is top)
              if (sibling->isTop() && sibling->status() == 3) { print(part, 4); return true; }
          }
      }
  }

  // check Higgs decay
  // 1) pythia
  //    - event record contains several Higgs with different status codes
  //    - need to select part->status() == 62
  //      from pythia manual:
  //      62 : outgoing subprocess particle with primordial kT included
  //    - b from Higgs has status() == 23
  //      from pythia manual:
  //      23: outgoing
  
  if (part->isHiggs() && part->status() == 62 ) { print(part, 5); return true; }
  if (part->absPdgId() == 5 && part->status() == 23) {
      for (unsigned int i = 0; i < part->nParents(); ++i) {
          auto parent = part->parent(i);
          // check if parent is Higgs
          if (parent->isHiggs() && parent->status() == 62) { print(part, 6); return true; }
      }
  }

  // check vector bosons
  // 1) powheg:
  //    - need to select part->status() == 3 for W/Z from hard process
  //    - status code 2 involves internal W -> W, but also W -> lnu
  // 2) pythia8
  //    - need to select part->status() == 62 for W/Z
  //    - need to select part->status() == 1,2 for l/nu
  // 3) sherpa
  //    - sherpa does not store (virtual) W, but only final state partons from hard process
  //    - status() == 3

  // 1) powheg
  if ((part->isW() || part->isZ()) && part->status() == 3) { print(part, 7); return true; }
  if (part->isLepton() && part->status() == 3) {
      // skip hadronic V decays, as they are very messy
      for (unsigned int i = 0; i < part->nParents(); ++i) {
          auto parent = part->parent(i);
          // check if parent is W/Z
          if ( (parent->isW() || parent->isZ()) && parent->status() == 3) { print(part, 8); return true; }
      }
  }

  // 2) pythia8
  if ((part->isW() || part->isZ()) && (part->status() == 62)) { print(part, 9); return true; }
  if (part->isLepton() && (part->status() == 1 || part->status() == 2)) {
      // skip hadronic V decays, as they are very messy
      for (unsigned int i = 0; i < part->nParents(); ++i) {
          auto parent = part->parent(i);
          // check if parent is W/Z
          if ( (parent->isW() || parent->isZ()) && (parent->status() == 62) ) { print(part, 10); return true; }
      }
  }

  // 3) sherpa
  if (part->isLepton() && part->status() == 3) {
      for (unsigned int i = 0; i < part->nParents(); ++i) {
          auto parent = part->parent(i);
          // check if parent is also from hard process (to distinguish from pythia)
          if (parent->status() == 3) { print(part, 11); return true; }
      }
  }

//   print(part, 0);
  
  return false;  
}


EL::StatusCode TruthParticleHandler::fillOutputContainer() 
{
  if (!m_eventInfoHandler.get_isMC()) {
    return EL::StatusCode::SUCCESS;
  }
  return fillOutputContainerCheck(&checkPassSel);
}


/**
 * Perform cleaning if needed
 */
EL::StatusCode TruthParticleHandler::clearEvent() 
{
  
  if (ObjectHandler::clearEvent() != EL::StatusCode::SUCCESS) {
    Error("EL::StatusCode TruthParticleHandler::clearEvent()", "Failed to clear event in object handler!");
    return EL::StatusCode::FAILURE;
  }
  return EL::StatusCode::SUCCESS;
}


/**
 * No decoration is needed here
 */
EL::StatusCode TruthParticleHandler::decorate(xAOD::TruthParticle * particle) 
{

  return EL::StatusCode::SUCCESS;
}


/**
 * No calib is needed here
 */
EL::StatusCode TruthParticleHandler::calibrateCopies(xAOD::TruthParticleContainer * particles, const CP::SystematicSet & sysSet) 
{
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode TruthParticleHandler::setVariables(xAOD::TruthParticle * inPart, xAOD::TruthParticle * outPart, bool isKinVar, bool isWeightVar) 
{
  
  // set kinematics
  setP4( inPart , outPart );

  outPart->setPdgId(inPart->pdgId());

  // the next two are temp for testing
  outPart->setBarcode(inPart->barcode());
  outPart->setStatus(inPart->status());

  outPart->toPersistent();

  return EL::StatusCode::SUCCESS;

}
