#ifndef CxAOD__VBFHbb1phEvtSelection_H
#define CxAOD__VBFHbb1phEvtSelection_H

#include <vector>

#include "VBFHbbEvtSelection.h"

struct ResultVBFHbb1ph
{
  bool pass;
  const xAOD::Photon* ph;
  std::vector<const xAOD::Jet*> jets;
};

class VBFHbb1phEvtSelection : public VBFHbbEvtSelection<ResultVBFHbb1ph>
{
 public:
  VBFHbb1phEvtSelection() = default;
  virtual ~VBFHbb1phEvtSelection() noexcept {}

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
  virtual  bool passPhotonSelection(const xAOD::PhotonContainer* photons);

  virtual  bool passPhotonPreSelection(const xAOD::PhotonContainer* photons);

  virtual bool passKinematics();

  virtual void clearResult();

};

#endif
