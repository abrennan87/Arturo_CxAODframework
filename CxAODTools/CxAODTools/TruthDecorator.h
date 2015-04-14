#ifndef CxAODTools_TruthDecorator_H
#define CxAODTools_TruthDecorator_H

#include "ObjectDecorator.h"

enum class TruthCharProps { None };
enum class TruthIntProps { None };
enum class TruthFloatProps { zPV  };

class TruthDecorator : public ObjectDecorator<TruthCharProps, TruthIntProps, TruthFloatProps>
{

public:
  TruthDecorator();
  ~TruthDecorator() = default;

};

#endif
