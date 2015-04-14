#include <iostream>
//#include "xAODRootAccess/TStore.h"

// jet specific includes
#include "xAODJet/JetContainer.h"
#include "xAODJet/JetAuxContainer.h"
#include "CxAODMaker/GroomedJetHandler.h"
#include "xAODHelpers/Helpers.h"
#include "JetSubStructureMomentTools/EnergyCorrelatorRatiosTool.h"

// declare static members
FatJetDecorator GroomedJetHandler::m_decorator;

GroomedJetHandler::GroomedJetHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
				     EventInfoHandler & eventInfoHandler) : 
  ObjectHandler(name, config, event, eventInfoHandler) 
{  
  m_config.getif<bool>("applyJetSubStructure", doRebuild);
  
  m_selectFcns.push_back(&passGroomedJet);
}


GroomedJetHandler::~GroomedJetHandler() 
{
  
}


EL::StatusCode GroomedJetHandler::initializeTools()
{
  
  // register ISystematicsTools
  //---------------------------
  m_sysToolList.clear();
  
  m_EnergyCorrelatorRatiosTool = new EnergyCorrelatorRatiosTool("ecfratios");
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode GroomedJetHandler::decorate(xAOD::Jet * jet) 
{
  // jet vertex fraction
  std::vector<float> jvf;
  jet->getAttribute("JVF", jvf);
  
  if( jvf.size() > 0) {
    m_decorator.set(jet, FatJetFloatProps::JVF,jvf[0]);
  } else  {
    m_decorator.set(jet, FatJetFloatProps::JVF,0);
  }
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode GroomedJetHandler::calibrateCopies(xAOD::JetContainer * particles, const CP::SystematicSet & sysSet) 
{
  
  // loop over the particles in the container
  for (xAOD::Jet * jet : *particles) {
    //this ensures that the DynAux container has the same number of entries as the original one
    setP4( jet , jet );
    
    
    if(doRebuild){
      
      // decorate jet
      if ( decorate( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // Start to add Sub-Structure variables  ==== March 22th 2015 ====
      // Moment 	xAOD Jet attribute names 	Utils constructor 	Description
      // N-subjettiness 	Tau1, Tau2, Tau3, Tau1_wta, Tau2_wta, Tau3_wta 	Nsubjettiness(n, axes, measure)
      //if ( N_subjettiness( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // N-subjettiness ratios 	Tau21, Tau32, Tau21_wta, Tau32_wta
      if ( NSubjettinessRatios( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
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
      //if ( EnergyCorrelations( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
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
      
    } // End inclusion of Substructure variables into the Groomed jets    
    
  }
  
  return EL::StatusCode::SUCCESS;
  
}


bool GroomedJetHandler::checkPassSel(xAOD::Jet * part) 
{
  
  // TODO implement check like muon
  return true;
  
}


bool GroomedJetHandler::passGroomedJet(xAOD::Jet* jet)
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


EL::StatusCode GroomedJetHandler::setVariables(xAOD::Jet* inJet, xAOD::Jet* outJet, bool isKinVar, bool isWeightVar)
{
  // set four momentum
  TLorentzVector trimmedJet = helpers.jet_trimming(inJet,0.2,0.05,fastjet::antikt_algorithm);
  xAOD::JetFourMom_t new4Vector(trimmedJet.Pt(),trimmedJet.Eta(),trimmedJet.Phi(),trimmedJet.M());
  
  outJet->setJetP4(new4Vector);
  
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
    /* 
       m_decorator.copy(inJet, outJet, FatJetFloatProps::Tau21_wta);
       m_decorator.copy(inJet, outJet, FatJetFloatProps::Tau32_wta);
       m_decorator.copy(inJet, outJet, FatJetFloatProps::D2_Beta2);      
       m_decorator.copy(inJet, outJet, FatJetFloatProps::C1_Beta2);
       m_decorator.copy(inJet, outJet, FatJetFloatProps::C2_Beta2);*/
  }  
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode GroomedJetHandler::fillOutputContainer() 
{
  
  return fillOutputContainerCheck(&checkPassSel,"TrimmedPtFrac5SmallR20");
  
}


EL::StatusCode GroomedJetHandler::clearEvent() 
{
  if (ObjectHandler::clearEvent() != EL::StatusCode::SUCCESS) {
    Error("EL::StatusCode GroomedJetHandler::clearEvent()", "Failed to clear event in object handler!");
    return EL::StatusCode::FAILURE;
  }
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode GroomedJetHandler::NSubjettinessRatios(xAOD::Jet * jet) {
  // Regular
  float tau1 = jet->getAttribute<float>("Tau1");
  float tau2 = jet->getAttribute<float>("Tau2");
  float tau3 = jet->getAttribute<float>("Tau3");
  
  if(fabs(tau1) > 1e-8) // Prevent div-0
    m_decorator.set(jet, FatJetFloatProps::Tau21, tau2/tau1);
  else
    m_decorator.set(jet, FatJetFloatProps::Tau21, -999);
  if(fabs(tau2) > 1e-8) // Prevent div-0
    m_decorator.set(jet, FatJetFloatProps::Tau32, tau3/tau2);
  else
    m_decorator.set(jet, FatJetFloatProps::Tau32, -999);
  
  if(0/*Turn on when variables are inside the input xAOD/DxAOD*/) {
    float tau1_wta = jet->getAttribute<float>("Tau1_wta");
    float tau2_wta = jet->getAttribute<float>("Tau2_wta");
    float tau3_wta = jet->getAttribute<float>("Tau3_wta");
    
    // WTA
    if(fabs(tau1_wta) > 1e-8) // Prevent div-0
      m_decorator.set(jet, FatJetFloatProps::Tau21_wta, tau2_wta/tau1_wta);
    else
      m_decorator.set(jet, FatJetFloatProps::Tau21_wta, -999);
    if(fabs(tau2_wta) > 1e-8) // Prevent div-0
      m_decorator.set(jet, FatJetFloatProps::Tau32_wta, tau3_wta/tau2_wta);
    else
      m_decorator.set(jet, FatJetFloatProps::Tau32_wta, -999.0);
  }
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode GroomedJetHandler::EnergyCorrelations(xAOD::Jet * jet) {
  
  float ecf1 = jet->getAttribute<float>("ECF1");
  float ecf2 = jet->getAttribute<float>("ECF2");
  float ecf3 = jet->getAttribute<float>("ECF3");
  
  // D2
  if(fabs(ecf2) > 1e-8) // Prevent div-0
    m_decorator.set(jet, FatJetFloatProps::D2, ecf3 * pow(ecf1, 3.0) / pow(ecf2, 3.0));
  else
    m_decorator.set(jet, FatJetFloatProps::D2, 0);
  
  // C1
  if(fabs(ecf1) > 1e-8) // Prevent div-0
    m_decorator.set(jet, FatJetFloatProps::C1, ecf2 / pow(ecf1, 2.0));
  else
    m_decorator.set(jet, FatJetFloatProps::C1, -999.0);
  
  // C2
  if(fabs(ecf2) > 1e-8) // Prevent div-0
    m_decorator.set(jet, FatJetFloatProps::C2, ecf3 * ecf1 / pow(ecf2, 2.0));
  else
    m_decorator.set(jet, FatJetFloatProps::C2, -999.0);
  
  if(0/*m_includeBeta2*/) { //Keep an eye on this. Is thise not necessary any more? (March 22th, 2015) /*Turn on when variables are inside the input xAOD/DxAOD*/
    
    float ecf1_beta2 = jet->getAttribute<float>("ECF1_Beta2");
    float ecf2_beta2 = jet->getAttribute<float>("ECF2_Beta2");
    float ecf3_beta2 = jet->getAttribute<float>("ECF3_Beta2");
    
    // D2
    if(fabs(ecf2_beta2) > 1e-8) // Prevent div-0
      m_decorator.set(jet, FatJetFloatProps::D2_Beta2, ecf3_beta2 * pow(ecf1_beta2, 3.0) / pow(ecf2_beta2, 3.0));
    else
      m_decorator.set(jet, FatJetFloatProps::D2_Beta2, -999.0);
    
    // C1
    if(fabs(ecf1_beta2) > 1e-8) // Prevent div-0
      m_decorator.set(jet, FatJetFloatProps::C1_Beta2, ecf2_beta2 / pow(ecf1_beta2, 2.0));
    else
      m_decorator.set(jet, FatJetFloatProps::C1_Beta2, -999.0);
    
    // C2
    if(fabs(ecf2_beta2) > 1e-8) // Prevent div-0
      m_decorator.set(jet, FatJetFloatProps::C2_Beta2, ecf3_beta2 * ecf1_beta2 / pow(ecf2_beta2, 2.0));
    else
      m_decorator.set(jet, FatJetFloatProps::C2_Beta2, -999.0);
  }
  
  return EL::StatusCode::SUCCESS;
  
}
