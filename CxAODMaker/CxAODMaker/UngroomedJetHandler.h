// Dear emacs, this is -*-c++-*-
#ifndef CxAODMaker_UngroomedJetHandler_H
#define CxAODMaker_UngroomedJetHandler_H

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


class UngroomedJetHandler : public ObjectHandler<xAOD::Jet,xAOD::JetContainer> {
  
public:
  
  UngroomedJetHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
		      EventInfoHandler & eventInfoHandler);
  
  ~UngroomedJetHandler();
  
  bool doRebuild = false;

  EL::StatusCode initializeTools();
  EL::StatusCode fillOutputContainer();
  EL::StatusCode clearEvent();  
  
  void setP4(const xAOD::Jet * in, xAOD::Jet * out) { out->setJetP4( in->jetP4() ); }
  
private:
  
  // decorator defining non-standard object variables
  static FatJetDecorator m_decorator;
  
  bool m_isMC;
  
  xAOD::JetContainer* m_Xungroomedjets, * m_Xungroomedgrmjets;
  xAOD::JetAuxContainer* m_XungroomedjetsAux, * m_XungroomedgrmjetsAux;
  
  xAODHelpers::Helpers helpers;
  
  EnergyCorrelatorRatiosTool* m_EnergyCorrelatorRatiosTool;
  
  // selection functions for single objects
  static bool checkPassSel(xAOD::Jet * part);
  
  static bool passUngroomedJet(xAOD::Jet* jet);
  
  EL::StatusCode decorate(xAOD::Jet * jet);
  
  EL::StatusCode calibrateCopies(xAOD::JetContainer * particles, const CP::SystematicSet & sysSet);
  
  virtual EL::StatusCode setVariables(xAOD::Jet * inPart, xAOD::Jet * outPart, bool isKinVar, bool isWeightVar);
  
};

#endif
