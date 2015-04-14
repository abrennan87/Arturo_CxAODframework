#ifndef CxAODTools__HHbbtautauSelection_H
#define CxAODTools__HHbbtautauSelection_H

#include "EventSelection.h"

namespace xAOD {
#ifndef XAODEGAMMA_ELECTRON_H
  class Electron;
#endif
#ifndef XAODEGAMMA_PHOTON_H
  class Photon;
#endif
#ifndef XAODMUON_MUON_H
  class Muon;
#endif
#ifndef XAODJET_JET_H
  class Jet;
#endif
#ifndef XAODTAUJET_TAU_H
  class Tau;
#endif

}

template <typename T>
class HHbbtautauSelection : public EventSelection
{
  protected:
    T m_result;

  public:
    HHbbtautauSelection() noexcept;

    virtual ~HHbbtautauSelection() noexcept {}

    virtual T& result() { return m_result; } // probably should be const ?

    virtual bool passPreSelection(const xAOD::EventInfo* evtinfo,
                                  const xAOD::MissingET* met,
                                  const xAOD::ElectronContainer* electrons,
				  const xAOD::PhotonContainer* photons,
                                  const xAOD::MuonContainer* muons,
				  const xAOD::TauJetContainer* taus,
                                  const xAOD::JetContainer* jets,
                                  const xAOD::JetContainer* fatjets);

    virtual bool passSelection(const xAOD::EventInfo* evtinfo,
                               const xAOD::MissingET* met,
                               const xAOD::ElectronContainer* electrons,
			       const xAOD::PhotonContainer* photons,
                               const xAOD::MuonContainer* muons,
			       const xAOD::TauJetContainer* taus,
                               const xAOD::JetContainer* jets);

  protected:
    virtual bool passJetSelection(const xAOD::JetContainer* jets);
    virtual bool passFatJetSelection(const xAOD::JetContainer* jets);
    virtual bool passTauSelection(const xAOD::TauJetContainer* taus);

    virtual bool passLeptonSelection(const xAOD::ElectronContainer* electrons,
                                     const xAOD::MuonContainer* muons,
                                     const xAOD::MissingET* met) = 0;

    virtual bool passJetPreSelection(const xAOD::JetContainer* jets);
    virtual bool passFatJetPreSelection(const xAOD::JetContainer* jets);

    virtual bool passLeptonPreSelection(const xAOD::ElectronContainer* electrons,
                                        const xAOD::MuonContainer* muons,
                                        const xAOD::MissingET* met) = 0;

    virtual bool passKinematics();

    virtual void clearResult() = 0;

    /// ensures consistency between channels
    int doHHLeptonSelection(const xAOD::ElectronContainer* electrons,
                            const xAOD::MuonContainer* muons,
                            const xAOD::Electron*& el1, const xAOD::Electron*& el2,
                            const xAOD::Muon*& mu1, const xAOD::Muon*& mu2);

    int doHHLeptonPreSelection(const xAOD::ElectronContainer* electrons,
                               const xAOD::MuonContainer* muons,
                               const xAOD::Electron*& el1, const xAOD::Electron*& el2,
                               const xAOD::Muon*& mu1, const xAOD::Muon*& mu2);

};

#include "CxAODTools/HHbbtautauSelection.icc"

#endif
