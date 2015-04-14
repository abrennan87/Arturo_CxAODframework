// Dear emacs, this is -*-c++-*-

#ifndef CxAODMaker_METHandler_H
#define CxAODMaker_METHandler_H

#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"


#ifndef __MAKECINT__
#include "METInterface/IMETRebuilder.h"
#include "xAODMissingET/MissingETContainer.h"	
#include "xAODMissingET/MissingETAuxContainer.h"
#include "xAODMissingET/MissingETComposition.h"
#endif

#include "METUtilities/METRebuilder.h"
#include "CxAODMaker/ObjectHandler.h"

class IMETRebuilder;


namespace xAOD {
#ifndef XAODMUON_MUON_H 
  class Muon;
#endif
}

class METHandler {
public:

  METHandler(ConfigStore *config, xAOD::TEvent *event = 0, int isMC=0);
  
  ~METHandler();

//  EL::StatusCode select();
  EL::StatusCode fillOutputContainer();
  EL::StatusCode clearEvent();
  //  EL::StatusCode setMET();
  //EL::StatusCode setMET(const xAOD::ElectronContainer* elec,
  ////		        const xAOD::PhotonContainer* gamma,
  ////		        const xAOD::TauJetContainer* taujet,
  //			const xAOD::MuonContainer* muon,
  //			const xAOD::JetContainer* jet);


  std::string m_eleTerm;
  std::string m_gammaTerm;
  std::string m_tauTerm;
  std::string m_jetTerm;
  std::string m_muonTerm;
  std::string m_softTerm;
  std::string m_inputMap;
  std::string m_inputMETCont;
  std::string m_outMETTerm;

  std::string m_inputMETTrackCont;

  EL::StatusCode setMET(std::map<TString, xAOD::ElectronContainer*>* elec,
			std::map<TString, xAOD::PhotonContainer*>* gamma,
			std::map<TString, xAOD::TauJetContainer*>* taujet,
			std::map<TString, xAOD::MuonContainer*>* muon,
			std::map<TString, xAOD::JetContainer*>* jet);
  

  //adding these by hand because it's usually in ObjectHandler.h
  xAOD::TEvent* m_event;
  ConfigStore* m_config;
  std::string m_containerName;
  std::string m_contSysName;



  // FIXME we need to have a way to access MET frmo elsewhere in CxAODMaker
  // This function may be temporary though, as the final API of this class may change when
  // MET rebuilding and systematics work
  xAOD::MissingET* getMET();
  void printMET(const xAOD::MissingETContainer* METCont);

  xAOD::MissingET* getMETTrack();

private:

  bool debug = true;

  int m_isMC;

  //  // decorator defining non-standard object variables
  //  static METDecorator m_decorator;

  // MET utilities tool
  //ToolHandle<IMETRebuilder> m_metutil;//!
  //met::METRebuilder* m_metutil;
  met::METRebuilder* m_metutil;//!

  xAOD::MissingETContainer* m_METContainer;
  xAOD::MissingETAuxContainer* m_METContainerAux;

  xAOD::MissingETContainer* m_TruthMETContainer;
  xAOD::MissingETAuxContainer* m_TruthMETContainerAux;

  xAOD::MissingETContainer* m_METTrackContainer;

  // selection functions for single objects

  //EL::StatusCode calibrateCopies(
  //        xAOD::METContainer* particles,
  //        const CP::SystematicSet &sysSet);



  /** @brief Sets certain variables for the outMET.
    * @param inMET MET from m_inContainer, from which values are read.
    * @param outMET MET from m_outContainer for which values are set.
    * @param isSysVar Bool deciding if container holding outMET is a shallow copy.
    *
    *Called in function copyContainer that is implemented in the ObjectHandler.
    *In case isSysVar is true, variation dependent object variables are overwritten.
   */
  //virtual EL::StatusCode setVariables(xAOD::MET* inMET, xAOD::MET* outMET, bool isSysVar);
};
#endif

