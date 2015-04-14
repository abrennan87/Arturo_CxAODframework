#include <iostream>

// electron specific includes
#include "xAODEgamma/ElectronContainer.h"
#include "xAODEgamma/ElectronAuxContainer.h"
#include "CxAODMaker/ElectronHandler.h"
#include "ElectronPhotonFourMomentumCorrection/EgammaCalibrationAndSmearingTool.h"
#include "ElectronEfficiencyCorrection/AsgElectronEfficiencyCorrectionTool.h"
#include "ElectronPhotonSelectorTools/AsgElectronLikelihoodTool.h"
#include "ElectronPhotonSelectorTools/AsgElectronIsEMSelector.h"
#include "PathResolver/PathResolver.h"

ElectronDecorator ElectronHandler::m_decorator;


ElectronHandler::ElectronHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
                                 EventInfoHandler & eventInfoHandler) : 
  ObjectHandler(name, config, event, eventInfoHandler),
  m_EgammaCalibrationAndSmearingTool(nullptr),
  m_effToolVeryLooseLH(nullptr),
  m_effToolVeryTightLH(nullptr),
  m_checkVeryLooseLH(nullptr),
  m_checkVeryTightLH(nullptr),
  m_ElectronIsEMSelector(nullptr)
{
  m_selectFcns.push_back(&passVHLooseElectron);
  m_selectFcns.push_back(&passVHSignalElectron);
  m_selectFcns.push_back(&passZHSignalElectron);
  m_selectFcns.push_back(&passWHSignalElectron);
}


ElectronHandler::~ElectronHandler() 
{

  //delete tools
  delete m_EgammaCalibrationAndSmearingTool;
  delete m_effToolVeryLooseLH;
  delete m_effToolVeryTightLH;
  delete m_checkVeryLooseLH;
  delete m_checkVeryTightLH;
  delete m_ElectronIsEMSelector;

}


EL::StatusCode ElectronHandler::initializeTools() 
{
  
  bool is8TeV = m_eventInfoHandler.get_is8TeV();
  // TODO atlfast / fullsim
  //  enum DataType {Data = 0, Full = 1, FastShower = 2, Fast = 3, True = 4}
  int dataType = PATCore::ParticleDataType::Full;

  //calibration tool
  //-----------------
  m_EgammaCalibrationAndSmearingTool = new CP::EgammaCalibrationAndSmearingTool("EgammaCalibrationAndSmearingTool_Electrons");
  m_EgammaCalibrationAndSmearingTool->msg().setLevel( m_msgLevel );
  TOOL_CHECK("ElectronHandler::initializeTools()", m_EgammaCalibrationAndSmearingTool->setProperty("ESModel", "es2012c"));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_EgammaCalibrationAndSmearingTool->setProperty("ResolutionType", "SigmaEff90"));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_EgammaCalibrationAndSmearingTool->initialize());

  // efficiency tool loose
  //-----------------
  m_effToolVeryLooseLH = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_VeryLooseLH");
  m_effToolVeryLooseLH->msg().setLevel( m_msgLevel );
  std::vector< std::string > correctionFileNameListLoose;
  if (is8TeV) {
    correctionFileNameListLoose.push_back("ElectronEfficiencyCorrection/efficiencySF.offline.VeryLooseLLH.2012.8TeV.rel17p2.v07.root");
    //    efficiencySF.offline.LooseLLH.2012.8TeV.rel17p2.GEO21.v01.root
    //    efficiencySF.offline.LooseLLH.2012.8TeV.rel17p2.v07.root
  } else {
    // TODO no VeryLooseLLH for 13 TeV?
    correctionFileNameListLoose.push_back("ElectronEfficiencyCorrection/efficiencySF.offline.LooseLLH.2015.13TeV.rel19.GEO21.v01.root");
  }
  TOOL_CHECK("ElectronHandler::initializeTools()", m_effToolVeryLooseLH->setProperty("CorrectionFileNameList", correctionFileNameListLoose));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_effToolVeryLooseLH->setProperty("ForceDataType", dataType));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_effToolVeryLooseLH->initialize());
  
  // efficiency tool loose
  //-----------------
  m_effToolVeryTightLH = new AsgElectronEfficiencyCorrectionTool("AsgElectronEfficiencyCorrectionTool_VeryTightLH");
  m_effToolVeryTightLH->msg().setLevel( m_msgLevel );
  std::vector< std::string > correctionFileNameListTight;
  if (is8TeV) {
    correctionFileNameListTight.push_back("ElectronEfficiencyCorrection/efficiencySF.offline.VeryTightLLH.2012.8TeV.rel17p2.v07.root");
    //    efficiencySF.offline.VeryTightLLH.2012.8TeV.rel17p2.GEO21.v01.root
  } else {
    correctionFileNameListTight.push_back("ElectronEfficiencyCorrection/efficiencySF.offline.VeryTightLLH.2015.13TeV.rel19.GEO21.v01.root");
  }
  TOOL_CHECK("ElectronHandler::initializeTools()", m_effToolVeryTightLH->setProperty("CorrectionFileNameList", correctionFileNameListTight));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_effToolVeryTightLH->setProperty("ForceDataType", dataType));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_effToolVeryTightLH->initialize());
  
  //LH selector tools
  //-----------------
  m_checkVeryLooseLH = new AsgElectronLikelihoodTool("checkVeryLooseLH");
  m_checkVeryLooseLH->msg().setLevel( m_msgLevel );
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryLooseLH->setProperty("primaryVertexContainer", "PrimaryVertices"));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryLooseLH->setProperty("OperatingPoint", static_cast<unsigned int> (LikeEnum::VeryLoose)));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryLooseLH->setProperty("inputPDFFileName", "ElectronPhotonSelectorTools/v1/ElectronLikelihoodPdfs.root"));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryLooseLH->initialize());
  //VeryTightLH
  m_checkVeryTightLH = new AsgElectronLikelihoodTool("checkVeryTightLH");
  m_checkVeryTightLH->msg().setLevel( m_msgLevel );
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryTightLH->setProperty("primaryVertexContainer", "PrimaryVertices"));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryTightLH->setProperty("OperatingPoint", static_cast<unsigned int> (LikeEnum::VeryTight)));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryTightLH->setProperty("inputPDFFileName", "ElectronPhotonSelectorTools/v1/ElectronLikelihoodPdfs.root"));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_checkVeryTightLH->initialize());

  //isEM selector tool
  //-----------------
  m_ElectronIsEMSelector = new AsgElectronIsEMSelector("ElectronIsEMSelector");
  m_ElectronIsEMSelector->msg().setLevel( m_msgLevel );
  TOOL_CHECK("ElectronHandler::initializeTools()", m_ElectronIsEMSelector->setProperty("ConfigFile", "ElectronPhotonSelectorTools/v1/ElectronIsEMLooseSelectorCutDefs.conf"));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_ElectronIsEMSelector->setProperty("isEMMask", static_cast<unsigned int> (egammaPID::ElectronTightPP)));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_ElectronIsEMSelector->setProperty("PIDName", static_cast<int> (egammaPID::IsEMTight)));
  TOOL_CHECK("ElectronHandler::initializeTools()", m_ElectronIsEMSelector->initialize());
  
  // register ISystematicsTools
  //---------------------------
  m_sysToolList.clear();
  m_sysToolList.push_back(m_EgammaCalibrationAndSmearingTool);
  m_sysToolList.push_back(m_effToolVeryLooseLH);
  m_sysToolList.push_back(m_effToolVeryTightLH);

  return EL::StatusCode::SUCCESS;
}


EL::StatusCode ElectronHandler::decorate(xAOD::Electron * electron) 
{

  //selection tools
  //---------------
  //retrieve decision from tools and decorate electron with it
  //perform actual selection later
  int isVeryLooseLH = static_cast<int>(m_checkVeryLooseLH->accept(electron));
  int isVeryTightLH = static_cast<int>(m_checkVeryTightLH->accept(electron));
  int isTightPP     = static_cast<int>(m_ElectronIsEMSelector->accept(electron));
  m_decorator.set(electron, ElecIntProps::isVeryLooseLH, isVeryLooseLH);
  m_decorator.set(electron, ElecIntProps::isVeryTightLH, isVeryTightLH);
  m_decorator.set(electron, ElecIntProps::isTightPP, isTightPP);
  
  
  // get SFs from electron SF tool
  //--------------------------
  int isMC = m_eventInfoHandler.get_isMC();
  double effSFloose = 1.;
  double effSFtight = 1.;

  // TODO remove range cuts, but tool prints error message currently
  // http://acode-browser.usatlas.bnl.gov/lxr/source/atlas/PhysicsAnalysis/ElectronPhotonID/ElectronEfficiencyCorrection/Root/AsgElectronEfficiencyCorrectionTool.cxx

  const xAOD::CaloCluster* cluster = electron->caloCluster();
  float cluster_eta = 10;
  float cluster_et = 0;
  if (cluster) {
    cluster_eta = cluster->eta();
    if (cluster_eta != 0.0) {
      cluster_et = cluster->e() / cosh(cluster_eta);
    }
  }
  
  if (isMC && cluster_et >= 7000. && fabs(cluster_eta) < 2.47) {
    if (m_effToolVeryLooseLH->getEfficiencyScaleFactor(*electron, effSFloose) == CP::CorrectionCode::Error) {
      Error("ElectronHandler::decorate()", "ElectronEfficiencyCorrection returned CP::CorrectionCode::Error");
      return EL::StatusCode::FAILURE;
    }
    if (m_effToolVeryTightLH->getEfficiencyScaleFactor(*electron, effSFtight) == CP::CorrectionCode::Error) {
      Error("ElectronHandler::decorate()", "ElectronEfficiencyCorrection returned CP::CorrectionCode::Error");
      return EL::StatusCode::FAILURE;
    }
  }
  m_decorator.set(electron, ElecFloatProps::effSFloose, effSFloose);
  m_decorator.set(electron, ElecFloatProps::effSFtight, effSFtight);
  
  return EL::StatusCode::SUCCESS;  

}


EL::StatusCode ElectronHandler::calibrateCopies(xAOD::ElectronContainer * particles, const CP::SystematicSet & sysSet) 
{

  //calibration tool
  //-----------------
  // tell tool to apply systematic variation
  CP_CHECK("ElectronHandler::calibrateCopies()",m_EgammaCalibrationAndSmearingTool->applySystematicVariation(sysSet),m_debug);

  // tell tool to apply systematic variation
  CP_CHECK("ElectronHandler::calibrateCopies()",m_effToolVeryLooseLH->applySystematicVariation(sysSet),m_debug);

  for (xAOD::Electron * electron : *particles) {

    //calibration tool
    //-----------------
    //set seed for smearing
    m_EgammaCalibrationAndSmearingTool->setRandomSeed(m_eventInfoHandler.get_eventNumber() + 100 * electron->index());
    //this ensures that the DynAux container has the same number of entries as the original one
    //not necessary in case of electrons - keep it for consistency?
    //setP4( electron , electron );
    CP_CHECK("ElectronHandler::calibrateCopies()",m_EgammaCalibrationAndSmearingTool->applyCorrection(*electron),m_debug);

    // decorate electron
    if ( decorate( electron ) != EL::StatusCode::SUCCESS ) return EL::StatusCode::FAILURE;
  }

  return EL::StatusCode::SUCCESS;

}


bool ElectronHandler::checkPassSelOR(xAOD::Electron * electron) 
{

  int res = 0;
  m_decorator.get(electron, ElecIntProps::passORGlob, res);
  return res;

}


bool ElectronHandler::checkPassSelNoOR(xAOD::Electron * electron) 
{

  int res = 0;
  m_decorator.get(electron, ElecIntProps::isVHLooseElectron, res);
  return res;

}


bool ElectronHandler::passVHLooseElectron(xAOD::Electron * electron) 
{

  bool passSel = true;

  //ToDo
  //steer certain cuts by config settings
  //cutflow
  //if (!(electron->author() == xAOD::EgammaParameters::AuthorElectron)) passSel = false; //not needed anymore since forward electrons are stored in a different container
  if (!(m_decorator.get(electron, ElecIntProps::isVeryLooseLH))) passSel = false;
  if (!(fabs(electron->eta()) < 2.47)) passSel = false;
  if (!(electron->pt() > 7000.)) passSel = false;
  //  if (!(electron->isolationValue(xAOD::Iso::ptcone20) / electron->pt() < 0.1)) passSel = false; //just for now until isolation problems are fixed in input!
  if (!(electron->isGoodOQ(xAOD::EgammaParameters::BADCLUSELECTRON))) passSel = false;

  m_decorator.set(electron, ElecIntProps::isVHLooseElectron, passSel);
  m_decorator.set(electron, ElecIntProps::passPreSel, passSel);

  return passSel;

}

bool ElectronHandler::passVHSignalElectron(xAOD::Electron * electron) 
{

  bool passSel = true;
  //ToDo
  //steer certain cuts by config settings
  //cutflow

  if (!m_decorator.get(electron, ElecIntProps::isVHLooseElectron)) passSel = false;
  if (!(electron->pt() > 25000.)) passSel = false;
 
  m_decorator.set(electron, ElecIntProps::isVHSignalElectron, passSel);

  return passSel;

}

bool ElectronHandler::passZHSignalElectron(xAOD::Electron * electron) 
{

  bool passSel = true;
  //ToDo
  //steer certain cuts by config settings
  //cutflow

  if (!m_decorator.get(electron, ElecIntProps::isVHSignalElectron)) passSel = false;
 
  m_decorator.set(electron, ElecIntProps::isZHSignalElectron, passSel);

  return passSel;

}

bool ElectronHandler::passWHSignalElectron(xAOD::Electron * electron) 
{
  bool passSel = true;
  //ToDo
  //steer certain cuts by config settings
  //cutflow

  //require loose electron cuts to be passed - does this make sense?
  //isn't it possible that the VeryLooseLH isn't passed but VeryTight is?
  if (!m_decorator.get(electron, ElecIntProps::isVHSignalElectron)) passSel = false;

  if (!(m_decorator.get(electron, ElecIntProps::isVeryTightLH))) passSel = false;
  //  if (!(electron->isolationValue(xAOD::Iso::ptcone20) / electron->pt() < 0.04)) passSel = false; //just for now until isolation problems are fixed in input!
  //if (!(electron->isolationValue(xAOD::Iso::topoetcone30_corrected) / electron->pt() < 0.04)) passWHSel = false;
  //if (!(electron->isolationValue(xAOD::Iso::topoetcone30) / electron->pt() < 0.04)) passSel = false;//just for now until isolation problems are fixed in input!

  m_decorator.set(electron, ElecIntProps::isWHSignalElectron, passSel);

  return passSel;

}


EL::StatusCode ElectronHandler::setVariables(xAOD::Electron * inElectron, xAOD::Electron * outElectron, bool isKinVar, bool isWeightVar) 
{
  
  if (!isWeightVar ){
    // set four momentum
    setP4( inElectron , outElectron );
    
    //set isolation
    outElectron->setIsolationValue(inElectron->isolationValue(xAOD::Iso::ptcone20),xAOD::Iso::ptcone20);
    //outElectron->setIsolationValue(inElectron->isolationValue(xAOD::Iso::topoetcone30_corrected),xAOD::Iso::topoetcone30_corrected);
    outElectron->setIsolationValue(inElectron->isolationValue(xAOD::Iso::topoetcone30),xAOD::Iso::topoetcone30);
    
    // set something without having a pre-defined method
    m_decorator.copy(inElectron, outElectron, ElecIntProps::isVeryTightLH);
    m_decorator.copy(inElectron, outElectron, ElecIntProps::isVHLooseElectron);
    m_decorator.copy(inElectron, outElectron, ElecIntProps::isZHSignalElectron);
    m_decorator.copy(inElectron, outElectron, ElecIntProps::isWHSignalElectron);
  }

  // SF to be written for nominal and all variations 
  int isMC = m_eventInfoHandler.get_isMC();
  if (isMC) {
    m_decorator.copy(inElectron, outElectron, ElecFloatProps::effSFloose);
    m_decorator.copy(inElectron, outElectron, ElecFloatProps::effSFtight);
  }

  return EL::StatusCode::SUCCESS;

}


EL::StatusCode ElectronHandler::fillOutputContainer() 
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


EL::StatusCode ElectronHandler::clearEvent() 
{
  
  EL_CHECK("ElectronHandler::clearEvent()",ObjectHandler::clearEvent());
  return EL::StatusCode::SUCCESS;

}
