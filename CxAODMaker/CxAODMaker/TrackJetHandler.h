// Dear emacs, this is -*-c++-*-
#ifndef CxAODMaker_TrackJetHandler_H
#define CxAODMaker_TrackJetHandler_H

#include "CxAODMaker/ObjectHandler.h"
#include "CxAODTools/TrackJetDecorator.h"

namespace xAOD {
#ifndef XAODJET_JETCONTAINER_H 
  class JetContainer;
#endif
#ifndef XAODJET_JET_H 
  class Jet;
#endif
}


class TrackJetHandler : public ObjectHandler<xAOD::Jet,xAOD::JetContainer> {

public:

  TrackJetHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
                EventInfoHandler & eventInfoHandler);

  ~TrackJetHandler();

  EL::StatusCode initializeTools();
  EL::StatusCode fillOutputContainer();
  EL::StatusCode clearEvent();  

  void setP4(const xAOD::Jet * in, xAOD::Jet * out) { out->setJetP4( in->jetP4() ); }
  
private:

  // decorator defining non-standard object variables
  static TrackJetDecorator m_decorator;

  bool m_isMC;

  xAOD::JetContainer* m_Kt4Ztrkjets;
  xAOD::JetAuxContainer* m_Kt4ZtrkjetsAux;
  // selection functions for single objects
  static bool checkPassSel(xAOD::Jet * part);
  
  static bool passTrackJet(xAOD::Jet* jet);

  EL::StatusCode decorate(xAOD::Jet * jet);

  EL::StatusCode calibrateCopies(xAOD::JetContainer * particles, const CP::SystematicSet & sysSet);
  
  virtual EL::StatusCode setVariables(xAOD::Jet * inPart, xAOD::Jet * outPart, bool isKinVar, bool isWeightVar);

};

#endif
