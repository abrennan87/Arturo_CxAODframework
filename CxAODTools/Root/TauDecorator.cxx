#include "CxAODTools/TauDecorator.h"

template <>
TauDecorator::MapCharDec ObjectDecorator<TauCharProps, TauIntProps, TauFloatProps>::m_charDecs = {};

template <>
TauDecorator::MapCharAcc ObjectDecorator<TauCharProps, TauIntProps, TauFloatProps>::m_charAccs = {};

template <>
TauDecorator::MapIntDec ObjectDecorator<TauCharProps, TauIntProps, TauFloatProps>::m_intDecs = {};

template <>
TauDecorator::MapIntAcc ObjectDecorator<TauCharProps, TauIntProps, TauFloatProps>::m_intAccs = {};

template <>
TauDecorator::MapFloatDec ObjectDecorator<TauCharProps, TauIntProps, TauFloatProps>::m_floatDecs = {};

template <>
TauDecorator::MapFloatAcc ObjectDecorator<TauCharProps, TauIntProps, TauFloatProps>::m_floatAccs = {};



TauDecorator::TauDecorator() {

  m_charPropNames = {
    {TauCharProps::ORInputLabel,"ORInputLabel"},
    {TauCharProps::OROutputLabel,"OROutputLabel"}
  };
  
  m_intPropNames = {
    {TauIntProps::passPreSel,"passPreSel"},
    {TauIntProps::passEvetoEffSel,"passEvetoEffSel"},
    {TauIntProps::partIndex, "partIndex"},
    {TauIntProps::passOR, "passOR"},
    {TauIntProps::passEvetoOR, "passEvetoOR"},
    {TauIntProps::passORGlob, "passORGlob"},
    {TauIntProps::passedIDCuts, "passedIDCuts"},
    {TauIntProps::nTracks, "nTracks"},
    {TauIntProps::nWideTracks, "nWideTracks"},
    {TauIntProps::nPi0PFOs,    "nPi0PFOs"},   //nPi0PFOs, //tau->nPi0_PFOs()
    {TauIntProps::isBDTLoose, "isBDTLoose"},
    {TauIntProps::isBDTMedium, "isBDTMedium"},
    {TauIntProps::isBDTTight, "isBDTTight"},
    {TauIntProps::passLooseTau, "passLooseTau"},
    {TauIntProps::passEvetoLoose, "passEvetoLoose"},
    {TauIntProps::passEvetoMedium, "passEvetoMedium"},
    {TauIntProps::passEvetoTight, "passEvetoTight"},
    {TauIntProps::passTauSelector, "passTauSelector"}, 
    {TauIntProps::TruthMatch, "TruthMatch"}, 
    {TauIntProps::LeptonTruthMatch, "LeptonTruthMatch"}, 
    {TauIntProps::passCandSel, "passCandSel"}
  };

  m_floatPropNames = {
    {TauFloatProps::effSF, "effSF"},
    {TauFloatProps::BDTScore, "BDTScore"},
    {TauFloatProps::EleBDTScore, "EleBDTScore"},
    {TauFloatProps::TrackEta, "TrackEta"},
    {TauFloatProps::charge, "charge"},
    {TauFloatProps::effSFeveto, "effSFeveto"},
  };

}

