#include "CxAODMaker/OverlapRemover.h"
#include "CxAODTools/ReturnCheck.h"

OverlapRemover::OverlapRemover(ConfigStore & config) :
  m_config(config),
  m_jets(nullptr),
  m_muons(nullptr),
  m_taus(nullptr),
  m_electrons(nullptr),
  m_photons(nullptr),
  m_decorator(),
  m_OR(nullptr)
{
 m_config.getif<bool>("debug", m_debug);
}


OverlapRemover::~OverlapRemover()
{
  if (m_OR) {
    delete m_OR;
  }
}


EL::StatusCode OverlapRemover::removeOverlap(const TString& sysName)
{
  if(m_debug) Info("OverlapRemover::removeOverlap", "...");

  if (!m_OR) {
    Error("OverlapRemover::removeOverlap", "OverlapRemoval was not initialized!");
    return EL::StatusCode::FAILURE;
  }
  
  // first, retrieve the containers. Always check for nullptr, in case some analyses don't use some
  // containers
  xAOD::JetContainer* jets = nullptr;
  if(m_jets) { jets = m_jets->getInParticleVariation(sysName); }
  xAOD::ElectronContainer* electrons = nullptr;
  if(m_electrons) { electrons = m_electrons->getInParticleVariation(sysName); }
  xAOD::PhotonContainer* photons = nullptr;
  if(m_photons) { photons = m_photons->getInParticleVariation(sysName); }
  xAOD::MuonContainer* muons = nullptr;
  if(m_muons) { muons = m_muons->getInParticleVariation(sysName); }
  xAOD::TauJetContainer* taus = nullptr;
  if(m_taus) { taus = m_taus->getInParticleVariation(sysName); }
  // next, perform the actual OR on the objects.
  // This step set the decorators "passOR" on the objects

  EL_CHECK("OverlapRemover",m_OR->removeOverlap(electrons, photons, muons, taus, jets));
 
  // Now, set the "passORGlob" flags which track if at least once the OR has been passed for the
  // different cases with the same container (e.g Electron Nominal container used for all jet systematics)

  if(electrons) {
    for(xAOD::Electron* el : *electrons) {
      int passORGlob = 0;
      m_decorator.get(el, ElecIntProps::passORGlob, passORGlob);
      m_decorator.set(el, ElecIntProps::passORGlob,
                      passORGlob | m_decorator.get(el, ElecIntProps::passOR)
                     );
    }
  }

  if(photons) {
    for(xAOD::Photon* ph : *photons) {
      int passORGlob = 0;
      m_decorator.get(ph, PhotIntProps::passORGlob, passORGlob);
      m_decorator.set(ph, PhotIntProps::passORGlob,
		      passORGlob | m_decorator.get(ph, PhotIntProps::passOR)
		      );
    }
  }

  if(muons) {
    for(xAOD::Muon* mu : *muons) {
      int passORGlob = 0;
      m_decorator.get(mu, MuonIntProps::passORGlob, passORGlob);
      m_decorator.set(mu, MuonIntProps::passORGlob,
                      passORGlob | m_decorator.get(mu, MuonIntProps::passOR)
                     );
    }
  }

  if(taus) {
    for(xAOD::TauJet* tau : *taus) {
      int passORGlob = 0;
      m_decorator.get(tau, TauIntProps::passORGlob, passORGlob);
      m_decorator.set(tau, TauIntProps::passORGlob,
                      passORGlob | m_decorator.get(tau, TauIntProps::passOR)
                     );
    }
  }

  if(jets) {
    for(xAOD::Jet* jet : *jets) {
      int passORGlob = 0;
      m_decorator.get(jet, JetIntProps::passORGlob, passORGlob);
      m_decorator.set(jet, JetIntProps::passORGlob,
                      passORGlob | m_decorator.get(jet, JetIntProps::passOR)
                     );
    }
  }

  // if we managed to reach this, everything went fine
  return EL::StatusCode::SUCCESS;
}

