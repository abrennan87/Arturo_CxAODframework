#ifndef CxAODMaker_EventSelector_H
#define CxAODMaker_EventSelector_H

// infrastructure includes
#include "PATInterfaces/SystematicRegistry.h"
#include "PATInterfaces/ISystematicsTool.h"
#include "EventLoop/StatusCode.h"

#include "xAODRootAccess/TEvent.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODMissingET/MissingETContainer.h"	

#include "CxAODMaker/OverlapRemover.h"

#include "CxAODTools/ConfigStore.h"
#include "CxAODTools/SuperDecorator.h"
#include "CxAODTools/EventSelection.h"

#include "CxAODMaker/ElectronHandler.h"
#include "CxAODMaker/PhotonHandler.h"
#include "CxAODMaker/MuonHandler.h"
#include "CxAODMaker/TauHandler.h"
#include "CxAODMaker/JetHandler.h"
#include "CxAODMaker/FatJetHandler.h"
#include "CxAODMaker/TrackJetHandler.h"
#include "CxAODMaker/EventInfoHandler.h"
#include "CxAODMaker/METHandler.h"
#include "CxAODMaker/UngroomedJetHandler.h"
#include "CxAODMaker/GroomedJetHandler.h"
#include "CxAODMaker/TrimmedJetHandler.h"

#include <set>
#include <vector>

class ObjectHandlerBase;

class EventSelector {

protected:

  ConfigStore & m_config;
  bool m_debug;

  JetHandler* m_jets;
  FatJetHandler* m_fatjets;
  TrackJetHandler* m_trackjets;
  UngroomedJetHandler* m_ungroomedjets;
  GroomedJetHandler* m_groomedjets;
  TrimmedJetHandler* m_trimmedjets;
  MuonHandler* m_muons;
  TauHandler* m_taus;
  ElectronHandler* m_electrons;
  PhotonHandler* m_photons;
  METHandler* m_met;
  EventInfoHandler* m_info;

  std::vector<std::string> m_weightVariations;
  bool m_doOR;
  OverlapRemover* m_OR;
  EventSelection* m_selection;

  // can use TString? == operator not defined?
  std::set<std::string> m_systematics;

  bool m_isFirstCall;

  virtual EL::StatusCode fillSystematics();

  virtual EL::StatusCode fillSystematics(ObjectHandlerBase* obj);

  virtual bool performSelection(const TString& sysName);

  virtual bool passORandPreSel(const TString& sysName);

public:

  EventSelector() = delete;

  EventSelector(ConfigStore & config);

  virtual ~EventSelector();
  
  virtual void setOverlapRemoval(OverlapRemoval* OR);

  virtual void setJets(JetHandler* jets);

  virtual void setFatJets(FatJetHandler* jets);

  virtual void setTrackJets(TrackJetHandler* jets);

  virtual void setUngroomedJets(UngroomedJetHandler* jets);

  virtual void setGroomedJets(GroomedJetHandler* jets);

  virtual void setTrimmedJets(TrimmedJetHandler* jets);

  virtual void setMuons(MuonHandler* muons);

  virtual void setTaus(TauHandler* taus);

  virtual void setElectrons(ElectronHandler* electrons);

  virtual void setPhotons(PhotonHandler* photons);

  virtual void setMET(METHandler* met) { m_met = met; }

  virtual void setEventInfo(EventInfoHandler* info) { m_info = info; }

  /**
   * @brief Set the event selection to apply
   *
   * @c this becomes the owner of the EventSelection object !
   *
   * @param[in] selection	The event selection to apply
   */
  virtual void setSelection(EventSelection* selection) { m_selection = selection; }

  virtual EL::StatusCode performSelection(bool& pass);

};

#endif
