#ifndef CxAODTools__VBFHbbEvtSelection_H
#define CxAODTools__VBFHbbEvtSelection_H

#include "EventSelection.h"
#include "xAODEgamma/Photon.h"

namespace xAOD {
#ifndef XAODEGAMMA_PHOTON_H
  class Photon;
#endif
#ifndef XAODJET_JET_H
  class Jet;
#endif
#ifndef XAODEGAMMA_ELECTRON_H
  class Electron;
#endif
#ifndef XAODMUON_MUON_H
  class Muon;
#endif

}

template <typename T>
class VBFHbbEvtSelection : public EventSelection
{
  protected:
    T m_result;

  public:
    VBFHbbEvtSelection() noexcept;

    virtual ~VBFHbbEvtSelection() noexcept {}

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

    virtual bool passJetPreSelection(const xAOD::JetContainer* jets);

    virtual bool passPhotonSelection(const xAOD::PhotonContainer* photons) = 0;

    virtual bool passPhotonPreSelection(const xAOD::PhotonContainer* photons) = 0;

    virtual bool passKinematics();

    virtual void clearResult() = 0;


    int doVBFPhotonSelection(const xAOD::PhotonContainer* photons,
			     const xAOD::Photon*& ph);

    int doVBFPhotonPreSelection(const xAOD::PhotonContainer* photons,
				const xAOD::Photon*& ph);

};

#include "CxAODTools/VBFHbbEvtSelection.icc"

#endif
