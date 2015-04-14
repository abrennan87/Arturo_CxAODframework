#ifndef XAODANAHELPERS_OVERLAPREMOVER_H
#define XAODANAHELPERS_OVERLAPREMOVER_H

#include <EventLoop/Algorithm.h>

// Infrastructure include(s):
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/TStore.h"

// EDM include(s):
#ifndef __CINT__
  #include "xAODBase/IParticleHelpers.h"
  #include "xAODBase/IParticleContainer.h"
  #include "xAODBase/IParticle.h"
  #include "xAODEgamma/ElectronContainer.h"
  #include "xAODMuon/MuonContainer.h"
  #include "xAODJet/JetContainer.h"
  #include "xAODEgamma/PhotonContainer.h"
  #include "xAODTau/TauJetContainer.h"
#endif

class OverlapRemovalTool;

class OverlapRemover : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:

  xAOD::TEvent *m_event;  //!
  xAOD::TStore *m_store;  //!
  int m_numEvent;         //!
  int m_numObject;        //!
  int m_numEventPass;     //!
  int m_weightNumEventPass; //!
  int m_numObjectPass;    //!

  std::string m_name;
  std::string m_configName;
  bool m_debug;

private:

#ifndef __CINT__
  // tools
  OverlapRemovalTool *m_overlapRemovalTool; //!
#endif

  // configuration variables

  bool     m_decorateSelectedObjects;  // decorate selected objects? default passSel
  bool     m_createSelectedContainers; // fill using SG::VIEW_ELEMENTS to be light weight

  bool     m_useSelected; // pass only object passing selection to O.R. tool

  /* Electrons */
  std::string m_inContainerName_Electrons;
  std::string  m_outContainerName_Electrons;        // output container name
  std::string  m_outAuxContainerName_Electrons;     // output auxiliary container name
  /* Muons */
  std::string m_inContainerName_Muons;
  std::string  m_outContainerName_Muons;        // output container name
  std::string  m_outAuxContainerName_Muons;     // output auxiliary container name
  /* Jets */
  std::string m_inContainerName_Jets;
  std::string  m_outContainerName_Jets;        // output container name
  std::string  m_outAuxContainerName_Jets;     // output auxiliary container name
  /* Photons */
  std::string m_inContainerName_Photons;
  std::string  m_outContainerName_Photons;        // output container name
  std::string  m_outAuxContainerName_Photons;     // output auxiliary container name
  /* Taus */
  std::string m_inContainerName_Taus;
  std::string  m_outContainerName_Taus;        // output container name
  std::string  m_outAuxContainerName_Taus;     // output auxiliary container name


  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!


  // this is a standard constructor
  OverlapRemover ();
  OverlapRemover (std::string name, std::string configName);

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  // these are the functions not inherited from Algorithm
  virtual EL::StatusCode configure ();
#ifndef __CINT__
  virtual EL::StatusCode executeConst(const xAOD::ElectronContainer* inElectrons,
				      const xAOD::MuonContainer* inMuons,
				      const xAOD::JetContainer* inJets,
			              const xAOD::TauJetContainer* inTaus,
				      const xAOD::PhotonContainer* inPhotons);
#endif
#ifndef __CINT__
  virtual EL::StatusCode printOverlapInfo (const char* type, const xAOD::IParticleContainer* objCont, const std::string& selectFlag, const std::string& overlapFlag);
  virtual EL::StatusCode printOverlapInfo (const char* type, xAOD::IParticle* obj, const std::string& selectFlag, const std::string& overlapFlag);
#endif

  // this is needed to distribute the algorithm to the workers
  ClassDef(OverlapRemover, 1);
};

#endif
