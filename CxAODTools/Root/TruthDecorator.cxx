#include "CxAODTools/TruthDecorator.h"

template <>
TruthDecorator::MapCharDec ObjectDecorator<TruthCharProps, TruthIntProps, TruthFloatProps>::m_charDecs = {};

template <>
TruthDecorator::MapCharAcc ObjectDecorator<TruthCharProps, TruthIntProps, TruthFloatProps>::m_charAccs = {};

template <>
TruthDecorator::MapIntDec ObjectDecorator<TruthCharProps, TruthIntProps, TruthFloatProps>::m_intDecs = {};

template <>
TruthDecorator::MapIntAcc ObjectDecorator<TruthCharProps, TruthIntProps, TruthFloatProps>::m_intAccs = {};

template <>
TruthDecorator::MapFloatDec ObjectDecorator<TruthCharProps, TruthIntProps, TruthFloatProps>::m_floatDecs = {};

template <>
TruthDecorator::MapFloatAcc ObjectDecorator<TruthCharProps, TruthIntProps, TruthFloatProps>::m_floatAccs = {};

TruthDecorator::TruthDecorator() {

  m_charPropNames ={
    {TruthCharProps::None, "None"}
  };

  m_intPropNames = {
    {TruthIntProps::None, "None"},
  };

  m_floatPropNames = {
    {TruthFloatProps::zPV, "zPV"}
  };
}

