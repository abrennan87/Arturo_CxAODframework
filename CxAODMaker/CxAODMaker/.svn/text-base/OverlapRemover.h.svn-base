#ifndef CxAODMaker_OverlapRemover_H
#define CxAODMaker_OverlapRemover_H

#include "EventLoop/StatusCode.h"

#include "CxAODTools/ConfigStore.h"
#include "CxAODTools/SuperDecorator.h"
#include "CxAODTools/OverlapRemoval.h"

#include "CxAODMaker/ElectronHandler.h"
#include "CxAODMaker/PhotonHandler.h"
#include "CxAODMaker/MuonHandler.h"
#include "CxAODMaker/JetHandler.h"
#include "CxAODMaker/TauHandler.h"

#include <map>


class OverlapRemover {

protected:

  ConfigStore & m_config;
  bool m_debug;

  JetHandler      * m_jets;
  MuonHandler     * m_muons;
  TauHandler     * m_taus;
  ElectronHandler * m_electrons;
  PhotonHandler   * m_photons;
  SuperDecorator m_decorator;

  OverlapRemoval* m_OR;

public:

  OverlapRemover(ConfigStore & config);

  virtual ~OverlapRemover();
  
  virtual void setOverlapRemoval(OverlapRemoval* OR) { m_OR = OR; }

  virtual void setJets(JetHandler* jets) { m_jets = jets; }

  virtual void setMuons(MuonHandler* muons) { m_muons = muons; }

  virtual void setElectrons(ElectronHandler* electrons) { m_electrons = electrons; }

  virtual void setPhotons(PhotonHandler* photons) { m_photons = photons; }

  virtual void setTaus(TauHandler* taus) { m_taus = taus; }

  virtual EL::StatusCode removeOverlap(const TString& sysName);

};

#endif
