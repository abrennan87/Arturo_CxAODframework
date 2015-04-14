#ifndef CxAODTools_TrackJetDecorator_H
#define CxAODTools_TrackJetDecorator_H

#include "ObjectDecorator.h"

enum class TrackJetCharProps {
  None
};

enum class TrackJetIntProps {
    partIndex,
    isTrackJet
};
enum class TrackJetFloatProps {
    JVF
};

class TrackJetDecorator : public ObjectDecorator<TrackJetCharProps, TrackJetIntProps, TrackJetFloatProps>
{

public:
  TrackJetDecorator();
  ~TrackJetDecorator() = default;

};

#endif
