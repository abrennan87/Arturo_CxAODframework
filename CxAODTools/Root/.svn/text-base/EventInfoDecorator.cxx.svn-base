#include "CxAODTools/EventInfoDecorator.h"

template <>
EventInfoDecorator::MapCharDec ObjectDecorator<EventInfoCharProps, EventInfoIntProps, EventInfoFloatProps>::m_charDecs = {};

template <>
EventInfoDecorator::MapCharAcc ObjectDecorator<EventInfoCharProps, EventInfoIntProps, EventInfoFloatProps>::m_charAccs = {};

template <>
EventInfoDecorator::MapIntDec ObjectDecorator<EventInfoCharProps, EventInfoIntProps, EventInfoFloatProps>::m_intDecs = {};

template <>
EventInfoDecorator::MapIntAcc ObjectDecorator<EventInfoCharProps, EventInfoIntProps, EventInfoFloatProps>::m_intAccs = {};

template <>
EventInfoDecorator::MapFloatDec ObjectDecorator<EventInfoCharProps, EventInfoIntProps, EventInfoFloatProps>::m_floatDecs = {};

template <>
EventInfoDecorator::MapFloatAcc ObjectDecorator<EventInfoCharProps, EventInfoIntProps, EventInfoFloatProps>::m_floatAccs = {};

EventInfoDecorator::EventInfoDecorator() {

  m_charPropNames = {
    {EventInfoCharProps::None, "None"}
  };

  m_intPropNames = {
    {EventInfoIntProps::TTLH_presel, "TTLH_presel"},
    {EventInfoIntProps::TTLH_dilepcr, "TTLH_dilepcr"},
    {EventInfoIntProps::TTLH_isvbf, "TTLH_isvbf"},
    {EventInfoIntProps::TTLH_isboost, "TTLH_isboost"},
    {EventInfoIntProps::TTLH_os, "TTLH_os"},
    {EventInfoIntProps::TTLH_iselhad, "TTLH_iselhad"},
    {EventInfoIntProps::TTLH_hasbtag, "TTLH_hasbtag"},
    {EventInfoIntProps::isMC, "isMC"},
    {EventInfoIntProps::NVtx3Trks, "NVtx3Trks"},
    {EventInfoIntProps::hasPV, "hasPV"},
    {EventInfoIntProps::passGRL, "passGRL"},
    {EventInfoIntProps::isCleanEvent, "isCleanEvent"},
    {EventInfoIntProps::TTLH_njets, "TTLH_njets"},
    {EventInfoIntProps::TriggerStream, "TriggerStream"},
    {EventInfoIntProps::passTrigger, "passTrigger"},
    {EventInfoIntProps::passHLT_xe100            , "passHLT_xe100"},		
    {EventInfoIntProps::passHLT_e28_tight_iloose , "passHLT_e28_tight_iloose"}, 	
    {EventInfoIntProps::passHLT_e60_medium1      , "passHLT_e60_medium1"}, 	
    {EventInfoIntProps::passHLT_2e17_loose1      , "passHLT_2e17_loose1"}, 	
    {EventInfoIntProps::passHLT_mu26_imedium     , "passHLT_mu26_imedium"}, 	
    {EventInfoIntProps::passHLT_mu50 	         , "passHLT_mu50"}, 		
    {EventInfoIntProps::passHLT_2mu14            , "passHLT_2mu14"},                  
    
  };

  m_floatPropNames = {
    {EventInfoFloatProps::MCEventWeight, "MCEventWeight"},
    {EventInfoFloatProps::Pileupweight, "Pileupweight"},
    {EventInfoFloatProps::ZPV, "zPV"},
    {EventInfoFloatProps::leptonSF, "leptonSF"},
    {EventInfoFloatProps::TTLH_globalweight, "TTLH_globalweight"},
    {EventInfoFloatProps::TTLH_btaggingweight, "TTLH_btaggingweight"},
    {EventInfoFloatProps::TTLH_MMC, "TTLH_MMC"},
    {EventInfoFloatProps::TTLH_mT, "TTLH_mT"},
    {EventInfoFloatProps::TTLH_mvis, "TTLH_mvis"},
    {EventInfoFloatProps::TTLH_detajj, "TTLH_detajj"},
    {EventInfoFloatProps::TTLH_drleptau, "TTLH_drleptau"},
    {EventInfoFloatProps::TTLH_ptH, "TTLH_ptH"},
    {EventInfoFloatProps::TTLH_pttot,"TTLH_pttot"},
    {EventInfoFloatProps::TTLH_ptl_over_pttau,"TTLH_ptl_over_pttau"},
    {EventInfoFloatProps::TTLH_lep_eta_cent,"TTLH_lep_eta_cent"},
    {EventInfoFloatProps::TTLH_met_phi_cent,"TTLH_met_phi_cent"},
    {EventInfoFloatProps::TTLH_sumpt, "TTLH_sumpt"},
    {EventInfoFloatProps::TTLH_mjj,"TTLH_mjj"},
    {EventInfoFloatProps::TTLH_jet_cent,"TTLH_jet_cent"},
    {EventInfoFloatProps::TTLH_tau_x1,"TTLH_tau_x1"},
    {EventInfoFloatProps::TTLH_lep_x2,"TTLH_lep_x2"},
    {EventInfoFloatProps::TTLH_sumdphi,"TTLH_sumdphi"}
  };
}

