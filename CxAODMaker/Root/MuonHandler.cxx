#include <iostream>

//muon specific includes
#include "xAODMuon/MuonContainer.h"
#include "xAODMuon/MuonAuxContainer.h"
#include "CxAODMaker/MuonHandler.h"
#include "MuonMomentumCorrections/MuonCalibrationAndSmearingTool.h"
#include "MuonSelectorTools/MuonSelectionTool.h"
#include "MuonEfficiencyCorrections/MuonEfficiencyScaleFactors.h"

// declare static members
MuonDecorator MuonHandler::m_decorator;

MuonHandler::MuonHandler(const std::string& name, ConfigStore & config, xAOD::TEvent *event,
                         EventInfoHandler & eventInfoHandler) :
  ObjectHandler(name, config, event, eventInfoHandler),
  m_muonCalibrationAndSmearingTool(0),
  m_muonSelectionTool(0)
{
  m_selectFcns.push_back(&passVHLooseMuon);
  m_selectFcns.push_back(&passVHSignalMuon);
  m_selectFcns.push_back(&passZHSignalMuon);
  m_selectFcns.push_back(&passWHSignalMuon);
}

MuonHandler::~MuonHandler() {

  //delete tool:
  delete m_muonCalibrationAndSmearingTool;
  delete m_muonSelectionTool;
  
}


EL::StatusCode MuonHandler::initializeTools() 
{

  // initialize the muon calibration and smearing tool - default settings are recommended for 8 TeV and 13 TeV  -- last updated: 15/02/24
  //-----------------------------------------------------------------------------------------------------------
  m_muonCalibrationAndSmearingTool = new CP::MuonCalibrationAndSmearingTool("MuonCalibrationTool");
  m_muonCalibrationAndSmearingTool->msg().setLevel( m_msgLevel ); 
  TOOL_CHECK("MuonHandler::initializeTools()",m_muonCalibrationAndSmearingTool->initialize());
  
  // initialize the muon selector tool -- last updated: 15/02/24
  //---------------------------------------------------......................
  m_muonSelectionTool = new CP::MuonSelectionTool("MuonSelectionTool");
  m_muonSelectionTool->msg().setLevel( m_msgLevel );
  //m_muonSelectionTool->setProperty("MaxEta", 2.7); //default 2.5
  TOOL_CHECK("MuonHandler::initializeTools()",m_muonSelectionTool->setProperty("MuQuality", 1)); // 0 tight, 1 medium, 2 loose, 3 very loose
  TOOL_CHECK("MuonHandler::initializeTools()",m_muonSelectionTool->initialize());
  
  // initialize the muon efficiency tool -- last updated: 15/02/24
  //---------------------------------------------------------------
  m_muonEfficiencyScaleFactors = new CP::MuonEfficiencyScaleFactors("MuonEfficiencyTool");
  m_muonEfficiencyScaleFactors->msg().setLevel( m_msgLevel );
  TOOL_CHECK("MuonHandler::initializeTools()",m_muonEfficiencyScaleFactors->setProperty("WorkingPoint", "CBandST")); //medium working point
  TOOL_CHECK("MuonHandler::initializeTools()",m_muonEfficiencyScaleFactors->setProperty("DataPeriod", "2012")); // will be "2015" for 13 TeV
  TOOL_CHECK("MuonHandler::initializeTools()",m_muonEfficiencyScaleFactors->initialize());
  
  // register ISystematicsTools
  //---------------------------
  m_sysToolList.clear();
  m_sysToolList.push_back(m_muonCalibrationAndSmearingTool);
  m_sysToolList.push_back(m_muonEfficiencyScaleFactors);

  return EL::StatusCode::SUCCESS;

}


EL::StatusCode MuonHandler::decorate(xAOD::Muon * muon) 
{

  //compute some stuff, e.g. d0,z0, decorate muon object, but apply cuts later (in passVHLooseMuon,...)!

  //compute d0, z0
  //---------------
  const xAOD::TrackParticle * trackPart = muon->trackParticle(xAOD::Muon::TrackParticleType::InnerDetectorTrackParticle);
  if (!trackPart) {
    if (muon->muonType() != xAOD::Muon::MuonStandAlone) {
      Warning("MuonHandler::calibrateCopies","Couldn't get inner detector track particle... trying to get primary one");
    }
    trackPart = muon->trackParticle(xAOD::Muon::TrackParticleType::Primary);
  }
  if (!trackPart) {
    Error("MuonHandler::calibrateCopies","Failed to get the TrackParticle to retrieve d0/z0...");
    return EL::StatusCode::FAILURE; //do we want a failure here?
  }
  float pvZ = m_eventInfoHandler.get_ZPV();
  float d0 = trackPart->d0(); 
  float z0 = trackPart->z0()+ trackPart->vz() - pvZ;

  //get decision from muon selection tool
  //---------------------------------
  bool passedIDCuts = m_muonSelectionTool->passedIDCuts(*muon);
  bool accepted = m_muonSelectionTool->accept(*muon);

  //get SFs from muon SF tool
  //--------------------------
  int isMC = m_eventInfoHandler.get_isMC();
  float effSF = 1.;
  if (isMC) {
    // TODO we would like to have this for Nominal only - why, using shallow copies...?
    CP_CHECK("MuonHandler::decorate()",m_muonEfficiencyScaleFactors->getEfficiencyScaleFactor(*muon, effSF),m_debug);
  }

  //decorate muon 
  //---------------
  m_decorator.set(muon, MuonFloatProps::d0,d0);
  m_decorator.set(muon, MuonFloatProps::z0,z0);
  m_decorator.set(muon, MuonIntProps::passedIDCuts, passedIDCuts);
  m_decorator.set(muon, MuonIntProps::acceptedMuonTool,accepted);
  m_decorator.set(muon, MuonFloatProps::effSF, effSF);

  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode MuonHandler::calibrateCopies(xAOD::MuonContainer * particles, const CP::SystematicSet & sysSet) 
{

  // get isMC
  int isMC = m_eventInfoHandler.get_isMC();

  // tell tool to apply systematic variation
  CP_CHECK("MuonHandler::calibrateCopies()",m_muonCalibrationAndSmearingTool->applySystematicVariation(sysSet),m_debug);

  // tell tool to apply systematic variation
  CP_CHECK("MuonHandler::calibrateCopies()",m_muonEfficiencyScaleFactors->applySystematicVariation(sysSet),m_debug);
  // TODO this behaves badly for Original, since calibrate() is not called
  // TODO call applySystematicVariation() in ObjectHandler via m_sysToolList

  // loop over the particles in the container
  for (xAOD::Muon * muon : *particles) {
    
    //calibration
    //------------
    //this ensures that the DynAux container has the same number of entries as the original one
    //since the calibration is not valid for all inMuons...
    setP4( muon , muon );
    
    if ( isMC ) {
      CP_CHECK("MuonHandler::calibrateCopies()",m_muonCalibrationAndSmearingTool->applyCorrection(*muon),m_debug);
    }

    // decorate muon
    if ( decorate( muon ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
    
  }

  return EL::StatusCode::SUCCESS;

}


bool MuonHandler::checkPassSelOR(xAOD::Muon * part) 
{

  int res = 0;
  m_decorator.get(part, MuonIntProps::passORGlob, res);
  return res;

}


bool MuonHandler::checkPassSelNoOR(xAOD::Muon * part) 
{

  int res = 0;
  m_decorator.get(part, MuonIntProps::isVHLooseMuon, res);
  return res;

}


bool MuonHandler::passVHLooseMuon(xAOD::Muon * muon) 
{

  bool passSel = true;

  //apply selection for combined or segment tagged muons for now
  if (!((muon->muonType() == xAOD::Muon::Combined) || (muon->muonType() == xAOD::Muon::SegmentTagged))) passSel = false;
  if (!(fabs(m_decorator.get(muon, MuonFloatProps::d0)) < 0.1)) passSel = false;
  if (!(fabs(m_decorator.get(muon, MuonFloatProps::z0)) < 10)) passSel = false;
  if (!(m_decorator.get(muon, MuonIntProps::acceptedMuonTool))) passSel = false; //abs(eta) < 2.7, ID cuts, medium
  if (!(muon->pt() > 7000.)) passSel = false;
  float trackIso = -999.;
  muon->isolation(trackIso,xAOD::Iso::ptcone20); 
  //  if (!((trackIso / muon->pt()) < 0.1)) passSel = false; //just for now until isolation problems are fixed in input!
  
  // outdated cuts
  //---------------
  // Do not use author directly.  For 13TeV it will kill MuGirl(Combined) and MuTagIMO(SegmentTagged).
  // For 8TeV it makes no difference as only combined available is MuidCo and all MuTagIMO(SegmentTagged)muons fail passedIDCuts
  // if (!(muon->author() == xAOD::Muon::MuidCo)) passSel = false;
  // if (!(fabs(muon->eta()) < 2.7)) passSel = false; //done by the muon selection tool.
  // if (!(m_decorator.get(muon, MuonIntProps::passedIDCuts))) passSel = false; //done by the muon selection tool.
  // Do not use quality directly. It always returns Loose==2(Tight==0) in 13(8)TeV. Quality selection(medium) is done by the muon selection tool.
  // if (!(muon->quality() == xAOD::Muon::Tight)) passSel = false;

  m_decorator.set(muon, MuonIntProps::isVHLooseMuon, passSel);
  m_decorator.set(muon, MuonIntProps::passPreSel, passSel);

  return passSel;

}

bool MuonHandler::passVHSignalMuon(xAOD::Muon* muon){
  
  bool passSel = true;
 
  //check loose selection is passed
  if(!(m_decorator.get(muon, MuonIntProps::isVHLooseMuon))) passSel = false;
  //common cuts
  if (!((muon->muonType() == xAOD::Muon::Combined) || (muon->muonType() == xAOD::Muon::SegmentTagged))) passSel = false;
  if (!(fabs(muon->eta()) < 2.5)) passSel = false;
  if (!(muon->pt() > 25000.)) passSel = false;

  m_decorator.set(muon, MuonIntProps::isVHSignalMuon, passSel);
  
  return passSel;
}

bool MuonHandler::passZHSignalMuon(xAOD::Muon* muon){
  
  bool passSel = true;
 
  //check VH selection is passed
  if(!(m_decorator.get(muon, MuonIntProps::isVHSignalMuon))) passSel = false;

  m_decorator.set(muon, MuonIntProps::isZHSignalMuon, passSel);
  
  return passSel;
}

bool MuonHandler::passWHSignalMuon(xAOD::Muon* muon){
  
  bool passSel = true;
 
  //check VH selection is passed
  if(!(m_decorator.get(muon, MuonIntProps::isVHSignalMuon))) passSel = false;

  float trackIso = -999.;
  float caloIso = -999.;
  muon->isolation(trackIso,xAOD::Iso::ptcone20); 
  muon->isolation(caloIso,xAOD::Iso::etcone30); 
  //  if (!((trackIso / muon->pt()) < 0.04)) passSel = false; //just for now until isolation problems are fixed in input!
  // if (!((caloIso / muon->pt()) < 0.04)) passSel = false;//just for now until isolation problems are fixed in input!

  m_decorator.set(muon, MuonIntProps::isWHSignalMuon, passSel);
  
  return passSel;
}

EL::StatusCode MuonHandler::setVariables(xAOD::Muon * inMuon, xAOD::Muon * outMuon, bool isKinVar, bool isWeightVar) 
{


  // Kinematics only to be written in case its not a weight variation
  if( ! isWeightVar ){
    setP4( inMuon , outMuon );
    float trackIso = -999.;
    float caloIso = -999.;
    inMuon->isolation(trackIso, xAOD::Iso::ptcone20);
    inMuon->isolation(caloIso, xAOD::Iso::etcone30);
    outMuon->setIsolation(trackIso, xAOD::Iso::ptcone20);
    outMuon->setIsolation(caloIso, xAOD::Iso::etcone30); //corrected? not available (yet)!
    
    // set something without having a pre-defined method
    m_decorator.copy(inMuon, outMuon, MuonIntProps::isVHLooseMuon);
    m_decorator.copy(inMuon, outMuon, MuonIntProps::isZHSignalMuon);
    m_decorator.copy(inMuon, outMuon, MuonIntProps::isWHSignalMuon);
  

    // not dependent on systematic variations
    if ( !isKinVar ) {
      //set muon type
      xAOD::Muon::MuonType muonType = inMuon->muonType();
      outMuon->setMuonType(muonType);
      // set something without having a pre-defined method
      //    m_decorator.copy(inMuon, outMuon, MuonFloatProps::z0);
      //    m_decorator.copy(inMuon, outMuon, MuonFloatProps::d0);
    }
  }
  
  // SF to be written for nominal and all variations 
  int isMC = m_eventInfoHandler.get_isMC();
  if (isMC) {
    m_decorator.copy(inMuon, outMuon, MuonFloatProps::effSF);
  }
  
  return EL::StatusCode::SUCCESS;

}


EL::StatusCode MuonHandler::fillOutputContainer() 
{

  EL::StatusCode res = EL::StatusCode::FAILURE;
  if(m_usedInOR) {
    res = fillOutputContainerCheck(&checkPassSelOR);
  }
  else {
    res = fillOutputContainerCheck(&checkPassSelNoOR);
  }
  return res;

}


EL::StatusCode MuonHandler::clearEvent() 
{
  EL_CHECK("EL::StatusCode MuonHandler::clearEvent()",ObjectHandler::clearEvent());
  return EL::StatusCode::SUCCESS;

}
