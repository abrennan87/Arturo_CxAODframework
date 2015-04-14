#include "CxAODTools/OverlapRemoval.h"
#include "AssociationUtils/OverlapRemovalTool.h"
#include "CxAODTools/ReturnCheck.h"

OverlapRemoval::OverlapRemoval(ConfigStore & config) :
  m_config(config),
  m_applyOverlapRemoval(true),
  m_overlapRemovalTool(nullptr)
{
  //from config
  //------------
  m_config.getif<bool>("debug", m_debug);
  m_config.getif<bool>("applyOverlapRemoval", m_applyOverlapRemoval);
}
  
EL::StatusCode OverlapRemoval::initialize()
{
  
  if (!m_applyOverlapRemoval) {
    return EL::StatusCode::SUCCESS;
  }
  
  //initialize overlap removal tool
  //-------------------------------
  m_overlapRemovalTool = new OverlapRemovalTool("OverlapRemovalTool");
  m_overlapRemovalTool->msg().setLevel(MSG::INFO);
  if(m_debug) m_overlapRemovalTool->msg().setLevel(MSG::DEBUG);
  // Set name of decoration which tells the OR tool which objects to consider
  // if set to "false", the object automatically passes OR, i.e. the OROutputLabel is 0 (as in "do not remove this object").
  TOOL_CHECK("OverlapRemoval::initialize()", m_overlapRemovalTool->setProperty("InputLabel", "ORInputLabel"));
  // Set name of decoration the OR tool will add as decoration
  // if decoration is "false" the object should be removed, while if "true" the object should be kept.
  TOOL_CHECK("OverlapRemoval::initialize()", m_overlapRemovalTool->setProperty("OverlapLabel", "OROutputLabel"));
  // ElectronJetDRCone = 0.4 -> only jets removed as in run1 VHbb
  //TOOL_CHECK("OverlapRemoval::initialize()", m_overlapRemovalTool->setProperty("ElectronJetDRCone", 0.4));
  TOOL_CHECK("OverlapRemoval::initialize()", m_overlapRemovalTool->initialize());
  
  return EL::StatusCode::SUCCESS;
}

OverlapRemoval::~OverlapRemoval()
{
  delete m_overlapRemovalTool;
}


EL::StatusCode OverlapRemoval::removeOverlap(const xAOD::ElectronContainer* electrons,
                                             const xAOD::PhotonContainer* photons,
					     const xAOD::MuonContainer* muons,
					     const xAOD::TauJetContainer* taus,
                                             const xAOD::JetContainer* jets)
{

  // Set input flag for the OR tool (IntProp::ORInputLabel)  
  if (electrons) {
    for (const xAOD::Electron* elec : *electrons) {
      m_decorator.set(elec, ElecCharProps::ORInputLabel,
              m_decorator.get(elec, ElecIntProps::isVHLooseElectron));
    }
  }

  if (muons) {
    for (const xAOD::Muon* muon : *muons) {
      m_decorator.set(muon, MuonCharProps::ORInputLabel,
              m_decorator.get(muon, MuonIntProps::isVHLooseMuon));
    }
  }
  
  if (jets) {
    for (const xAOD::Jet* jet : *jets) {
      m_decorator.set(jet, JetCharProps::ORInputLabel,
              m_decorator.get(jet, JetIntProps::isVetoJet));
    }
  }
  
  if (taus) {
    for (const xAOD::TauJet* tau : *taus) {
      m_decorator.set(tau, TauCharProps::ORInputLabel,
              m_decorator.get(tau, TauIntProps::passTauSelector));
    }
  }
  
  if (photons) {
    for (const xAOD::Photon* photon : *photons) {
      m_decorator.set(photon, PhotCharProps::ORInputLabel,
              m_decorator.get(photon, PhotIntProps::isVBFLoosePhoton));
    }
  }

  // taus and photons can be nulptrs - do not apply photon OR, but use method below!
  // electrons, muons and jets need to be valid pointers
  if (m_applyOverlapRemoval) {
    if (!m_overlapRemovalTool) {
      Error("OverlapRemoval::removeOverlap()", "OverlapRemovalTool not initialized!");
      return EL::StatusCode::FAILURE;
    }
    EL_CHECK("OverlapRemoval::removeOverlap()",m_overlapRemovalTool->removeOverlaps(electrons, muons, jets, taus, nullptr));
  }
  
  // set passOR flags
  if (electrons) {
    for (const xAOD::Electron* elec : *electrons) {
      bool passOR = m_decorator.get(elec, ElecCharProps::ORInputLabel);
      if (m_applyOverlapRemoval)
        passOR &= !m_decorator.get(elec, ElecCharProps::OROutputLabel);
      m_decorator.set(elec, ElecIntProps::passOR, passOR);
    }
  }

  if (muons) {
    for (const xAOD::Muon* muon : *muons) {
      bool passOR = m_decorator.get(muon, MuonCharProps::ORInputLabel);
      if (m_applyOverlapRemoval)
        passOR &= !m_decorator.get(muon, MuonCharProps::OROutputLabel);
      m_decorator.set(muon, MuonIntProps::passOR, passOR);
    }
  }
 
  if (jets) {
    for (const xAOD::Jet* jet : *jets) {
      bool passOR = m_decorator.get(jet, JetCharProps::ORInputLabel);
      if (m_applyOverlapRemoval)
        passOR &= !m_decorator.get(jet, JetCharProps::OROutputLabel);
      m_decorator.set(jet, JetIntProps::passOR, passOR);
    }
  }
 
  if (taus){
    for (const xAOD::TauJet* tau : *taus) {
      bool passOR = m_decorator.get(tau, TauCharProps::ORInputLabel);
      if (m_applyOverlapRemoval)
        passOR &= !m_decorator.get(tau, TauCharProps::OROutputLabel);
      m_decorator.set(tau, TauIntProps::passOR, passOR);
    }
  } 

  // TODO should VBFbba be moved to different package? 
  // photon removal
  if(photons) {
    for(const xAOD::Photon* phot : *photons) {
      m_decorator.set(phot,PhotIntProps::passOR, false);
      //ignore particles that didnt pass the preselection
      if (!m_decorator.get(phot, PhotIntProps::isVBFLoosePhoton)) {
        continue;
      }
      
      if (!m_applyOverlapRemoval) {
        m_decorator.set(phot, PhotIntProps::passOR, true);
        continue;
      }

      bool photPassOR = true;
      if(jets){
	for (const xAOD::Jet * jet : *jets) {
          // ignore particles that didn't pass pre-selection 
          if (!m_decorator.get(jet, JetIntProps::isVetoJet)) {
            continue;
          }
	  // ignore particles that didn't pass previous OR 
          if (!m_decorator.get(jet, JetIntProps::passOR)) {
            continue;
          }
	  //do the OR
	  if (0.2 < phot->p4().DeltaR(jet->p4()) && phot->p4().DeltaR(jet->p4()) < 0.4) {
	    photPassOR &= false;
	  }//if
	}//for
      }//jets

      m_decorator.set(phot, PhotIntProps::passOR, photPassOR);

    }//for(photons)
  }//if(photons)


  return EL::StatusCode::SUCCESS;
}

