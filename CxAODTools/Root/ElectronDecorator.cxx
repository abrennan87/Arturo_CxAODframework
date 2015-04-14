#include "CxAODTools/ElectronDecorator.h"

template <>
ElectronDecorator::MapCharDec ObjectDecorator<ElecCharProps, ElecIntProps, ElecFloatProps>::m_charDecs = {};

template <>
ElectronDecorator::MapCharAcc ObjectDecorator<ElecCharProps, ElecIntProps, ElecFloatProps>::m_charAccs = {};

template <>
ElectronDecorator::MapIntDec ObjectDecorator<ElecCharProps, ElecIntProps, ElecFloatProps>::m_intDecs = {};

template <>
ElectronDecorator::MapIntAcc ObjectDecorator<ElecCharProps, ElecIntProps, ElecFloatProps>::m_intAccs = {};

template <>
ElectronDecorator::MapFloatDec ObjectDecorator<ElecCharProps, ElecIntProps, ElecFloatProps>::m_floatDecs = {};

template <>
ElectronDecorator::MapFloatAcc ObjectDecorator<ElecCharProps, ElecIntProps, ElecFloatProps>::m_floatAccs = {};

ElectronDecorator::ElectronDecorator() {
  m_charPropNames = {
    {ElecCharProps::ORInputLabel, "ORInputLabel"},
    {ElecCharProps::OROutputLabel, "OROutputLabel"}
  };

  m_intPropNames = {
    {ElecIntProps::passPreSel, "passPreSel"},
    {ElecIntProps::partIndex, "partIndex"},
    {ElecIntProps::passOR, "passOR"},
    {ElecIntProps::passORGlob, "passORGlob"},
    {ElecIntProps::isVeryLooseLH, "isVeryLooseLH"}, {ElecIntProps::isVeryTightLH, "isVeryTightLH"},
    {ElecIntProps::isTightPP, "isTightPP"},
    {ElecIntProps::isLoosePP, "isLoosePP"},
    {ElecIntProps::isMediumPP, "isMediumPP"},
    {ElecIntProps::isVHLooseElectron, "isVHLooseElectron"},     {ElecIntProps::isVHSignalElectron, "isVHSignalElectron"},
    {ElecIntProps::isZHSignalElectron, "isZHSignalElectron"}, {ElecIntProps::isWHSignalElectron, "isWHSignalElectron"},
    {ElecIntProps::isTTLHOLRElectron, "isTTLHOLRElectron"},
    {ElecIntProps::isTTLHDiLepVetoElectron, "isTTLHDiLepVetoElectron"},
    {ElecIntProps::isTTLHPreSelElectron, "isTTLHPreSelElectron"},
    {ElecIntProps::isTTLHIsolElectron, "isTTLHIsolElectron"},
    {ElecIntProps::isTTLHSoftElectron, "isTTLHSoftElectron"},
    {ElecIntProps::isEWOrigin,"isEWOrigin"}
  };

  m_floatPropNames = {
    {ElecFloatProps::charge, "charge"},
    {ElecFloatProps::effSFloose, "effSFloose"},
    {ElecFloatProps::effSFtight, "effSFtight"}
  };
}

