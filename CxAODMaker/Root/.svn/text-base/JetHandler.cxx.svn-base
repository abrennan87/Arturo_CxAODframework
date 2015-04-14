#include <iostream>

// jet specific includes
#include "xAODJet/JetContainer.h"
#include "xAODJet/JetAuxContainer.h"
#include "CxAODMaker/JetHandler.h"
#include "JetResolution/JERTool.h"
#include "JetResolution/JERSmearingTool.h"
#include "JetCalibTools/JetCalibrationTool.h"
#include "JetSelectorTools/JetCleaningTool.h"
#include "JetUncertainties/JetUncertaintiesTool.h"
#include "xAODBTagging/BTagging.h"

// declare static members
JetDecorator JetHandler::m_decorator;

JetHandler::JetHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
                       EventInfoHandler & eventInfoHandler) :
  ObjectHandler(name, config, event, eventInfoHandler),
  m_jetCalibration(0),
  m_jetCleaning(0),
  m_jetAlgoName("none"),
  m_isMC(0),
  m_is8TeV(0)
{

  // set jet algorithm name
  m_config.getif<std::string>(name+"AlgoName",m_jetAlgoName);

  m_selectFcns.push_back(&passVetoJet);
  m_selectFcns.push_back(&passSignalJet);
}

JetHandler::~JetHandler() {

  //delete tools
  delete m_jetCalibration;
  delete m_jetCleaning;

}

EL::StatusCode JetHandler::initializeTools()
{
  m_isMC = m_eventInfoHandler.get_isMC();
  m_is8TeV = m_eventInfoHandler.get_is8TeV();

  //initialize jet calibration tool - this hopefully will become less messy...
  // https://twiki.cern.ch/twiki/bin/view/AtlasProtected/ApplyJetCalibration2014
  //-----------------------------------------------------------------------------
  std::string configFile = "JES_Full2012dataset_May2014.config"; //JES_Full2012dataset_AFII_January2014.config for AFII!!
  if(!m_is8TeV) configFile = "JES_Prerecommendation2015_Feb2015.config";
  std::string calibSeq = "JetArea_Residual_Origin_EtaJES_GSC";
  if(!m_is8TeV) calibSeq = "JetArea_Residual_EtaJES" ;
  if(!m_isMC && m_is8TeV) calibSeq += "_Insitu";

  Info("JetHandler::initializeTools()","m_containerName = %s, m_jetAlgoName = %s, m_isMC = %s",m_containerName.c_str(), m_jetAlgoName.c_str(), m_isMC ? "true" : "false");
  
  m_jetCalibration = new JetCalibrationTool("JetCorrectionTool", 
					    m_jetAlgoName.c_str(),
					    configFile.c_str(),
					    calibSeq.c_str(),
					    !m_isMC);
  m_jetCalibration->msg().setLevel( m_msgLevel );

  TOOL_CHECK("JetHandler()::initializeTools()",m_jetCalibration->initializeTool("JetCorrectionTool"));
 
  // initialize the JES uncertainty tool
  // https://twiki.cern.ch/twiki/bin/view/AtlasProtected/JetUncertaintiesDC14
  //------------------------------------
  m_jesProvider = new JetUncertaintiesTool("JESProvider");
  m_jesProvider->msg().setLevel( m_msgLevel );
  TOOL_CHECK("JetHandler()::initializeTools()",m_jesProvider->setProperty("JetDefinition", m_jetAlgoName ));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jesProvider->setProperty("MCType","MC12"));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jesProvider->setProperty("ConfigFile","JES_2012/Final/InsituJES2012_14NP.config"));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jesProvider->initialize());
  
  // initialize and configure the jet cleaning tool
  //------------------------------------------------
  m_jetCleaning = new JetCleaningTool("JetCleaning");
  m_jetCleaning->msg().setLevel( m_msgLevel );
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetCleaning->setProperty( "CutLevel", "MediumBad"));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetCleaning->initialize());
  
  // initialize and configure the JER tools
  // https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/JetEnergyResolutionXAODTools
  //------------------------------------------------
  std::string containername;
  m_config.getif<std::string>("jetContainer",containername);
  //JER
  //----
  m_jetResolution = new JERTool("JERTool");
  m_jetResolution->msg().setLevel( m_msgLevel );
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetResolution->setProperty("PlotFileName", "JetResolution/JERProviderPlots_2012.root"));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetResolution->setProperty("CollectionName", containername));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetResolution->setProperty("BeamEnergy", "8TeV"));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetResolution->setProperty("SimulationType", "FullSim"));
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetResolution->initialize());
  
  //JER smearing
  //-------------
  m_jetResolutionSmearing = new JERSmearingTool("JERSmearingTool");
  m_jetResolutionSmearing->msg().setLevel( m_msgLevel );
  m_jetResolutionSmearing->setJERTool(m_jetResolution);
  m_jetResolutionSmearing->setNominalSmearing(false);
  TOOL_CHECK("JetHandler()::initializeTools()",m_jetResolutionSmearing->initialize());
  
  // register ISystematicsTools
  //---------------------------
  m_sysToolList.clear();
  m_sysToolList.push_back(m_jesProvider);
  m_sysToolList.push_back(m_jetResolutionSmearing);
    
  
  return EL::StatusCode::SUCCESS;

}


EL::StatusCode JetHandler::decorate(xAOD::Jet * jet) 
{

  // add decoration to jet
  // TODO: do we really need the decorate method?
  if (!m_decorator.exists(jet, JetIntProps::goodJet)) {
    bool goodJet = m_jetCleaning->accept( *jet );
    m_decorator.set(jet, JetIntProps::goodJet, goodJet);
  }


  // TODO: how will systematics be treated for JVF? Make sure decorate is the right place for this. If a tool will be provided this should go into calibratecopies !?
  std::vector<float> jvf;
  jet->getAttribute("JVF",jvf);
  int indexPV =  m_eventInfoHandler.get_indexPV();
  if( jvf.size() > 0) {
    m_decorator.set(jet,JetFloatProps::JVF,jvf[indexPV]);
  } else  {
    m_decorator.set(jet,JetFloatProps::JVF,0);
  }


  // set btagging discriminants in the output
  retrieveBTaggingDiscriminants(jet);
  //
  return EL::StatusCode::SUCCESS;
  
}



EL::StatusCode JetHandler::calibrateCopies(xAOD::JetContainer * particles, const CP::SystematicSet & sysSet) 
{
  

  CP_CHECK("JetHandler::calibrateCopies()",m_jetResolutionSmearing->applySystematicVariation(sysSet),m_debug);

  CP_CHECK("JetHandler::calibrateCopies()",m_jesProvider->applySystematicVariation(sysSet),m_debug);

  // loop over the particles in the container
  for (xAOD::Jet * jet : *particles) {
    //this ensures that the DynAux container has the same number of entries as the original one
    setP4( jet , jet );

    //only calibrate and write good clean jets
    bool goodJet = m_jetCleaning->accept( *jet );
    m_decorator.set(jet, JetIntProps::goodJet, goodJet);
    
    // MC: calibrate pT - use shallow copy
    if ( goodJet ) {
      CP_CHECK("JetHandler::calibrateCopies()",m_jetCalibration->applyCorrection(*jet),m_debug);
      
      // JER treatment: Only apply for MC, the tool does not know about it yet 
      if(m_isMC){
	CP_CHECK("JetHandler::calibrateCopies()",m_jetResolutionSmearing->applyCorrection(*jet),m_debug);
	CP_CHECK("JetHandler::calibrateCopies()",m_jesProvider->applyCorrection(*jet),m_debug);
      }
    }

    // decorate jet
    if ( decorate( jet ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
    
  }
  
  return EL::StatusCode::SUCCESS;

}

void JetHandler::retrieveBTaggingDiscriminants(xAOD::Jet * part) 
{
  const xAOD::BTagging * tagInfo = part->btagging();
  
  double discriminant_mv1 = 0;
  double discriminant_sv1_ip3d = 0;
  double discriminant_mv2c00=0;
  double discriminant_mv2c10=0;
  double discriminant_mv2c20=0;
  double discriminant_mvb=0;
  
  if(tagInfo) {
    // for the moment - ignore the retval since we've set a default value
    //bool retval = tagInfo->MVx_discriminant("MV1",discriminant_mv1);
    tagInfo->MVx_discriminant("MV1",discriminant_mv1);
    discriminant_sv1_ip3d = tagInfo->SV1plusIP3D_discriminant();
    tagInfo->MVx_discriminant("MV2c00",discriminant_mv2c00);
    tagInfo->MVx_discriminant("MV2c10",discriminant_mv2c10);
    tagInfo->MVx_discriminant("MV2c20",discriminant_mv2c20);
    tagInfo->MVx_discriminant("MVb",discriminant_mvb);
  }
  m_decorator.set(part,JetFloatProps::MV1, discriminant_mv1);
  m_decorator.set(part,JetFloatProps::SV1_IP3D,discriminant_sv1_ip3d);
  m_decorator.set(part,JetFloatProps::MV2c00,discriminant_mv2c00);
  m_decorator.set(part,JetFloatProps::MV2c10,discriminant_mv2c10);
  m_decorator.set(part,JetFloatProps::MV2c20,discriminant_mv2c20);
  m_decorator.set(part,JetFloatProps::MVb,discriminant_mvb);
}

bool JetHandler::checkPassSelOR(xAOD::Jet * part)
{

  int res = 0;
  m_decorator.get(part, JetIntProps::passORGlob, res);
  return res;

}


bool JetHandler::checkPassSelNoOR(xAOD::Jet * part)
{

  int res = 0;
  m_decorator.get(part, JetIntProps::isVetoJet, res);
  return res;

}


bool JetHandler::passVetoJet(xAOD::Jet* jet)
{
  
  bool passCentral = checkCentralJet(jet);
  
  bool passForward = true;
  if (!(jet->pt() > 30000.)) passForward = false;
  if (!(fabs(jet->eta()) >= 2.5)) passForward = false;
  if (!(fabs(jet->eta()) < 4.5)) passForward = false;
  
  bool passSel = true;
  if (!(m_decorator.get(jet, JetIntProps::goodJet))) passSel = false;
  if (!(fabs(m_decorator.get(jet,JetFloatProps::JVF)) > 0.5
          || !(jet->pt() < 50000. && fabs(jet->eta()) < 2.4))) passSel = false;
  if (!(passCentral || passForward)) passSel = false;
  
  m_decorator.set(jet, JetIntProps::isVetoJet, passSel);
  m_decorator.set(jet, JetIntProps::isVBFJet, passSel);
  m_decorator.set(jet, JetIntProps::passPreSel, passSel);
  return passSel;
}

bool JetHandler::passSignalJet(xAOD::Jet* jet)
{
  
  bool passSel = true;
  if (!(m_decorator.get(jet, JetIntProps::isVetoJet))) passSel = false;
  if (!(checkCentralJet(jet))) passSel = false;
  
  m_decorator.set(jet, JetIntProps::isSignalJet, passSel);
  return passSel;
}

bool JetHandler::checkCentralJet(xAOD::Jet* jet)
{
  bool passSel = true;
  if (!(jet->pt() > 20000.)) passSel = false;
  if (!(fabs(jet->eta()) < 2.5)) passSel = false;
  
  return passSel;
}

EL::StatusCode JetHandler::setVariables(xAOD::Jet * inJet, xAOD::Jet * outJet, bool isKinVar, bool isWeightVar)
{

  if(!isWeightVar){
    // set four momentum
    setP4( inJet , outJet );
    
    if(m_isMC) m_decorator.copy(inJet, outJet, JetIntProps::truthLabel); // in input xAOD
    m_decorator.copy(inJet, outJet, JetIntProps::isVetoJet);
    m_decorator.copy(inJet, outJet, JetIntProps::isSignalJet);
    m_decorator.copy(inJet, outJet, JetFloatProps::MV1);
    m_decorator.copy(inJet, outJet, JetFloatProps::SV1_IP3D);
    m_decorator.copy(inJet, outJet, JetFloatProps::MV2c00);
    m_decorator.copy(inJet, outJet, JetFloatProps::MV2c10);
    m_decorator.copy(inJet, outJet, JetFloatProps::MV2c20);
    m_decorator.copy(inJet, outJet, JetFloatProps::MVb);
    m_decorator.copy(inJet, outJet, JetFloatProps::JVF);
    
    if( !isKinVar){
      // copy first nTrk for OR
      std::vector<int> nTrkVecIn;
      inJet->getAttribute(xAOD::JetAttribute::NumTrkPt500, nTrkVecIn);
      std::vector<int> nTrkVecOut;
      nTrkVecOut.push_back(nTrkVecIn.at(0));
      outJet->setAttribute(xAOD::JetAttribute::NumTrkPt500, nTrkVecOut);
    }
  }
  
  return EL::StatusCode::SUCCESS;

 }


EL::StatusCode JetHandler::fillOutputContainer() 
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


EL::StatusCode JetHandler::clearEvent() {
 
  EL_CHECK("JetHandler::clearEvent()",ObjectHandler::clearEvent());
  return EL::StatusCode::SUCCESS;

}
