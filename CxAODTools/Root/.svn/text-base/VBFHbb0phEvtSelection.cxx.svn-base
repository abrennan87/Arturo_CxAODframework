#include "CxAODTools/VBFHbb0phEvtSelection.h"

#include "xAODEgamma/Electron.h"
#include "xAODEgamma/Photon.h"
#include "xAODMuon/Muon.h"
#include "xAODJet/Jet.h"
#include "xAODEventInfo/EventInfo.h"


void VBFHbb0phEvtSelection::clearResult(){
  m_result.pass = false;
  m_result.jets.clear();
}

bool VBFHbb0phEvtSelection::passSelection(const xAOD::EventInfo* evtinfo,
					  const xAOD::MissingET* met,
					  const xAOD::ElectronContainer* electrons,
					  const xAOD::PhotonContainer* photons,
					  const xAOD::MuonContainer* muons,
					  const xAOD::TauJetContainer* taus,
					  const xAOD::JetContainer* jets) {

  // here just as an example:
  // if a new passKinematics() function is defined with some variables in the prototype,
  // one needs to reimplement passSelection here
  // otherwise, don't need to put any code
  return VBFHbbEvtSelection<ResultVBFHbb0ph>::passSelection(evtinfo, met, electrons, 
							    photons, muons, taus, jets);
}


bool VBFHbb0phEvtSelection::passPhotonSelection(const xAOD::PhotonContainer* photons){
  
  const xAOD::Photon *ph=nullptr;
  int res = doVBFPhotonSelection(photons,ph);
  if(res != 0)
    return false;
  
  return true;

}


bool VBFHbb0phEvtSelection::passPreSelection(const xAOD::EventInfo* evtinfo,
					     const xAOD::MissingET* met,
					     const xAOD::ElectronContainer* electrons,
					     const xAOD::PhotonContainer* photons,
					     const xAOD::MuonContainer* muons,
					     const xAOD::TauJetContainer* taus,
					     const xAOD::JetContainer* jets,
					     const xAOD::JetContainer* fatjets) {

  // here just as an example:
  // if a new passKinematics() function is defined with some variables in the prototype,
  // one needs to reimplement passSelection here
  // otherwise, don't need to put any code
  return VBFHbbEvtSelection<ResultVBFHbb0ph>::passPreSelection(evtinfo, met, electrons, 
							       photons, muons, taus, jets, fatjets);
}


bool VBFHbb0phEvtSelection::passPhotonPreSelection(const xAOD::PhotonContainer* photons){
  
  const xAOD::Photon *ph=nullptr;
  int res = doVBFPhotonPreSelection(photons,ph);
  if(res != 0)
    return false;
  
  return true;

}


void VBFHbb0phEvtSelection::writeEventVariables(const xAOD::EventInfo* eventInfoIn,
        xAOD::EventInfo* eventInfoOut,
        bool isKinVar,
        bool isWeightVar) {

}

bool VBFHbb0phEvtSelection::passKinematics() {
  // MJ cuts, like MET / MPT etc...
  // my advice is to add in passKinematics() prototype all the stuff that
  // doesn't need to be put in the Result struct, like MPT
  return true;
}
