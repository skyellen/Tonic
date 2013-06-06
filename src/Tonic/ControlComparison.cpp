//
//  ControlComparison.cpp
//  Tonic
//
//  Created by Nick Donaldson on 5/31/13.
//

#include "ControlComparison.h"

namespace Tonic { namespace Tonic_{
  
  ControlBooleanOperator_::ControlBooleanOperator_() :
    lhsGen_(ControlValue(0)),
    rhsGen_(ControlValue(0))
  {};
  
  // --------------------------------------
  //              EQUALITY
  // --------------------------------------
  
  bool ControlEquals_::satisfiesCondition(float l, float r)
  {
    return l == r;
  }
  
  // --------------------------------------
  //             INEQUALITY
  // --------------------------------------
  
  bool ControlNotEquals_::satisfiesCondition(float l, float r)
  {
    return l != r;
  }
  
  // --------------------------------------
  //            GREATER THAN
  // --------------------------------------
  
  bool ControlGreaterThan_::satisfiesCondition(float l, float r)
  {
    return l > r;
  }
  
  // --------------------------------------
  //          GREATER OR EQUAL
  // --------------------------------------

  bool ControlGreaterOrEqual_::satisfiesCondition(float l, float r)
  {
    return l >= r;
  }
  
  // --------------------------------------
  //              LESS THAN
  // --------------------------------------
  
  bool ControlLessThan_::satisfiesCondition(float l, float r)
  {
    return l < r;
  }
  
  // --------------------------------------
  //            LESS OR EQUAL
  // --------------------------------------
  
  bool ControlLessOrEqual_::satisfiesCondition(float l, float r)
  {
    return l <= r;
  }
  
} // Namespace Tonic_
  
  
  
} // Namespace Tonic
