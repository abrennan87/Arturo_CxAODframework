#include "iostream"

#include "CxAODMaker/TrimmedJetHandler.h"
#include "JetSubStructureMomentTools/EnergyCorrelatorRatiosTool.h"

// declare static members
FatJetDecorator TrimmedJetHandler::m_decorator;


TrimmedJetHandler::TrimmedJetHandler(ConfigStore *config, xAOD::TEvent *event, int isMC) :
  m_event(event),
  m_isMC(isMC)
{
  //TODO: move this in a initialize() method
  debug=false;
  
  // set container name
  m_config = config; //This is usually defined in ObjectHandler so I add here by hand
  m_containerName = m_config->get<std::string>("trimmedJetContainer"); //This is usually defined in ObjectHandler so I add here by hand
  
  m_EnergyCorrelatorRatiosTool = new EnergyCorrelatorRatiosTool("ecfratios");

}


TrimmedJetHandler::~TrimmedJetHandler() {
  
}


EL::StatusCode TrimmedJetHandler::setTrimmedJets() {
  
  m_inputTrimmedJetCont = "AntiKt10LCTopoJets";
  m_inputSmallJetCont   = "AntiKt4LCTopoJets";
  m_outTrimmedJetCont   = "AntiKt10LCTopoTrimmedPtFrac5SmallR20Jets";
  
  akt10jets = 0;
  akt4jets  = 0;
  
  if ( !m_event->retrieve( akt10jets, m_inputTrimmedJetCont ).isSuccess() ){
    Error("seTrimmedJets()  ", "Failed to retrieve %s container. Exiting.", "AntiKt10LCTopoJets" );
    return EL::StatusCode::FAILURE;
  }
  
  if ( !m_event->retrieve( akt4jets, m_inputSmallJetCont ).isSuccess() ){
    Error("setTrimmedJets()  ", "Failed to retrieve %s container. Exiting.",  "AntiKt4LCTopoJets"  );
    return EL::StatusCode::FAILURE;
  }  
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode TrimmedJetHandler::decorate(xAOD::Jet * jet) {
  
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


EL::StatusCode TrimmedJetHandler::getTrimmedJets() {
    
  m_trimmedjetContainer = new xAOD::JetContainer();
  m_trimmedjetContainerAux = new xAOD::JetAuxContainer();
  m_trimmedjetContainer->setStore( m_trimmedjetContainerAux ); //< Connect the two
  
  xAODHelpers::Helpers helpers;


  if ( !m_event->retrieve( akt10jets, "AntiKt10LCTopoJets" ).isSuccess() ){
    Error("getTrimmedJets()  ", "Failed to retrieve %s container. Exiting.", "AntiKt10LCTopoJets" );
    return EL::StatusCode::FAILURE;
  }
  
  if ( !m_event->retrieve( akt4jets, "AntiKt4LCTopoJets" ).isSuccess() ){
    Error("getTrimmedJets()  ", "Failed to retrieve %s container. Exiting.",  "AntiKt4LCTopoJets"  );
    return EL::StatusCode::FAILURE;
  }  
  
  std::pair< xAOD::JetContainer*, xAOD::ShallowAuxContainer* > jets_shallowCopy = xAOD::shallowCopyContainer( *akt10jets );
  
  // Trimming using kt=0.2 subjets with fcut=0.05
  std::vector<TLorentzVector> trimmedJets = helpers.jet_trimming(akt10jets,0.2,0.05,fastjet::antikt_algorithm);
  
  // Reclutering using antikt=1.0 with fcut=0.05
  std::vector<TLorentzVector> reclusteredTrimmedJets = helpers.jet_reclustering(akt4jets);
  
  // iterate over the shallow copy
  xAOD::JetContainer::iterator jetSC_itr = (jets_shallowCopy.first)->begin();
  xAOD::JetContainer::iterator jetSC_end = (jets_shallowCopy.first)->end();
  
  int i = -1;
  for( ; jetSC_itr != jetSC_end; ++jetSC_itr ) {
    i++;
    
    TLorentzVector new_jet = trimmedJets.at(i);
    
    xAOD::JetFourMom_t new4Vector(new_jet.Pt(),new_jet.Eta(),new_jet.Phi(),new_jet.M());
    
    (*jetSC_itr)->setJetP4(new4Vector);
    
    xAOD::Jet* trim_jet = new xAOD::Jet();
    trim_jet->makePrivateStore( **jetSC_itr );
    
    
    bool doRebuild = false;
    m_config->getif<bool>("applyJetSubStructure", doRebuild);
    
    if(doRebuild){
      
      // decorate jet
      if ( decorate( trim_jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      
      // jet vertex fraction from xAOD
      m_decorator.copy(trim_jet, trim_jet, FatJetFloatProps::JVF);
      // substructure moments: n-subjettiness
      m_decorator.copy(trim_jet, trim_jet, FatJetFloatProps::Tau21);
      m_decorator.copy(trim_jet, trim_jet, FatJetFloatProps::Tau32);
      //
      
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
      //JetSubStructureMomentTools::EnergyCorrelatorRatiosTool modifyJet( trim_jet );
      //if ( EnergyCorrelations( trim_jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
      m_EnergyCorrelatorRatiosTool->modifyJet(*trim_jet);
      
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
      
    } // End inclusion of Substructure variables into the trimmed jets
    
    
    m_trimmedjetContainer->push_back( trim_jet );
    
  }
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode TrimmedJetHandler::NSubjettinessRatios(xAOD::Jet * jet) {
  
  // Regular
  float tau1 = jet->getAttribute<float>("Tau1");
  float tau2 = jet->getAttribute<float>("Tau2");
  float tau3 = jet->getAttribute<float>("Tau3");
  
  if(fabs(tau1) > 1e-8) // Prevent div-0
    jet->setAttribute("Tau21", tau2/tau1);
  else
    jet->setAttribute("Tau21", -999);
  if(fabs(tau2) > 1e-8) // Prevent div-0
    jet->setAttribute("Tau32", tau3/tau2);
  else
    jet->setAttribute("Tau32", -999);
  
  float tau1_wta = jet->getAttribute<float>("Tau1_wta");
  float tau2_wta = jet->getAttribute<float>("Tau2_wta");
  float tau3_wta = jet->getAttribute<float>("Tau3_wta");
  
  // WTA
  if(fabs(tau1_wta) > 1e-8) // Prevent div-0
    jet->setAttribute("Tau21_wta", tau2_wta/tau1_wta);
  else
    jet->setAttribute("Tau21_wta", -999);
  if(fabs(tau2_wta) > 1e-8) // Prevent div-0
    jet->setAttribute("Tau32_wta", tau3_wta/tau2_wta);
  else
    jet->setAttribute("Tau32_wta", -999);
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode TrimmedJetHandler::EnergyCorrelations(xAOD::Jet * jet) {
  
  float ecf1 = jet->getAttribute<float>("ECF1");
  float ecf2 = jet->getAttribute<float>("ECF2");
  float ecf3 = jet->getAttribute<float>("ECF3");
  
  // D2
  if(fabs(ecf2) > 1e-8) // Prevent div-0
    jet->setAttribute("D2", ecf3 * pow(ecf1, 3.0) / pow(ecf2, 3.0));
  else
    jet->setAttribute("D2", -999.0);
  
  // C1
  if(fabs(ecf1) > 1e-8) // Prevent div-0
    jet->setAttribute("C1", ecf2 / pow(ecf1, 2.0));
  else
    jet->setAttribute("C1", -999.0);
  
  // C2
  if(fabs(ecf2) > 1e-8) // Prevent div-0
    jet->setAttribute("C2", ecf3 * ecf1 / pow(ecf2, 2.0));
  else
    jet->setAttribute("C2", -999.0);
  
  if(0/*m_includeBeta2*/) { //Keep an eye on this. Is thise not necessary any more? (March 22th, 2015)
    float ecf1_beta2 = jet->getAttribute<float>("ECF1_Beta2");
    float ecf2_beta2 = jet->getAttribute<float>("ECF2_Beta2");
    float ecf3_beta2 = jet->getAttribute<float>("ECF3_Beta2");
    
    // D2
    if(fabs(ecf2_beta2) > 1e-8) // Prevent div-0
      jet->setAttribute("D2_Beta2", ecf3_beta2 * pow(ecf1_beta2, 3.0) / pow(ecf2_beta2, 3.0));
    else
      jet->setAttribute("D2_Beta2", -999.0);
    
    // C1
    if(fabs(ecf1_beta2) > 1e-8) // Prevent div-0
      jet->setAttribute("C1_Beta2", ecf2_beta2 / pow(ecf1_beta2, 2.0));
    else
      jet->setAttribute("C1_Beta2", -999.0);
    
    // C2
    if(fabs(ecf2_beta2) > 1e-8) // Prevent div-0
      jet->setAttribute("C2_Beta2", ecf3_beta2 * ecf1_beta2 / pow(ecf2_beta2, 2.0));
    else
      jet->setAttribute("C2_Beta2", -999.0);
  }
  
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode TrimmedJetHandler::fillOutputContainer() {
  //TODO ADD MORE SOPHISTICATED OUTPUT FILLING HERE 
  
  if (!m_event->record(m_trimmedjetContainer, "AntiKt10LCTopoTrimmedPtFrac5SmallR20Jets")) {
    return EL::StatusCode::FAILURE;
  }
  
  if (!m_event->record(m_trimmedjetContainerAux, "AntiKt10LCTopoTrimmedPtFrac5SmallR20JetsAux.")) {
    return EL::StatusCode::FAILURE;
  }
  
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode TrimmedJetHandler::clearEvent() {
  
  m_trimmedjetContainer->setConstStore(nullptr);
  m_trimmedjetContainer = nullptr;
  
  return EL::StatusCode::SUCCESS;
  
}
