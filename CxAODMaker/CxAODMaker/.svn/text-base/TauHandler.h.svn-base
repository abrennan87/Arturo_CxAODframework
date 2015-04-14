// Dear emacs, this is -*-c++-*-

#ifndef CxAODMaker_TauHandler_H
#define CxAODMaker_TauHandler_H

#include "CxAODMaker/ObjectHandler.h"
#include "CxAODTools/TauDecorator.h"
#include "CxAODMaker/TruthParticleHandler.h"
#include <vector>

namespace xAOD {
#ifndef XAODTAU_TAUJETCONTAINER_H 
  class TauJetContainer;
#endif
#ifndef XAODTAU_TAUJET_H 
  class TauJet;
#endif
#ifndef XAODTRUTH_TRUTHPARTICLE_H 
  class TruthParticle;
#endif
}

namespace TauAnalysisTools {
  class TauSmearingTool;
  class TauSelectionTool;
  class TauEfficiencyCorrectionsTool;
}

class TauHandler : public ObjectHandler<xAOD::TauJet,xAOD::TauJetContainer> {

public:

  TauHandler(const std::string& name, ConfigStore & config, xAOD::TEvent * event,
              EventInfoHandler & eventInfoHandler);
  
  virtual ~TauHandler();
  
  virtual EL::StatusCode initializeTools();
  virtual EL::StatusCode fillOutputContainer();
  virtual EL::StatusCode clearEvent();
  virtual void setTruthHandler(TruthParticleHandler* truthhandler ) { m_truthhandler=truthhandler; }
  
  // Setting tau mass to 0 for now as it was done in Run 1
  void setP4(const xAOD::TauJet * in, xAOD::TauJet * out) { out->setP4(in->pt(), in->eta(), in->phi(), 0); }


protected:
  
  // decorator defining non-standard object variables
  static TauDecorator m_decorator;
  TauAnalysisTools::TauSmearingTool * m_tauSmearingTool;
  TauAnalysisTools::TauSelectionTool  * m_tauSelectionTool;
  TauAnalysisTools::TauEfficiencyCorrectionsTool * m_tauEfficiencyCorrections;
  TauAnalysisTools::TauEfficiencyCorrectionsTool * m_tauEfficiencyCorrections_eveto;
  // calibration tools

  // selection functions for single objects
  static bool LooseTau(xAOD::TauJet * part);
  static bool checkPassSel(xAOD::TauJet * part);


  virtual EL::StatusCode decorate(xAOD::TauJet * tau); 
  
  virtual EL::StatusCode calibrateCopies(xAOD::TauJetContainer * particles, const CP::SystematicSet & sysSet);

  /** @brief Sets certain variables for the outTau.
    * @param inTau Tau from m_inContainer, from which values are read.
    * @param outTau Tau from m_outContainer for which values are set.
    * @param isSysVar Bool deciding if container holding outTau is a shallow copy.
    *
    *Called in function copyContainer that is implemented in the ObjectHandler.
    *In case isSysVar is true, variation dependent object variables are overwritten.
   */
  virtual EL::StatusCode setVariables(xAOD::TauJet * inTau, xAOD::TauJet * outTau, bool isKinVar, bool isWeightVar);
  
  TruthParticleHandler* m_truthhandler;
  EL::StatusCode TruthMatch(xAOD::TauJet * tau);
  EL::StatusCode FindTrueTaus();
  bool m_SearchedTrueTaus;
  std::vector<xAOD::TruthParticle*> m_truetaus_had;
  std::vector<xAOD::TruthParticle*> m_truetaus_lep;
  std::vector<xAOD::TruthParticle*> m_trueeles;
  std::vector<xAOD::TruthParticle*> m_truemuons;
  std::vector<xAOD::TruthParticle*> m_truepartons;
};

#endif

