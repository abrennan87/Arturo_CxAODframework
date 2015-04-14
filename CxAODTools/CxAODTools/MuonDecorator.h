#ifndef CxAODTools_MuonDecorator_H
#define CxAODTools_MuonDecorator_H

#include "ObjectDecorator.h"

enum class MuonCharProps {
  // OR tool
  ORInputLabel,
  OROutputLabel
};

enum class MuonIntProps {
  // common
  passPreSel,
  partIndex,
  passOR,
  passORGlob,
  passedIDCuts,
  acceptedMuonTool,
  isVHLooseMuon,
  isVHSignalMuon,
  isZHSignalMuon,
  isWHSignalMuon,
  isTTLHOLRTauMuon,
  isTTLHDiLepVetoMuon,
  isTTLHPreSelMuon,
  isTTLHIsolMuon,
    isTTLHSoftMuon,
};

enum class MuonFloatProps {
  z0,
  d0,
    effSF,
    charge
};

class MuonDecorator : public ObjectDecorator<MuonCharProps, MuonIntProps, MuonFloatProps>
{

public:
  MuonDecorator();
  ~MuonDecorator() = default;

};

#endif
