#ifndef CxAODTools_ElectronDecorator_H
#define CxAODTools_ElectronDecorator_H

#include "ObjectDecorator.h"


enum class ElecCharProps {
  // OR tool
  ORInputLabel,
  OROutputLabel
};

enum class ElecIntProps {
  // common stuff
  passPreSel,
  partIndex,
  passOR,
  passORGlob,
  // e-gamma ID
  isVeryLooseLH,
  isVeryTightLH,
  isTightPP,
  isMediumPP,
  isLoosePP,
  // analysis quality assignment
  isVHLooseElectron,
  isVHSignalElectron,
  isZHSignalElectron,
  isWHSignalElectron,
  isTTLHOLRElectron,
  isTTLHDiLepVetoElectron,
  isTTLHPreSelElectron,
  isTTLHIsolElectron,
  isTTLHSoftElectron,
  isEWOrigin
};

enum class ElecFloatProps {
  charge,
  effSFloose,
  effSFtight
};

class ElectronDecorator : public ObjectDecorator<ElecCharProps, ElecIntProps, ElecFloatProps>
{

public:
  ElectronDecorator();
  ~ElectronDecorator() = default;

};

#endif
