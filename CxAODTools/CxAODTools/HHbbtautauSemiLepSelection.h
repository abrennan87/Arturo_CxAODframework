#ifndef CxAOD__HHbbtautauSemiLepSelection_H
#define CxAOD__HHbbtautauSemiLepSelection_H

#include <vector>

#include "HHbbtautauSelection.h"

// structure holding kinematics of the result
struct ResultHHbbtautauSemiLep
{
  bool pass;
  const xAOD::Electron* el;
  const xAOD::Muon* mu;
  const xAOD::MissingET* met;
  std::vector<const xAOD::TauJet*> taus;
  std::vector<const xAOD::Jet*> jets;
  
};

class HHbbtautauSemiLepSelection : public HHbbtautauSelection<ResultHHbbtautauSemiLep>
{
  public:
    HHbbtautauSemiLepSelection() = default;
    virtual ~HHbbtautauSemiLepSelection() noexcept {}


    virtual bool passSelection(const xAOD::EventInfo* evtinfo,
                               const xAOD::MissingET* met,
                               const xAOD::ElectronContainer* electrons,
			       const xAOD::PhotonContainer* photons,
                               const xAOD::MuonContainer* muons,
			       const xAOD::TauJetContainer* taus,
                               const xAOD::JetContainer* jets);

    virtual bool passPreSelection(const xAOD::EventInfo* evtinfo,
                                  const xAOD::MissingET* met,
                                  const xAOD::ElectronContainer* electrons,
				  const xAOD::PhotonContainer* photons,
                                  const xAOD::MuonContainer* muons,
				  const xAOD::TauJetContainer* taus,
                                  const xAOD::JetContainer* jets,
                                  const xAOD::JetContainer* fatjets);

    virtual void writeEventVariables(const xAOD::EventInfo* eventInfoIn,
                             xAOD::EventInfo* eventInfoOut,
                             bool isKinVar,
                             bool isWeightVar);

  protected:
    virtual bool passLeptonSelection(const xAOD::ElectronContainer* electrons,
                                     const xAOD::MuonContainer* muons,
                                     const xAOD::MissingET* met);

    virtual bool passLeptonPreSelection(const xAOD::ElectronContainer* electrons,
                                        const xAOD::MuonContainer* muons,
                                        const xAOD::MissingET* met);
 
    virtual bool passKinematics();

    virtual void clearResult();

};

#endif
