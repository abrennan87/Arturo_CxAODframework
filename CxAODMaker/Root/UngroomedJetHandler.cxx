#include <iostream>
//#include "xAODRootAccess/TStore.h"

// jet specific includes
#include "xAODJet/JetContainer.h"
#include "xAODJet/JetAuxContainer.h"
#include "CxAODMaker/UngroomedJetHandler.h"
#include "xAODHelpers/Helpers.h"
#include "JetSubStructureMomentTools/EnergyCorrelatorRatiosTool.h"

// declare static members
FatJetDecorator UngroomedJetHandler::m_decorator;

UngroomedJetHandler::UngroomedJetHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
					 EventInfoHandler & eventInfoHandler) : 
  ObjectHandler(name, config, event, eventInfoHandler) 
{
  m_config.getif<bool>("applyJetSubStructure", doRebuild);

  m_selectFcns.push_back(&passUngroomedJet);
}


UngroomedJetHandler::~UngroomedJetHandler() 
{
  
}

EL::StatusCode UngroomedJetHandler::initializeTools()
{
  
  // register ISystematicsTools
  //---------------------------
  m_sysToolList.clear();
  
  m_EnergyCorrelatorRatiosTool = new EnergyCorrelatorRatiosTool("ecfratios");
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode UngroomedJetHandler::decorate(xAOD::Jet * jet) 
{
  // jet vertex fraction
  std::vector<float> jvf;
  jet->getAttribute("JVF", jvf);
  
  if( jvf.size() > 0) {
    m_decorator.set(jet, FatJetFloatProps::JVF,jvf[0]);
  } else  {
    m_decorator.set(jet, FatJetFloatProps::JVF,0);
  }
  
  // substructure moments: n-subjettiness
  float tau1(-1.), tau2(-1.), tau3(-1.);
  float tau21(-1.), tau32(-1.);
  
  jet->getAttribute("Tau1", tau1);
  jet->getAttribute("Tau2", tau2);
  jet->getAttribute("Tau3", tau3);
  
  if (tau2 > 0.) tau21 = tau2 / tau1;
  if (tau3 > 0.) tau32 = tau3 / tau2;
  
  m_decorator.set(jet, FatJetFloatProps::Tau21, tau21);
  m_decorator.set(jet, FatJetFloatProps::Tau32, tau32);
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode UngroomedJetHandler::calibrateCopies(xAOD::JetContainer * particles, const CP::SystematicSet & sysSet) 
{
  
  // loop over the particles in the container
  for (xAOD::Jet * jet : *particles) {
    //this ensures that the DynAux container has the same number of entries as the original one
    setP4( jet , jet );
    
    if(doRebuild){
      
      // decorate jet
      if ( decorate( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      /*       
      // jet vertex fraction from xAOD
      m_decorator.copy(jet, jet, FatJetFloatProps::JVF);
      
      // substructure moments: n-subjettiness
      m_decorator.copy(jet, jet, FatJetFloatProps::Tau21);
      m_decorator.copy(jet, jet, FatJetFloatProps::Tau32);
      */    
      
      // Start to add Sub-Structure variables  ==== March 22th 2015 ====
      // Moment 	xAOD Jet attribute names 	Utils constructor 	Description
      // N-subjettiness 	Tau1, Tau2, Tau3, Tau1_wta, Tau2_wta, Tau3_wta 	Nsubjettiness(n, axes, measure)
      // if ( N_subjettiness( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // N-subjettiness ratios 	Tau21, Tau32, Tau21_wta, Tau32_wta
      // if ( NSubjettinessRatios( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // kT splitting scale 	Split12, Split23, Split34 	KtSplittingScale(n)
      // if ( kT_splitting_scale( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // zCut 	ZCut12, ZCut23, ZCut34 	ZCut(n)
      // if ( zCut( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Dipolarity 	Dip12, Dip13, Dip23, DipExcl12 	Dipolarity(n1, n2, isExclusive, radius_subjet)
      // if ( Dipolarity( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Angularity 	Angularity 	Nsubjettiness(n, axes, measure)
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // kT Delta R 	KtDR 	KtDeltaR(radius)
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // kT Mass drop 	Mu12 	KtMassDrop()
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Planar flow 	PlanarFlow 	PlanarFlow()
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Energy correlations 	ECF1, ECF2, ECF3, ECF1_Beta2, ECF2_Beta2, ECF3_Beta2 	EnergyCorrelator(n, beta, EnergyCorrelator::pt_R)
      m_EnergyCorrelatorRatiosTool->modifyJet(*jet);
      
      // ECF ratios 	C1, C2, D2, C1_Beta2, C2_Beta2, D2_Beta2
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Thrust 	ThrustMin, ThrustMaj 	Thrust()
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // FoxWolfram 	FoxWolfram0, FoxWolfram1, FoxWolfram2, FoxWolfram3, FoxWolfram4 	FoxWolfram()
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Sphericity 	Sphericity, Aplanarity 	SphericityTensor()
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Jet charge 	Charge 	Charge(k)
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Pull 	PullMag, PullPhi, Pull_C00_, Pull_C01_, Pull_C10_, Pull_C10_ 	Pull(useEtaInsteadOfY)
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Shower deconstruction 	ShowerDeconstructionW, ShowerDeconstructionTop 	ShowerDeconstruction(signal_model)
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Q-jets volatility 	Volatility 	Volatility(N_iter, zcut, dcut, exp_min, exp_max, rigidity, truncation)
      // if ( ( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // End to add Sub-Structure variables  ==== March 22th 2015 ====    
      
    } // End inclusion of Substructure variables into the Ungroomed jets
    
    
  }
  
  return EL::StatusCode::SUCCESS;
  
}


bool UngroomedJetHandler::checkPassSel(xAOD::Jet * part) 
{
  
  // TODO implement check like muon
  return true;
  
}

bool UngroomedJetHandler::passUngroomedJet(xAOD::Jet* jet)
{
  bool passFatCut=false;
  if(jet->pt()>200000){
    if(fabs(jet->eta()) <2.0){
      passFatCut=true;
    }
  }
  m_decorator.set(jet, FatJetIntProps::isFatJet, passFatCut);
  
  return passFatCut;
}

EL::StatusCode UngroomedJetHandler::setVariables(xAOD::Jet* inJet, xAOD::Jet* outJet, bool isKinVar, bool isWeightVar)
{
  // set four momentum
  outJet->setJetP4(inJet->jetP4());
  
  m_decorator.copy(inJet, outJet, FatJetIntProps::isFatJet);
  
  if(doRebuild){
    
    // jet vertex fraction from xAOD
    m_decorator.copy(inJet, outJet, FatJetFloatProps::JVF);
    
    // substructure moments: n-subjettiness
    m_decorator.copy(inJet, outJet, FatJetFloatProps::Tau21);
    m_decorator.copy(inJet, outJet, FatJetFloatProps::Tau32);
    m_decorator.copy(inJet, outJet, FatJetFloatProps::D2);      
    m_decorator.copy(inJet, outJet, FatJetFloatProps::C1);      
    m_decorator.copy(inJet, outJet, FatJetFloatProps::C2);      
    /* m_decorator.copy(inJet, outJet, FatJetFloatProps::D2_Beta2);      
       m_decorator.copy(inJet, outJet, FatJetFloatProps::C1_Beta2);
       m_decorator.copy(inJet, outJet, FatJetFloatProps::C2_Beta2);*/
  }
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode UngroomedJetHandler::fillOutputContainer() 
{
  
  return fillOutputContainerCheck(&checkPassSel);
  
}


EL::StatusCode UngroomedJetHandler::clearEvent() 
{
  if (ObjectHandler::clearEvent() != EL::StatusCode::SUCCESS) {
    Error("EL::StatusCode UngroomedJetHandler::clearEvent()", "Failed to clear event in object handler!");
    return EL::StatusCode::FAILURE;
  }
  return EL::StatusCode::SUCCESS;
  
}
