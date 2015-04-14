// Dear emacs, this is -*-c++-*-
#ifndef CxAODTools_CutFlowCounter_H
#define CxAODTools_CutFlowCounter_H

#include <map>

// ROOT includes
#include "TString.h"
#include "TH1D.h"

class CutFlowCounter {

  public: 

    // Counter for cut flow
    struct Counter {

      // cut order 
      int priority;

      // number of events 
      double count;

      // sum of event weight
      double sumOfWeight;

    };

    // name of the cut flow
    TString m_name;

    // cut flow information: TString->Cut name ; Counter-> see above
    std::map<std::string, Counter> m_cutFlowInfor;

    // Don't count in some case, e.g. systematics variations and etc
    bool m_doStopCount;

    // Constructor: set the name of the cutflow, e.g. electron or event level;
    CutFlowCounter() {
    }

    void setName( TString name ) ;

    // Set the name of cut one by one to setup the cutflowInfor map 
    void setCutFlow( int priority, TString cutName ) ;

    // Count the number of entries and weights passing the cut
    void count( int priority, TString cutName, double weight=1 ) ;

    // Don't count in some case, e.g. systematics variations and etc
    void doStopCount( bool doStop ) ;

    // Don't count in some case, e.g. systematics variations and etc
    TH1D * getCutFlow() ;

};

#endif
