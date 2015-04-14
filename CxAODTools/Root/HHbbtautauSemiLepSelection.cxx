#include "CxAODTools/HHbbtautauSemiLepSelection.h"
#include "xAODTau/TauJet.h"
#include "xAODEgamma/Electron.h"
#include "xAODEgamma/Photon.h"
#include "xAODMuon/Muon.h"
#include "xAODJet/Jet.h"
#include "xAODEventInfo/EventInfo.h"


void HHbbtautauSemiLepSelection::clearResult() {
  m_result.pass = false;
  m_result.taus.clear();
  m_result.jets.clear();
  m_result.met = nullptr;
  m_result.mu=nullptr; 
  m_result.el=nullptr;

}

bool HHbbtautauSemiLepSelection::passSelection(const xAOD::EventInfo* evtinfo,
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
 
  return HHbbtautauSelection<ResultHHbbtautauSemiLep>::passSelection(evtinfo, met, electrons, photons, muons, taus, jets);
}

bool HHbbtautauSemiLepSelection::passLeptonSelection(const xAOD::ElectronContainer* electrons,
                                               const xAOD::MuonContainer* muons,
                                               const xAOD::MissingET* met) {
  const xAOD::Electron* el_junk=nullptr;
  const xAOD::Muon* mu_junk=nullptr;
  int res = doHHLeptonSelection(electrons, muons, m_result.el, el_junk, m_result.mu, mu_junk);
  if(res != 1) {
    return false;
  }
  m_result.met = met;
  return true;

}

// preselection versions
bool HHbbtautauSemiLepSelection::passPreSelection(const xAOD::EventInfo* evtinfo,
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
  return HHbbtautauSelection<ResultHHbbtautauSemiLep>::passPreSelection(evtinfo, met, electrons, photons,
                                                            muons, taus, jets, fatjets);
}

bool HHbbtautauSemiLepSelection::passLeptonPreSelection(const xAOD::ElectronContainer* electrons,
                                               const xAOD::MuonContainer* muons,
                                               const xAOD::MissingET* met) {
 const xAOD::Electron* el_junk=nullptr;
  const xAOD::Muon* mu_junk=nullptr;
  int res = doHHLeptonPreSelection(electrons, muons, m_result.el, el_junk, m_result.mu, mu_junk);
  if(res != 1) {
    return false;
  }
  return true;

}

void HHbbtautauSemiLepSelection::writeEventVariables(const xAOD::EventInfo* eventInfoIn,
        xAOD::EventInfo* eventInfoOut,
        bool isKinVar,
        bool isWeightVar) {

}

bool HHbbtautauSemiLepSelection::passKinematics() {
  // MJ cuts, like MET / MPT etc...
  // my advice is to add in passKinematics() prototype all the stuff that
  // doesn't need to be put in the Result struct, like MPT

  return true;
}
