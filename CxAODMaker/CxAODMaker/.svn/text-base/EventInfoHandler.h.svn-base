// Dear emacs, this is -*-c++-*-
#ifndef CxAODMaker_EventInfoHandler_H
#define CxAODMaker_EventInfoHandler_H

// Framework includes
#ifndef __MAKECINT__

#include "CxAODTools/EventInfoDecorator.h"
#include "xAODCore/AuxContainerBase.h"
#include "xAODCore/AuxInfoBase.h"
#include "xAODCore/ShallowCopy.h"
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include "PileupReweighting/PileupReweightingTool.h"
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#endif // not __MAKECINT__


#include "xAODEventInfo/EventInfo.h"


// Forward declarations
class ConfigStore;

class EventInfoHandler {

public:

  EventInfoHandler(ConfigStore & config, xAOD::TEvent * event);

  virtual ~EventInfoHandler();

  // initialize tools and stuff
  virtual EL::StatusCode initialize();
  // add systematic variations that affect the event info
  virtual EL::StatusCode addVariations(const std::vector<TString> &variations);
  // read the info from the event
  virtual EL::StatusCode executeEvent();
  // initialize output container for all variations
  // a preceeding call of executeEvent() is required
  virtual EL::StatusCode setOutputContainer();
  // fill/record output container
  virtual EL::StatusCode fillOutputContainer();
  
  // get info
  int   get_runNumber()       { return m_eventInfoIn->runNumber()                                                           ; }
  int   get_eventNumber()     { return m_eventInfoIn->eventNumber()                                                         ; }
  int   get_mcEventNumber()   { return m_isMC ? m_eventInfoIn->mcEventNumber()                                      : -1    ; }
  int   get_mcChannelNumber() { return m_isMC ? m_eventInfoIn->mcChannelNumber()                                    : -1    ; }
  float get_MCEventWeight()   { return m_isMC ? m_decorator.get(m_eventInfoIn, EventInfoFloatProps::MCEventWeight)  : -999. ; }
  float get_Pileupweight()    { return m_isMC ? m_decorator.get(m_eventInfoIn, EventInfoFloatProps::Pileupweight)   : -999. ; }
  float get_ZPV()             { return m_decorator.get(m_eventInfoIn, EventInfoFloatProps::ZPV)                             ; }
  float get_indexPV()         { return m_indexPV                                                                            ; }
  int   get_NVtx3Trks()       { return m_decorator.get(m_eventInfoIn, EventInfoIntProps::NVtx3Trks)                         ; }
  int   get_isMC()            { return m_isMC                                                                               ; }
  int   get_RandomRunNumber() { return m_pileupreweighting.GetRandomRunNumber(m_eventInfoIn->runNumber())                   ; }
  int   get_is8TeV()      { return m_is8TeV                                                                       ; }

  int   get_TriggerStream()   { return m_triggerStream                                                                      ; }

  void  set_TriggerStream(int triggerStream)   { m_triggerStream = triggerStream; }

  // get input event info with full info
  const xAOD::EventInfo * getEventInfo() const { return m_eventInfoIn; }

  // get output event info variation (e.g. for writing event variables)
  xAOD::EventInfo * getOutEventInfoVariation(const TString &variation);

  // clean shallow copy
  EL::StatusCode clearEvent();


protected:

  ConfigStore & m_config;

  bool m_debug;
  MSG::Level m_msgLevel;
  std::string m_grl;
  std::vector<std::string> m_triggerList;

  xAOD::TEvent * m_event;

  std::vector<TString> m_variations;
  
  virtual void setVariables(xAOD::EventInfo* eventInfoIn, xAOD::EventInfo* eventInfoOut);

#ifndef __MAKECINT__

  // pointer to the Nominal EventInfo (shallow copy on input)
  xAOD::EventInfo      * m_eventInfoIn; //!

  // maps for all output variations
  std::map<TString, xAOD::EventInfo*> m_eventInfosOut; //!
  
  EventInfoDecorator   m_decorator; //!
  GoodRunsListSelectionTool *m_grlSelectionTool; //!
  CP::PileupReweightingTool m_pileupreweighting;//!
  TrigConf::xAODConfigTool *m_trigConfigTool; //!
  Trig::TrigDecisionTool *m_trigDecTool; //;
  #endif // not __MAKECINT__

  int m_isMC;
  int m_triggerStream;
  int m_indexPV;
  int m_is8TeV;
  
  EL::StatusCode findTrigDecDecorator(std::string triggerName, EventInfoIntProps& trigDecDecorator);
  
};

#endif
