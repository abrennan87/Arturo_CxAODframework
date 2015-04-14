#ifndef CxAODMaker_AnalysisBase_H
#define CxAODMaker_AnalysisBase_H

#include <vector>

#include "EventLoop/Algorithm.h"

// Infrastructure include(s):
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"

#include "CxAODTools/ConfigStore.h"

#include "TH1D.h"

// Forward declarations
class ObjectHandlerBase;
class JetHandler;
class FatJetHandler;
class TrackJetHandler;
class MuonHandler;
class TauHandler;
class ElectronHandler;
class PhotonHandler;
class METHandler;
class EventInfoHandler;
class EventSelector;
class UngroomedJetHandler;
class GroomedJetHandler;
class TrimmedJetHandler;

class AnalysisBase : public EL::Algorithm {

protected:
  
  // vector of all ObjectHandlers, including defaults
  std::vector<ObjectHandlerBase *> m_objectHandler; //!
  
  // default ObjectHandlers used for MET, OR and selection
  JetHandler* m_jetHandler; //!
  FatJetHandler* m_fatjetHandler; //!
  TrackJetHandler* m_trackjetHandler; //!
  MuonHandler* m_muonHandler; //!
  ElectronHandler* m_electronHandler; //!
  PhotonHandler* m_photonHandler; //!
  TauHandler* m_tauHandler; //!
  EventInfoHandler * m_eventInfoHandler; //!
  UngroomedJetHandler * m_ungroomedjetHandler; //!
  GroomedJetHandler * m_groomedjetHandler; //!
  TrimmedJetHandler * m_trimmedjetHandler; //!

  std::vector<TString> m_variations; //!

#ifndef __MAKECINT__
  METHandler* m_METHandler; //!
  EventSelector* m_selector; //!
#endif // not __MAKECINT__
 
  ConfigStore * m_config; //!
  std::string m_configPath; 
  bool m_debug; //!
  bool m_xJets; //!

  // some helper functions
  template <class handlerType>
  handlerType* registerHandler(std::string name);
  void printKnownVariations();
  
  
  // these are called from initialize() in fixed order
  virtual EL::StatusCode initializeEvent();
  virtual EL::StatusCode initializeVariations();
  virtual EL::StatusCode initializeHandlers();
  virtual EL::StatusCode initializeSelector();
  virtual EL::StatusCode initializeTools(bool isMC);
  virtual EL::StatusCode initializeSelection();
  
  
public:
  // Tree *myTree; //!
  // TH1 *myHist; //!
  xAOD::TEvent * m_event; //!
  long m_maxEvent; 
  long m_eventCounter; //!
  double m_eventWeightCounter; //!
  TH1* m_histEventCount; //!
  
  // this is a standard constructor
  AnalysisBase();
  ~AnalysisBase(){};

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob(EL::Job& job);
  virtual EL::StatusCode fileExecute();
  virtual EL::StatusCode histInitialize();
  virtual EL::StatusCode changeInput(bool firstFile);
  virtual EL::StatusCode initialize();
  virtual EL::StatusCode execute();
  virtual EL::StatusCode postExecute();
  virtual EL::StatusCode finalize();
  virtual EL::StatusCode histFinalize();

  void setConfig(std::string configPath) { m_configPath = configPath; }

  // this is needed to distribute the algorithm to the workers
  ClassDef(AnalysisBase, 1);
};

#include "CxAODMaker/AnalysisBase.icc"

#endif
