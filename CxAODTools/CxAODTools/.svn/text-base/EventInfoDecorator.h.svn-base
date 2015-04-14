#ifndef CxAODTools_EventInfoDecorator_H
#define CxAODTools_EventInfoDecorator_H

#include "ObjectDecorator.h"

enum class EventInfoCharProps {
  None
};

enum class EventInfoIntProps {
  TTLH_isvbf,
  TTLH_isboost,
  TTLH_presel,
  TTLH_dilepcr,
  TTLH_os,
  TTLH_hasbtag,
  TTLH_iselhad,
  isMC,
  NVtx3Trks,
  hasPV,
  passGRL,
  isCleanEvent,
  TTLH_njets,
  TriggerStream,
  passTrigger,
  passHLT_xe100,
  passHLT_e28_tight_iloose,
  passHLT_e60_medium1,
  passHLT_2e17_loose1,
  passHLT_mu26_imedium,
  passHLT_mu50,
  passHLT_2mu14
};

enum class EventInfoFloatProps {
  MCEventWeight,
  Pileupweight,
  ZPV,
  leptonSF,
  TTLH_MMC,
  TTLH_mT,
  TTLH_mvis,
  TTLH_drleptau,
  TTLH_ptH,
  TTLH_detajj,
  TTLH_pttot,
  TTLH_ptl_over_pttau,
  TTLH_lep_eta_cent,
  TTLH_met_phi_cent,
  TTLH_sumpt,
  TTLH_mjj,
  TTLH_jet_cent,
  TTLH_tau_x1,
  TTLH_lep_x2,
  TTLH_sumdphi,
  TTLH_globalweight,
  TTLH_btaggingweight
};

class EventInfoDecorator : public ObjectDecorator<EventInfoCharProps, EventInfoIntProps, EventInfoFloatProps>
{

public:
  EventInfoDecorator();
  ~EventInfoDecorator() = default;

};

#endif
