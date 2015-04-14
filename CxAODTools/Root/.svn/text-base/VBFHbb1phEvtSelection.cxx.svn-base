#include "CxAODTools/VBFHbb1phEvtSelection.h"

#include "xAODEgamma/Electron.h"
#include "xAODEgamma/Photon.h"
#include "xAODMuon/Muon.h"
#include "xAODJet/Jet.h"
#include "xAODEventInfo/EventInfo.h"


void VBFHbb1phEvtSelection::clearResult(){
  m_result.pass = false;
  m_result.jets.clear();
  m_result.ph = nullptr;
}

bool VBFHbb1phEvtSelection::passSelection(const xAOD::EventInfo* evtinfo,
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
  return VBFHbbEvtSelection<ResultVBFHbb1ph>::passSelection(evtinfo, met, electrons,
							    photons, muons,taus,  jets);
}

bool VBFHbb1phEvtSelection::passPhotonSelection(const xAOD::PhotonContainer* photons){
  
  int res = doVBFPhotonSelection(photons, m_result.ph);
  if(res != 1)
    return false;
  
  return true;

}


bool VBFHbb1phEvtSelection::passPreSelection(const xAOD::EventInfo* evtinfo,
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
  return VBFHbbEvtSelection<ResultVBFHbb1ph>::passPreSelection(evtinfo, met, electrons,
							       photons, muons, taus, jets, fatjets);
}


bool VBFHbb1phEvtSelection::passPhotonPreSelection(const xAOD::PhotonContainer* photons){
  
  int res = doVBFPhotonPreSelection(photons, m_result.ph);
  if(res != 1)
    return false;
  
  return true;

}

void VBFHbb1phEvtSelection::writeEventVariables(const xAOD::EventInfo* eventInfoIn,
        xAOD::EventInfo* eventInfoOut,
        bool isKinVar,
        bool isWeightVar) {

}

bool VBFHbb1phEvtSelection::passKinematics() {
  // MJ cuts, like MET / MPT etc...
  // my advice is to add in passKinematics() prototype all the stuff that          
  // doesn't need to be put in the Result struct, like MPT
  return true;
}
