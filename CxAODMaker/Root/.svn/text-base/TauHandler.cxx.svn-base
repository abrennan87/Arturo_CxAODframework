#include <iostream>
//tau includes
#include "xAODTau/TauJetContainer.h"
#include "xAODTau/TauJetAuxContainer.h"
#include "xAODTau/TauJet.h"
#include "xAODTruth/TruthParticleContainer.h"
#include "CxAODMaker/TauHandler.h"
#include "TauAnalysisTools/Enums.h"
#include "TauAnalysisTools/TauSelectionTool.h"
#include "TauAnalysisTools/TauSmearingTool.h"
#include "TauAnalysisTools/TauEfficiencyCorrectionsTool.h"
#include "PATCore/IAsgSelectionTool.h"
#include <iostream>
#include <vector>


TauDecorator TauHandler::m_decorator;
TauHandler::TauHandler(const std::string& name, ConfigStore & config, xAOD::TEvent *event,
                         EventInfoHandler & eventInfoHandler) :
  ObjectHandler(name, config, event, eventInfoHandler),
  m_tauSmearingTool(0),
  m_tauSelectionTool(0),
  m_tauEfficiencyCorrections(0),
  m_tauEfficiencyCorrections_eveto(0),
  m_truthhandler(0), 
  m_SearchedTrueTaus(false)
{
  m_selectFcns.push_back(&LooseTau);
}

TauHandler::~TauHandler() {

  //delete tool:
  delete m_tauSmearingTool;
  delete m_tauSelectionTool;
  delete m_tauEfficiencyCorrections;
  delete m_tauEfficiencyCorrections_eveto;

}


EL::StatusCode TauHandler::initializeTools()
{

  // Init Calibrationtool
  // _____________________________________________

  m_tauSmearingTool = new TauAnalysisTools ::TauSmearingTool("TauSmearTool");
  m_tauSmearingTool->msg().setLevel( m_msgLevel );
  TOOL_CHECK("TauHandler::initializeTools()",m_tauSmearingTool->initialize());

  // Init TauSelector
  // _____________________________________________
  m_tauSelectionTool = new TauAnalysisTools::TauSelectionTool("TauSelectTool"); 
  m_tauSelectionTool->msg().setLevel( m_msgLevel );
  m_tauSelectionTool->setRecommendedProperties();
  // //Manual set of basic tau cuts
  // std::vector<double> vAbsEtaRegion = {0, 1.37, 1.52, 2.5};
  //m_tauSelectionTool->setProperty("AbsEtaRegion", vAbsEtaRegion);
      // define pt threshold, note that pt has to be given in GeV
  // m_tauSelectionTool->setProperty("PtMin", 20.);
      // // define absolute charge requirement, in general should be set to 1
  //m_tauSelectionTool->setProperty("AbsCharge", 1.);
      // // define number of tracks required, most analysis use 1 and 3 track taus
  //std::vector<size_t> vNTracks = {1,3};
  //m_tauSelectionTool->setProperty( "NTracks", vNTracks);
      // // requiring tau to pass a jet BDT working point
  //m_tauSelectionTool->setProperty( "JetIDWP", int(TauAnalysisTools::JETIDBDTMEDIUM));
      // Ele BDT
   //m_tauSelectionTool->setProperty( "EleBDTWP", int(TauAnalysisTools::ELEIDBDTLOOSE));
      //  and finally define cuts actually to be executed:
      // Do not put the e-veto in the selection tool. Ask for it later. 
  TOOL_CHECK("TauHandler::initializeTools()",m_tauSelectionTool->setProperty( "SelectionCuts", int(
  					       TauAnalysisTools::CutPt |
  					       TauAnalysisTools::CutAbsEta |
  					       TauAnalysisTools::CutAbsCharge |
  					       TauAnalysisTools::CutNTrack |
  					       TauAnalysisTools::CutJetIDWP // | 
  					       // TauAnalysisTools::CutEleBDTWP
								   )));
  
  TOOL_CHECK("TauHandler::initializeTools()",m_tauSelectionTool->initialize());

  // Init ID Correction
  // _____________________________________________
  m_tauEfficiencyCorrections = new TauAnalysisTools::TauEfficiencyCorrectionsTool("TauEfficiencyTool",m_tauSelectionTool);
  m_tauEfficiencyCorrections->msg().setLevel( m_msgLevel );
  TOOL_CHECK("TauHandler::initializeTools()",m_tauEfficiencyCorrections->setProperty("EfficiencyCorrectionType", (int) TauAnalysisTools::SFJetID));
  TOOL_CHECK("TauHandler::initializeTools()",m_tauEfficiencyCorrections->setProperty("IDLevel", int(TauAnalysisTools::JETIDBDTMEDIUM) )); 
  TOOL_CHECK("TauHandler::initializeTools()",m_tauEfficiencyCorrections->initialize()); 
  //eveto
  //-----
  m_tauEfficiencyCorrections_eveto = new TauAnalysisTools::TauEfficiencyCorrectionsTool("TauEfficiencyTool_EVETO",m_tauSelectionTool);
  m_tauEfficiencyCorrections_eveto->msg().setLevel( m_msgLevel );
  TOOL_CHECK("TauHandler::initializeTools()",m_tauEfficiencyCorrections_eveto->setProperty("EfficiencyCorrectionType", (int) TauAnalysisTools::SFEleID)); 
  TOOL_CHECK("TauHandler::initializeTools()",m_tauEfficiencyCorrections_eveto->setProperty("EVLevel", int(TauAnalysisTools::ELEIDBDTLOOSE) )); 
  TOOL_CHECK("TauHandler::initializeTools()",m_tauEfficiencyCorrections_eveto->initialize()); 
  
  // register ISystematicsTools
  // _____________________________________________
  m_sysToolList.clear();
  m_sysToolList.push_back(m_tauEfficiencyCorrections);
  m_sysToolList.push_back(m_tauEfficiencyCorrections_eveto);
  m_sysToolList.push_back(m_tauSmearingTool);

  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode TauHandler::setVariables(xAOD::TauJet * inTau, xAOD::TauJet * outTau, bool isKinVar, bool isWeightVar) 
{

 
  /*
    nTracks
    nConversionTracks

   */

  // set four momentum
  if (!isWeightVar ){
    setP4( inTau , outTau );
    m_decorator.copy(inTau, outTau, TauIntProps::passLooseTau);
    m_decorator.copy(inTau, outTau, TauIntProps::passTauSelector);
    //m_decorator.copy(inTau, outTau, TauIntProps::passPreSel);
    m_decorator.copy(inTau, outTau, TauIntProps::TruthMatch);
    m_decorator.copy(inTau, outTau, TauIntProps::LeptonTruthMatch);
    outTau->setCharge(inTau->charge());

    // Below are properties which remain unchanged by any variation
    if(!isKinVar){
      m_decorator.copy(inTau, outTau, TauIntProps::nTracks);
      m_decorator.copy(inTau, outTau, TauIntProps::isBDTLoose);
      m_decorator.copy(inTau, outTau, TauIntProps::isBDTMedium);
      m_decorator.copy(inTau, outTau, TauIntProps::isBDTTight);
      m_decorator.copy(inTau, outTau, TauIntProps::passEvetoLoose);
      m_decorator.copy(inTau, outTau, TauIntProps::passEvetoMedium);
      m_decorator.copy(inTau, outTau, TauIntProps::passEvetoTight);
      m_decorator.copy(inTau, outTau, TauFloatProps::charge);
      m_decorator.copy(inTau, outTau, TauFloatProps::BDTScore);

      m_decorator.copy(inTau, outTau, TauFloatProps::EleBDTScore);
      m_decorator.copy(inTau, outTau, TauFloatProps::TrackEta);
    }
  }

  int isMC = m_eventInfoHandler.get_isMC();
  if (isMC) {
    m_decorator.copy(inTau, outTau, TauFloatProps::effSFeveto);
    m_decorator.copy(inTau, outTau, TauFloatProps::effSF);
  }

  return EL::StatusCode::SUCCESS;

}


/* Only oreselected & OLR taus survive */
bool TauHandler::checkPassSel(xAOD::TauJet * tau){
 
  int res = 0;
  
  m_decorator.get(tau, TauIntProps::passORGlob, res);
 
  return res;

}





EL::StatusCode TauHandler::fillOutputContainer(){
  return fillOutputContainerCheck(&checkPassSel);	
}


EL::StatusCode TauHandler::decorate(xAOD::TauJet * tau) 
{

  /* Set tau variables - derived ones*/

  m_decorator.set(tau, TauIntProps::nTracks, tau->nTracks());

  float leadtrketa=-100;
  if (tau->nTracks() > 0){ 
    leadtrketa = tau->track(0)->eta();
  }
  m_decorator.set(tau, TauFloatProps::TrackEta,leadtrketa );

  bool isloose=tau->isTau(xAOD::TauJetParameters::JetBDTSigLoose);
  m_decorator.set(tau, TauIntProps::isBDTLoose, isloose);
  bool ismed=tau->isTau(xAOD::TauJetParameters::JetBDTSigMedium);
  m_decorator.set(tau, TauIntProps::isBDTMedium, ismed);
  bool istight=tau->isTau(xAOD::TauJetParameters::JetBDTSigTight);
  m_decorator.set(tau, TauIntProps::isBDTTight, istight);

  float bdtscore= tau->discriminant(xAOD::TauJetParameters::BDTJetScore);
  m_decorator.set(tau, TauFloatProps::BDTScore, bdtscore);

  bool passevetoloose=! tau->isTau(xAOD::TauJetParameters::EleBDTLoose);
  m_decorator.set(tau, TauIntProps::passEvetoLoose, passevetoloose);
  bool passevetomedium=! tau->isTau(xAOD::TauJetParameters::EleBDTMedium);
  m_decorator.set(tau, TauIntProps::passEvetoMedium, passevetomedium);
  bool passevetotight=! tau->isTau(xAOD::TauJetParameters::EleBDTTight);
  m_decorator.set(tau, TauIntProps::passEvetoTight, passevetotight);

  float bdtelescore= tau->discriminant(xAOD::TauJetParameters::BDTEleScore);
  m_decorator.set(tau, TauFloatProps::EleBDTScore, bdtelescore);

  bool accept=m_tauSelectionTool->accept( *tau );
  m_decorator.set(tau, TauIntProps::passTauSelector, accept);

  float charge=tau->charge();
  m_decorator.set(tau, TauFloatProps::charge, charge);

  /*presel*/
  bool presel=accept;
  m_decorator.set(tau, TauIntProps::passPreSel, presel);
  if( !m_decorator.exists(tau, TauFloatProps::effSF)){
    m_decorator.set(tau, TauFloatProps::effSF, 1);
    m_decorator.set(tau, TauFloatProps::effSFeveto, 1);
   }

  EL_CHECK("TauHandler::decorate",TruthMatch(tau));

  return EL::StatusCode::SUCCESS;
  
}

bool TauHandler::LooseTau(xAOD::TauJet * tau) {
  bool passSel = true;
  if (tau->pt()<20000)passSel=false;
  if (abs(tau->eta())>2.5)passSel=false;
 if (!(m_decorator.get(tau, TauIntProps::passTauSelector))) passSel = false;
 if (!(m_decorator.get(tau, TauIntProps::isBDTMedium))) passSel = false;
 if (!(m_decorator.get(tau, TauIntProps::passEvetoLoose))) passSel = false;

 m_decorator.set(tau, TauIntProps::passLooseTau, passSel);

  return passSel;
}

EL::StatusCode TauHandler::FindTrueTaus(){
  if(! m_truthhandler ) {
    Error("TauHandler::TruthMatch()", "Cannot find truthparticle handler");
    return EL::StatusCode::FAILURE;
  }

  // thats how it usually done, working on the Nominal InParticleVariation
  xAOD::TruthParticleContainer* truthContainer =  m_truthhandler -> getInParticleVariation("Nominal");

  if(!truthContainer) {
    Error("TauHandler::TruthMatch()", "Cannot find nominal outParticle container for mctruth");
    return EL::StatusCode::FAILURE;
  }
  
  // Build a vector of true taus. 

  for(xAOD::TruthParticle* part : *truthContainer) {

    // also register partons above 4 gev (pt cut to speed up processing time..)
    if( part->pt() > 4000. && ( (fabs(part->pdgId()) > 0 &&   fabs(part->pdgId()) < 7 ) || 
				fabs(part->pdgId()) == 21) ){
      //      std::cout<<"pdg:"<< part->pdgId()<<" pt=" << part->pt() << " eta="<< part->eta() <<" status:"<<part->status()<<"children:"<<part->nChildren()<<std::endl;
      if ( part->status() == 2 ||  part->status() == 11 ||  part->status() == 3) 
	m_truepartons.push_back(part);
    }
    
    if( ! ( fabs(part->pdgId()) == 15 || fabs(part->pdgId()) == 11 || fabs(part->pdgId()) == 13 )) continue;
    if(part->status() ==3 ) continue;

    // do the leptons first:
    if(fabs(part->pdgId()) == 11 || fabs(part->pdgId()) == 13){
      if(part->status() != 1 ) continue;
      // check where it comes from, lets consider only electrons from EW parents for now
      bool coolele=false;
      for(unsigned int iParents=0; iParents< part->nParents(); ++iParents){
	xAOD::TruthParticle* parent = ( xAOD::TruthParticle*) part->parent(iParents);
	if ( fabs(parent->pdgId()) == 15 || fabs(parent->pdgId()) == 23 || fabs(parent->pdgId()) == 24 )
	  coolele=true;
      }
      if(! coolele) continue;
      if (fabs(part->pdgId()) == 11 ) m_trueeles.push_back(part);
      if (fabs(part->pdgId()) == 13 ) m_truemuons.push_back(part);
      
    } // ele or muon

    if( fabs(part->pdgId()) == 15){
      bool ishad=true;
      //    std::cout<<"----- "<<part->nChildren() <<std::endl;
      for(unsigned int iChild=0; iChild< part->nChildren(); ++iChild){
	xAOD::TruthParticle* child = ( xAOD::TruthParticle*) part->child(iChild);
	//std::cout<<"Child status:pdgid"<<child->status()  <<child->pdgId()  <<std::endl;
    
	if( child->status() == 3 ) continue;
	if( fabs( child->pdgId() ) == 11 || fabs( child->pdgId() ) == 13 ){
	  m_truetaus_lep.push_back(part);
	  ishad=false;
	  break;
	}
      }

      if(ishad) {
	m_truetaus_had.push_back(part);
      }
    }//taus
  } // truth particles
  
  m_SearchedTrueTaus=true;

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode TauHandler::TruthMatch(xAOD::TauJet * tau){
  
  m_decorator.set(tau, TauIntProps::TruthMatch, 0);
  m_decorator.set(tau, TauIntProps::LeptonTruthMatch, 0);
  bool hasmatch=false;

  // only perform time consuming truth matching for tau candidates passing some basic criteria: 
  if (tau->pt()<10000 || 
      fabs(tau->charge()) != 1 || 
      fabs(tau->eta())>2.5
      ) 
    return EL::StatusCode::SUCCESS;

  if(!m_SearchedTrueTaus){ 
    if(FindTrueTaus() != EL::StatusCode::SUCCESS){
      Error("in TauHandler::TruthMatch()","Failed to FindTrueTaus. Exiting.");
      return EL::StatusCode::FAILURE; 
    }
  }

  // std::cout<<"number of true had taus:"<<m_truetaus_had.size()<<std::endl;
  // std::cout<<"number of true lep taus:"<<m_truetaus_lep.size()<<std::endl;
  //  std::cout<<"number of partons:"<<m_truepartons.size()<<std::endl;


  // Check hadronic taus: 
  float mindr=0.2;
  for(unsigned int iPart=0; iPart<m_truetaus_had.size(); ++iPart){
    if( (m_truetaus_had[iPart]->p4()).DeltaR(tau->p4())<mindr ){
      m_decorator.set(tau, TauIntProps::TruthMatch, 1);
      hasmatch=true;
    }
  }// thads

  for(unsigned int iPart=0; iPart<m_truetaus_lep.size(); ++iPart){
    if( (m_truetaus_lep[iPart]->p4()).DeltaR(tau->p4())<mindr ){
      m_decorator.set(tau, TauIntProps::TruthMatch, 2);
      hasmatch=true;
      //   std::cout<<"found lep tau match"<<std::endl;
    }
  }// tleps

  for(unsigned int iPart=0; iPart<m_trueeles.size(); ++iPart){
    if( (m_trueeles[iPart]->p4()).DeltaR(tau->p4())<mindr ){
      m_decorator.set(tau, TauIntProps::LeptonTruthMatch, 1); // matched to true electron
      hasmatch=true;
    }
  }// true eles

  for(unsigned int iPart=0; iPart<m_truemuons.size(); ++iPart){
    if( (m_truemuons[iPart]->p4()).DeltaR(tau->p4())<mindr ){
      m_decorator.set(tau, TauIntProps::LeptonTruthMatch, 2); // matched to true muon
      hasmatch=true;
    }
  }// true eles
  
  // look whether it has a parton match
  if(! hasmatch){
    float highestpt=1.; // at least 1 mev please
    int partonindex=-1;
    for(unsigned int iPart=0; iPart<m_truepartons.size(); ++iPart){

      if( m_truepartons[iPart]->pt() >highestpt &&   (m_truepartons[iPart]->p4()).DeltaR(tau->p4())< 0.4 ){
	partonindex=iPart;
	highestpt=  m_truepartons[iPart]->pt();
      }
    }
    if (partonindex>=0){
      int partonpdgid=fabs(m_truepartons[partonindex]->pdgId());
      m_decorator.set(tau, TauIntProps::TruthMatch, -(partonpdgid));
      //      std::cout<<"Matched tau to parton, tau pt: "<<tau->pt()/1000. <<" pdgID: "<< partonpdgid<<" pt:" << highestpt/1000. <<std::endl;
    }
    // else{
    //   std::cout<<"No match found for tau pt "<<tau->pt()<<std::endl;
    // }
  }
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode TauHandler::calibrateCopies(xAOD::TauJetContainer * particles, const CP::SystematicSet & sysSet)
{

  int isMC = m_eventInfoHandler.get_isMC();
	       
  // tell tool to apply systematic variation
  CP_CHECK("TauHandler::calibrateCopies()",m_tauSmearingTool->applySystematicVariation(sysSet),m_debug);
  CP_CHECK("TauHandler::calibrateCopies()",m_tauEfficiencyCorrections->applySystematicVariation(sysSet),m_debug);
  CP_CHECK("TauHandler::calibrateCopies()",m_tauEfficiencyCorrections_eveto->applySystematicVariation(sysSet),m_debug);
  //  std::cout<<"Loop over taus:"<<std::endl;

  for (xAOD::TauJet * tau : *particles) {
    //      std::cout<<"new tau "<<std::endl;

    //calibration
    //------------
    setP4( tau , tau );
    
    bool accepted = m_tauSelectionTool->accept( *tau );
    double effSF= 1.0;
    double effSF_eveto= 1.0;

    if ( isMC && accepted ) {
      CP_CHECK("TauHandler::calibrateCopies()",m_tauSmearingTool->applyCorrection(*tau),m_debug);
      CP_CHECK("TauHandler::calibrateCopies()",m_tauEfficiencyCorrections->getEfficiencyScaleFactor(*tau, effSF),m_debug);
      CP_CHECK("TauHandler::calibrateCopies()",m_tauEfficiencyCorrections_eveto->getEfficiencyScaleFactor(*tau, effSF_eveto),m_debug);
    }

    m_decorator.set(tau, TauFloatProps::effSF, effSF);
    m_decorator.set(tau, TauFloatProps::effSFeveto, effSF_eveto);
	  
    //    std::cout<<"decorate tau "<<std::endl;
    // decorate tau
    if ( decorate( tau ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
    //    std::cout<<"done with tau "<<std::endl;
  }
  return EL::StatusCode::SUCCESS;
  
}

EL::StatusCode TauHandler::clearEvent() 
{
  m_truetaus_had.clear();
  m_truetaus_lep.clear();
  m_trueeles.clear();
  m_truemuons.clear();
  m_truepartons.clear();

  m_SearchedTrueTaus=false;
  EL_CHECK("TauHandler::clearEvent()",ObjectHandler::clearEvent());

  return EL::StatusCode::SUCCESS;

}
