#include "CxAODTools/FatJetDecorator.h"


template <>
FatJetDecorator::MapCharDec ObjectDecorator<FatJetCharProps, FatJetIntProps, FatJetFloatProps>::m_charDecs = {};

template <>
FatJetDecorator::MapCharAcc ObjectDecorator<FatJetCharProps, FatJetIntProps, FatJetFloatProps>::m_charAccs = {};

template <>
FatJetDecorator::MapIntDec ObjectDecorator<FatJetCharProps, FatJetIntProps, FatJetFloatProps>::m_intDecs = {};

template <>
FatJetDecorator::MapIntAcc ObjectDecorator<FatJetCharProps, FatJetIntProps, FatJetFloatProps>::m_intAccs = {};

template <>
FatJetDecorator::MapFloatDec ObjectDecorator<FatJetCharProps, FatJetIntProps, FatJetFloatProps>::m_floatDecs = {};

template <>
FatJetDecorator::MapFloatAcc ObjectDecorator<FatJetCharProps, FatJetIntProps, FatJetFloatProps>::m_floatAccs = {};

FatJetDecorator::FatJetDecorator() {
  
  m_charPropNames = {
    {FatJetCharProps::None, "None"}
  };
  
  m_intPropNames = {
    {FatJetIntProps::partIndex, "partIndex"},
    {FatJetIntProps::isFatJet, "isFatJet"}
  };
  
  m_floatPropNames = {
    {FatJetFloatProps::JVF, "jvf0"},
    {FatJetFloatProps::Tau21, "Tau21"},
    {FatJetFloatProps::Tau32, "Tau32"},
    {FatJetFloatProps::Tau21, "Tau21_wta"},
    {FatJetFloatProps::Tau32, "Tau32_wta"},
    {FatJetFloatProps::D2, "D2"},
    {FatJetFloatProps::C1, "C1"},
    {FatJetFloatProps::C2, "C2"},
    {FatJetFloatProps::D2_Beta2, "D2_Beta2"},
    {FatJetFloatProps::C1_Beta2, "C1_Beta2"},
    {FatJetFloatProps::C2_Beta2, "C2_Beta2"}
  };
  
}
