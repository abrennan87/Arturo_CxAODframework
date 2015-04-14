#include "CxAODTools/PhotonDecorator.h"

template <>
PhotonDecorator::MapCharDec ObjectDecorator<PhotCharProps, PhotIntProps, PhotFloatProps>::m_charDecs = {};

template <>
PhotonDecorator::MapCharAcc ObjectDecorator<PhotCharProps, PhotIntProps, PhotFloatProps>::m_charAccs = {};

template <>
PhotonDecorator::MapIntDec ObjectDecorator<PhotCharProps, PhotIntProps, PhotFloatProps>::m_intDecs = {};

template <>
PhotonDecorator::MapIntAcc ObjectDecorator<PhotCharProps, PhotIntProps, PhotFloatProps>::m_intAccs = {};

template <>
PhotonDecorator::MapFloatDec ObjectDecorator<PhotCharProps, PhotIntProps, PhotFloatProps>::m_floatDecs = {};

template <>
PhotonDecorator::MapFloatAcc ObjectDecorator<PhotCharProps, PhotIntProps, PhotFloatProps>::m_floatAccs = {};

PhotonDecorator::PhotonDecorator(){

  m_charPropNames = {
    // OR tool
    {PhotCharProps::ORInputLabel, "ORInputLabel"},
    {PhotCharProps::OROutputLabel, "OROutputLabel"}
  };

  m_intPropNames = {
    {PhotIntProps::passPreSel, "passPreSel"},
    {PhotIntProps::partIndex, "partIndex"},
    {PhotIntProps::passOR, "passOR"},
    {PhotIntProps::passORGlob, "passORGlob"},
    //TODO: Check these two
    //{PhotIntProps::isVeryLooseLH, "isVeryLooseLH"}, {PhotIntProps::isVeryTightLH, "isVeryTightLH"},
    //{PhotIntProps::isTightPP, "isTightPP"},
    {PhotIntProps::isTightIso, "isTightIso"},
    {PhotIntProps::isVBFLoosePhoton, "isVBFLoosePhoton"}, {PhotIntProps::isVBFSignalPhoton, "isVBFSignalPhoton"}
  };

  m_floatPropNames = {
    {PhotFloatProps::IDEff, "IDEff"}, {PhotFloatProps::IDEffSys, "IDEffSys"}
  };
}
