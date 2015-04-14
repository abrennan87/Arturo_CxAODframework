#include "CxAODTools/IndexDecorator.h"

template <>
IndexDecorator::MapCharDec ObjectDecorator<IndexCharProps, IndexIntProps, IndexFloatProps>::m_charDecs = {};

template <>
IndexDecorator::MapCharAcc ObjectDecorator<IndexCharProps, IndexIntProps, IndexFloatProps>::m_charAccs = {};

template <>
IndexDecorator::MapIntDec ObjectDecorator<IndexCharProps, IndexIntProps, IndexFloatProps>::m_intDecs = {};

template <>
IndexDecorator::MapIntAcc ObjectDecorator<IndexCharProps, IndexIntProps, IndexFloatProps>::m_intAccs = {};

template <>
IndexDecorator::MapFloatDec ObjectDecorator<IndexCharProps, IndexIntProps, IndexFloatProps>::m_floatDecs = {};

template <>
IndexDecorator::MapFloatAcc ObjectDecorator<IndexCharProps, IndexIntProps, IndexFloatProps>::m_floatAccs = {};

IndexDecorator::IndexDecorator() {

  m_charPropNames = {
    {IndexCharProps::None, "None"}
  };

  m_intPropNames = {
    {IndexIntProps::partIndex, "partIndex"},
  };

  m_floatPropNames = {
    {IndexFloatProps::None, "None"}
  };
}

