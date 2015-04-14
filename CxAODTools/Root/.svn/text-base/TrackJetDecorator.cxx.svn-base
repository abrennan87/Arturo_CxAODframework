#include "CxAODTools/TrackJetDecorator.h"

template <>
TrackJetDecorator::MapCharDec ObjectDecorator<TrackJetCharProps, TrackJetIntProps, TrackJetFloatProps>::m_charDecs = {};

template <>
TrackJetDecorator::MapCharAcc ObjectDecorator<TrackJetCharProps, TrackJetIntProps, TrackJetFloatProps>::m_charAccs = {};

template <>
TrackJetDecorator::MapIntDec ObjectDecorator<TrackJetCharProps, TrackJetIntProps, TrackJetFloatProps>::m_intDecs = {};

template <>
TrackJetDecorator::MapIntAcc ObjectDecorator<TrackJetCharProps, TrackJetIntProps, TrackJetFloatProps>::m_intAccs = {};

template <>
TrackJetDecorator::MapFloatDec ObjectDecorator<TrackJetCharProps, TrackJetIntProps, TrackJetFloatProps>::m_floatDecs = {};

template <>
TrackJetDecorator::MapFloatAcc ObjectDecorator<TrackJetCharProps, TrackJetIntProps, TrackJetFloatProps>::m_floatAccs = {};

TrackJetDecorator::TrackJetDecorator() {
  
  m_charPropNames = {
    {TrackJetCharProps::None, "None"}
  };
  
  m_intPropNames = {
    {TrackJetIntProps::partIndex, "partIndex"},
    {TrackJetIntProps::isTrackJet, "isTrackJet"}
  };

  m_floatPropNames = {
    {TrackJetFloatProps::JVF, "jvf0"}
  };

}
