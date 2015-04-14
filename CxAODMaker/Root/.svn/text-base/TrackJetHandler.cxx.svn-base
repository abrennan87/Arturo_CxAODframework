#include <iostream>
//#include "xAODRootAccess/TStore.h"

// jet specific includes
//#include "xAODJet/JetContainer.h"
//#include "xAODJet/JetAuxContainer.h"
#include "CxAODMaker/TrackJetHandler.h"

// declare static members
TrackJetDecorator TrackJetHandler::m_decorator;

TrackJetHandler::TrackJetHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
                             EventInfoHandler & eventInfoHandler) : 
  ObjectHandler(name, config, event, eventInfoHandler) 
{
  m_selectFcns.push_back(&passTrackJet);
}


TrackJetHandler::~TrackJetHandler() 
{

}

EL::StatusCode TrackJetHandler::initializeTools()
{

  // register ISystematicsTools
  //---------------------------
  m_sysToolList.clear();

  return EL::StatusCode::SUCCESS;

}


EL::StatusCode TrackJetHandler::decorate(xAOD::Jet * jet) 
{

   // jet vertex fraction
/*   std::vector<float> jvf;
   jet->getAttribute("JVF", jvf);

   if( jvf.size() > 0) {
     m_decorator.set(jet, FatJetFloatProps::JVF,jvf[0]);
   } else  {
     m_decorator.set(jet, FatJetFloatProps::JVF,0);
   }
  */ 
  // substructure moments: n-subjettiness
//  float tau1(-1.), tau2(-1.), tau3(-1.);
//  float tau21(-1.), tau32(-1.);
  
//  jet->getAttribute("Tau1", tau1);
//  jet->getAttribute("Tau2", tau2);
//  jet->getAttribute("Tau3", tau3);

//  if (tau2 > 0.) tau21 = tau2 / tau1;
//  if (tau3 > 0.) tau32 = tau3 / tau2;

//  m_decorator.set(jet, FatJetFloatProps::Tau21, tau21);
//  m_decorator.set(jet, FatJetFloatProps::Tau32, tau32);
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode TrackJetHandler::calibrateCopies(xAOD::JetContainer * particles, const CP::SystematicSet & sysSet) 
{

  // loop over the particles in the container
  for (xAOD::Jet * jet : *particles) {
    //this ensures that the DynAux container has the same number of entries as the original one
    setP4( jet , jet );

    // print particle (pt,eta,phi,e,m)
    //std::cout << "===> Fat jet <===" << std::endl;
    //printParticle(jet);
    
    // apply calibrations

    // decorate jet
    if ( decorate( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
    
  }

  return EL::StatusCode::SUCCESS;

}


bool TrackJetHandler::checkPassSel(xAOD::Jet * part) 
{

  // TODO implement check like muon
  return true;

}

bool TrackJetHandler::passTrackJet(xAOD::Jet* jet)
{
  bool passTrackCut=false;
  if(jet->pt()>200000){
    if(fabs(jet->eta()) <2.0){
      passTrackCut=true;
    }
  }
  m_decorator.set(jet, TrackJetIntProps::isTrackJet, passTrackCut);

 return passTrackCut;
}

EL::StatusCode TrackJetHandler::setVariables(xAOD::Jet* inJet, xAOD::Jet* outJet, bool isKinVar, bool isWeightVar)
{
   // set four momentum
   outJet->setJetP4(inJet->jetP4());
   m_decorator.copy(inJet, outJet, TrackJetIntProps::isTrackJet);

   // jet vertex fraction from xAOD
//   m_decorator.copy(inJet, outJet, FatJetFloatProps::JVF);

   // substructure moments: n-subjettiness
//   m_decorator.copy(inJet, outJet, FatJetFloatProps::Tau21);
//   m_decorator.copy(inJet, outJet, FatJetFloatProps::Tau32);
   
   return EL::StatusCode::SUCCESS;

}


EL::StatusCode TrackJetHandler::fillOutputContainer() 
{

  return fillOutputContainerCheck(&checkPassSel);

}


EL::StatusCode TrackJetHandler::clearEvent() 
{
  if (ObjectHandler::clearEvent() != EL::StatusCode::SUCCESS) {
    Error("EL::StatusCode TrackJetHandler::clearEvent()", "Failed to clear event in object handler!");
    return EL::StatusCode::FAILURE;
  }
  return EL::StatusCode::SUCCESS;

}
