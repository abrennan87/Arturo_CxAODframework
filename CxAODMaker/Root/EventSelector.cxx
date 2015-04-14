#include "CxAODMaker/EventSelector.h"

#include "CxAODMaker/ObjectHandlerBase.h"

#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <vector>

EventSelector::EventSelector(ConfigStore& config) :
  m_config(config),
  m_debug(false),
  m_jets(nullptr),
  m_fatjets(nullptr),
  m_trackjets(nullptr),
  m_muons(nullptr),
  m_taus(nullptr),
  m_electrons(nullptr),
  m_photons(nullptr),
  m_met(nullptr),
  m_info(nullptr),
  m_doOR(true),
  m_selection(nullptr),
  m_systematics(),
  m_isFirstCall(true)
{
  m_config.getif<bool>("removeOverlap", m_doOR);
  m_OR=new OverlapRemover(config);
  m_config.getif<bool>("debug", m_debug);

  // Recognize weight variations ! 
  std::vector<std::string> weightVariations;
  m_config.getif< std::vector<std::string> >("weightVariations", weightVariations);
  std::vector<std::string> pulls = {"1down", "1up"};
  for (std::string name : weightVariations) {
    for (std::string pull : pulls) {
      m_weightVariations.push_back((name + "__" + pull).c_str());
    }
  }
}

EventSelector::~EventSelector() {
  // we are the owner of the EventSelection object
  delete m_selection;
  delete m_OR;
}

void EventSelector::setOverlapRemoval(OverlapRemoval* OR) {
  m_OR->setOverlapRemoval(OR);
}

void EventSelector::setJets(JetHandler* jets) {
  m_jets = jets;
  m_OR->setJets(jets);
  if(!jets) return;
  if(m_doOR) jets->useForOR(true);
}

void EventSelector::setFatJets(FatJetHandler* jets) {
  m_fatjets = jets;
  //m_OR->setJets(jets);
  //if(!jets) return;
  //if(m_doOR) jets->useForOR(true);
}

void EventSelector::setTrackJets(TrackJetHandler* jets) {
  m_trackjets = jets;
}

void EventSelector::setUngroomedJets(UngroomedJetHandler* jets) {
  m_ungroomedjets = jets;
}


void EventSelector::setGroomedJets(GroomedJetHandler* jets) {
  m_groomedjets = jets;
}


void EventSelector::setTrimmedJets(TrimmedJetHandler* jets) {
  m_trimmedjets = jets;
}

void EventSelector::setMuons(MuonHandler* muons) {
  m_muons = muons;
  m_OR->setMuons(muons);
  if(!muons) return;
  if(m_doOR) muons->useForOR(true);
}

void EventSelector::setTaus(TauHandler* taus) {
  m_taus = taus;
  m_OR->setTaus(taus);
}

void EventSelector::setElectrons(ElectronHandler* electrons) {
  m_electrons = electrons;
  m_OR->setElectrons(electrons);
  if(!electrons) return;
  if(m_doOR) electrons->useForOR(true);
}

void EventSelector::setPhotons(PhotonHandler* photons) {
  m_photons = photons;
  if(!photons) return;
  m_OR->setPhotons(photons);
  if(m_doOR) photons->useForOR(true);
}

EL::StatusCode EventSelector::fillSystematics(ObjectHandlerBase* obj) {
  if(m_debug) Info("EventSelector::fillSystematics()","");
  if(obj) {
    std::vector<TString> systs = obj->getAllVariations();
    for (const TString& sysName : systs) {
      m_systematics.insert(sysName.Data());
    }
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode EventSelector::fillSystematics() {
  // as we use a set<>, the systematics should be there only once in the end
  // so no risk to double count the nominal, or e.g jet systematics between JetHandler
  // and METHandler
  if(fillSystematics(m_jets) != EL::StatusCode::SUCCESS){
    Error("EventSelector::fillSystematics()","Failed to fill systematics for jets! Exiting.");
    return EL::StatusCode::FAILURE;
  }
  if(fillSystematics(m_fatjets) != EL::StatusCode::SUCCESS){
    Error("EventSelector::fillSystematics()","Failed to fill systematics for fatjets! Exiting.");
    return EL::StatusCode::FAILURE;
  }
  if(fillSystematics(m_trackjets) != EL::StatusCode::SUCCESS){
    Error("EventSelector::fillSystematics()","Failed to fill systematics for trackjets! Exiting.");
    return EL::StatusCode::FAILURE;
  }
  if(fillSystematics(m_muons) != EL::StatusCode::SUCCESS){
    Error("EventSelector::fillSystematics()","Failed to fill systematics for muons! Exiting.");
    return EL::StatusCode::FAILURE;
  }
  if(fillSystematics(m_taus) != EL::StatusCode::SUCCESS){
    Error("EventSelector::fillSystematics()","Failed to fill systematics for taus! Exiting.");
    return EL::StatusCode::FAILURE;
  }
  if(fillSystematics(m_electrons) != EL::StatusCode::SUCCESS){
    Error("EventSelector::fillSystematics()","Failed to fill systematics for electrons! Exiting.");
    return EL::StatusCode::FAILURE;
  }
  if(fillSystematics(m_photons) != EL::StatusCode::SUCCESS){
    Error("EventSelector::fillSystematics()","Failed to fill systematics for photons! Exiting.");
    return EL::StatusCode::FAILURE;
  }
  // TODO add MET systematics when MET depends on ObjectHandler

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode EventSelector::performSelection(bool& pass) {
  if(m_debug) Info("EventSelector::performSelection(bool& pass)","");

  if(m_isFirstCall) {
    if(fillSystematics() != EL::StatusCode::SUCCESS){
      Error("EventSelector::fillSystematics()","Failed to fill systematics! Exiting.");
      return EL::StatusCode::FAILURE;
    }
  }

  if(!m_selection) {
    if(m_isFirstCall) {
      Warning("EventSelector::performSelection()", "No event preselection has been set ! All events will pass");
    }
  }

  m_isFirstCall = false;

  // run on all systematics
  pass = false;
  for(const std::string& sysName : m_systematics) {
    pass |= passORandPreSel(sysName.c_str());
  }

  return EL::StatusCode::SUCCESS;

}

bool EventSelector::passORandPreSel(const TString& sysName) {
  if(m_debug) Info("EventSelector::passORandPreSel()","");

  // if no OR, then no selection at all
  if(!m_doOR) { return true; }

  EL::StatusCode res = m_OR->removeOverlap(sysName);
  if(res != EL::StatusCode::SUCCESS) {
    Error("EventSelector::passORandPreSel", "There has been an issue with the OR. Please investigate !");
    exit(EXIT_FAILURE);
  }

  if(!m_selection) {
    return true;
  }

  return performSelection(sysName);
}

bool EventSelector::performSelection(const TString& sysName) {
  if(m_debug) Info("EventSelector::performSelection(const TString& sysName)","");
  // first, retrieve the containers. Always check for nullptr, in case some analyses don't use some containers
  xAOD::JetContainer* jets = nullptr;
  if(m_jets) { jets = m_jets->getInParticleVariation(sysName); }
  xAOD::JetContainer* fatjets = nullptr;
  if(m_fatjets) { fatjets = m_fatjets->getInParticleVariation(sysName); }
  //xAOD::JetContainer* trackjets = nullptr;
  //if(m_trackjets) { trackjets = m_trackjets->getInParticleVariation(sysName); }
  xAOD::ElectronContainer* electrons = nullptr;
  if(m_electrons) { electrons = m_electrons->getInParticleVariation(sysName); }
  xAOD::PhotonContainer* photons = nullptr;
  if(m_photons) { photons = m_photons->getInParticleVariation(sysName); }
  xAOD::MuonContainer* muons = nullptr;
  if(m_muons) { muons = m_muons->getInParticleVariation(sysName); }
  xAOD::TauJetContainer* taus = nullptr;
  if(m_taus) { taus = m_taus->getInParticleVariation(sysName); }
  
  if(m_debug) Info("EventSelector::performSelection()","Successfully retrieved InParticleVariations." );

  // at the moment no systematics for MET. Will hopefully change.
  xAOD::MissingET* met = nullptr;
  if(m_met) { met = m_met->getMET(); }

  // at the moment no systematics for METTrack. Will hopefully change.                                                                          
  xAOD::MissingET* mettrack = nullptr;
  if(m_met) { mettrack = m_met->getMETTrack(); }


  // event info is required !
  if(! m_info) {
    Error("EventSelector::performSelection",
          "We need to know about EventInfo ! Please call setEventInfo before any attempt to apply selections");
    exit(EXIT_FAILURE);
  }

  // input event info for selection
  const xAOD::EventInfo* evtinfo = m_info->getEventInfo();
 
  // output event info for writing results
  xAOD::EventInfo* evtinfoOut = m_info->getOutEventInfoVariation(sysName);
 
  // presence of m_selection has been checked in performSelection(bool)
  bool pass = m_selection->passPreSelection(evtinfo, met, electrons, photons, muons, taus, jets, fatjets);
 
  // is it a variation?
  bool isKinVar = (sysName != "Nominal");
  bool isWeightVar = false;
  for(unsigned int iWeightVar=0; iWeightVar<m_weightVariations.size() ; ++iWeightVar ){
    if( sysName == m_weightVariations[iWeightVar]) {
      isWeightVar = true;
      isKinVar = false;
    }
  }
 
  // do not write eventvariables for original! otherwise the Nominal Block gets overwritten!
  if (sysName == "Original")
    return pass;
 
  m_selection->writeEventVariables(evtinfo, evtinfoOut, isKinVar, isWeightVar);
 
  return pass;
}

