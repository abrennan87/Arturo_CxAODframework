#ifndef CxAODTools_TauDecorator_H
#define CxAODTools_TauDecorator_H

#include "ObjectDecorator.h"

enum class TauCharProps {
  // OR tool
  ORInputLabel,
  OROutputLabel
};

enum class TauIntProps {
  // common
  passPreSel,
  passEvetoEffSel,
  partIndex,
  passOR,
  passEvetoOR,
  passORGlob,
  passedIDCuts,
  nTracks,
  nWideTracks,
  nPi0PFOs, //tau->nPi0_PFOs()
  isBDTLoose,
  isBDTMedium,
  isBDTTight,
  passLooseTau,
  passEvetoLoose,
  passEvetoMedium,
  passEvetoTight,
  passTauSelector,
  TruthMatch,
  LeptonTruthMatch,
  passCandSel
};

enum class TauFloatProps {
  effSF,
  BDTScore,  
  charge,
  effSFeveto,
  EleBDTScore,
  TrackEta
};

class TauDecorator : public ObjectDecorator<TauCharProps, TauIntProps, TauFloatProps>
{

public:
  TauDecorator();
  ~TauDecorator() = default;

};

#endif
