#ifndef CxAODTools_PhotonDecorator_H
#define CxAODTools_PhotonDecorator_H

#include "ObjectDecorator.h"

enum class PhotCharProps {
  // OR tool
  ORInputLabel,
  OROutputLabel
};

enum class PhotIntProps {
  // common stuff
  passPreSel,
  partIndex,
  passOR,
  passORGlob,
  // e-gamma ID
  //TODO: check these for photons
  //isVeryLooseLH,
  //isVeryTightLH,
  //isTightPP,
  isTightIso,
  // analysis quality assignment
  isVBFLoosePhoton,
  isVBFSignalPhoton
};

enum class PhotFloatProps { IDEff, IDEffSys };

class PhotonDecorator : public ObjectDecorator<PhotCharProps, PhotIntProps, PhotFloatProps>
{

public:
  PhotonDecorator();
  ~PhotonDecorator() = default;

};

#endif
