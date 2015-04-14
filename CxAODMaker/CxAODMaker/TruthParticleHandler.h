// Dear emacs, this is -*-c++-*-

#ifndef CxAODMaker_TruthParticleHandler_H
#define CxAODMaker_TruthParticleHandler_H

#include "CxAODMaker/ObjectHandler.h"

// Infra structure includes
#include "xAODTruth/TruthParticleContainer.h"
#include "xAODTruth/TruthVertexContainer.h"

class TruthParticleHandler : public ObjectHandler<xAOD::TruthParticle,xAOD::TruthParticleContainer> {
 
public:

  TruthParticleHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
                       EventInfoHandler & eventInfoHandler);
  
  ~TruthParticleHandler();

  EL::StatusCode setObjects();
  EL::StatusCode fillOutputContainer();
  EL::StatusCode clearEvent();

  void setP4(const xAOD::TruthParticle * in, xAOD::TruthParticle * out) { 
    out->setPx(in->px());
    out->setPy(in->py());
    out->setPz(in->pz());
    out->setE(in->e());
    out->setM(in->m());
  }


protected:

  static bool checkPassSel(xAOD::TruthParticle * part);

  EL::StatusCode decorate(xAOD::TruthParticle * part);

  EL::StatusCode calibrateCopies(xAOD::TruthParticleContainer * particles, const CP::SystematicSet & sysSet);
  
  EL::StatusCode setVariables(xAOD::TruthParticle * inPart, xAOD::TruthParticle * outPart, bool isKinVar, bool isWeightVar);

  virtual EL::StatusCode initializeTools();

  const xAOD::TruthVertexContainer  * m_vtxContainer;

};

#endif
