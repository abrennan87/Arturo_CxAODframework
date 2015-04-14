#include "CxAODTools/JetDecorator.h"

template <>
JetDecorator::MapCharDec ObjectDecorator<JetCharProps, JetIntProps, JetFloatProps>::m_charDecs = {};

template <>
JetDecorator::MapCharAcc ObjectDecorator<JetCharProps, JetIntProps, JetFloatProps>::m_charAccs = {};

template <>
JetDecorator::MapIntDec ObjectDecorator<JetCharProps, JetIntProps, JetFloatProps>::m_intDecs = {};

template <>
JetDecorator::MapIntAcc ObjectDecorator<JetCharProps, JetIntProps, JetFloatProps>::m_intAccs = {};

template <>
JetDecorator::MapFloatDec ObjectDecorator<JetCharProps, JetIntProps, JetFloatProps>::m_floatDecs = {};

template <>
JetDecorator::MapFloatAcc ObjectDecorator<JetCharProps, JetIntProps, JetFloatProps>::m_floatAccs = {};

JetDecorator::JetDecorator() {

  m_charPropNames = {
    {JetCharProps::ORInputLabel, "ORInputLabel"},
    {JetCharProps::OROutputLabel, "OROutputLabel"},
  };

  m_intPropNames = {
    {JetIntProps::passPreSel, "passPreSel"},
    {JetIntProps::partIndex, "partIndex"},
    {JetIntProps::goodJet, "goodJet"},
    {JetIntProps::truthLabel, "TruthLabelID"},
    {JetIntProps::isVetoJet, "isVetoJet"},
    {JetIntProps::isSignalJet, "isSignalJet"},
    {JetIntProps::isVBFJet, "isVBFJet"},
    {JetIntProps::passOR, "passOR"},
    {JetIntProps::passORGlob, "passORGlob"}
  };

  m_floatPropNames = {
    {JetFloatProps::MV1, "MV1"},
    {JetFloatProps::SV1_IP3D,"SV1_IP3D"},
    {JetFloatProps::MV2c00,"MV2c00"},
    {JetFloatProps::MV2c10,"MV2c10"},
    {JetFloatProps::MV2c20,"MV2c20"},
    {JetFloatProps::MVb,"MVb"},
    {JetFloatProps::JVF,"jvf0"},
    {JetFloatProps::btagSF, "btagSF"}
  };

}

