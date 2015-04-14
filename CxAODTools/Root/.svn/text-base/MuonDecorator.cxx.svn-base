#include "CxAODTools/MuonDecorator.h"

template <>
MuonDecorator::MapCharDec ObjectDecorator<MuonCharProps, MuonIntProps, MuonFloatProps>::m_charDecs = {};

template <>
MuonDecorator::MapCharAcc ObjectDecorator<MuonCharProps, MuonIntProps, MuonFloatProps>::m_charAccs = {};

template <>
MuonDecorator::MapIntDec ObjectDecorator<MuonCharProps, MuonIntProps, MuonFloatProps>::m_intDecs = {};

template <>
MuonDecorator::MapIntAcc ObjectDecorator<MuonCharProps, MuonIntProps, MuonFloatProps>::m_intAccs = {};

template <>
MuonDecorator::MapFloatDec ObjectDecorator<MuonCharProps, MuonIntProps, MuonFloatProps>::m_floatDecs = {};

template <>
MuonDecorator::MapFloatAcc ObjectDecorator<MuonCharProps, MuonIntProps, MuonFloatProps>::m_floatAccs = {};

MuonDecorator::MuonDecorator() {

  m_charPropNames = {
    {MuonCharProps::ORInputLabel, "ORInputLabel"},
    {MuonCharProps::OROutputLabel, "OROutputLabel"},
  };

  m_intPropNames = {
    {MuonIntProps::passPreSel, "passPreSel"},
    {MuonIntProps::partIndex, "partIndex"},
    {MuonIntProps::passOR, "passOR"},
    {MuonIntProps::passORGlob, "passORGlob"},
    {MuonIntProps::passedIDCuts, "passedIDCuts"},
    {MuonIntProps::acceptedMuonTool, "acceptedMuonTool"},
    {MuonIntProps::isVHLooseMuon, "isVHLooseMuon"},
    {MuonIntProps::isVHSignalMuon, "isVHSignalMuon"},
    {MuonIntProps::isZHSignalMuon, "isZHSignalMuon"},
    {MuonIntProps::isWHSignalMuon, "isWHSignalMuon"},
    {MuonIntProps::isTTLHOLRTauMuon, "isTTLHOLRTauMuon"},
    {MuonIntProps::isTTLHDiLepVetoMuon, "isTTLHDiLepVetoMuon"},
    {MuonIntProps::isTTLHPreSelMuon, "isTTLHPreSelMuon"},
    {MuonIntProps::isTTLHIsolMuon, "isTTLHIsolMuon"},
    {MuonIntProps::isTTLHSoftMuon, "isTTLHSoftMuon"},
    // no setCharge method up to now in Muon EDM

  };

  m_floatPropNames = {
    {MuonFloatProps::z0, "z0"},
    {MuonFloatProps::d0, "d0"},
    {MuonFloatProps::effSF, "effSF"},
    {MuonFloatProps::charge, "charge"}
    
  };
}

