// Dear emacs, this is -*-c++-*-
#ifndef CxAODMaker_TrimmedJetHandler_H
#define CxAODMaker_TrimmedJetHandler_H

#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"

#include "CxAODMaker/ObjectHandler.h"
#include "CxAODTools/FatJetDecorator.h"
#include "xAODHelpers/Helpers.h"
#include "JetSubStructureMomentTools/EnergyCorrelatorRatiosTool.h"

namespace xAOD {
#ifndef XAODJET_JETCONTAINER_H 
  class JetContainer;
#endif
#ifndef XAODJET_JET_H 
  class Jet;
#endif
}

class JetCalibrationTool;
class JetCleaningTool;
class JERTool;
class JERSmearingTool;
class JetUncertaintiesTool;

class TrimmedJetHandler {
  
public:
  
  TrimmedJetHandler(ConfigStore *config, xAOD::TEvent *event = 0, int isMC=0);
  
  ~TrimmedJetHandler();
  
  EL::StatusCode fillOutputContainer();
  EL::StatusCode clearEvent();
  
  std::string m_inputTrimmedJetCont;
  std::string m_outTrimmedJetCont;
  std::string m_inputSmallJetCont;
  
  EL::StatusCode setTrimmedJets();
  EL::StatusCode getTrimmedJets();
  
  
  //adding these by hand because it's usually in ObjectHandler.h
  xAOD::TEvent* m_event;
  ConfigStore* m_config;
  std::string m_containerName;
  std::string m_contSysName;
  
private:
  
  bool debug = true;
  
  int m_isMC;
 
  // decorator defining non-standard object variables
  static FatJetDecorator m_decorator;
  EL::StatusCode decorate(xAOD::Jet * jet);
  EL::StatusCode EnergyCorrelations(xAOD::Jet * jet);
  EL::StatusCode NSubjettinessRatios(xAOD::Jet * jet);

  xAOD::JetContainer* m_trimmedjetContainer;
  xAOD::JetAuxContainer* m_trimmedjetContainerAux;
  const xAOD::JetContainer* akt10jets;
  const xAOD::JetContainer* akt4jets;
  EnergyCorrelatorRatiosTool* m_EnergyCorrelatorRatiosTool;

};
#endif
