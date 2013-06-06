//
//  ControlValue.h
//  TonicDemo
//
//  Created by Morgan Packard on 2/12/13.

//

#ifndef __TonicDemo__ControlValue__
#define __TonicDemo__ControlValue__

#include "ControlGenerator.h"

namespace Tonic {

  namespace Tonic_{

    class ControlValue_ : public ControlGenerator_{
    
    public:
      
        ControlValue_();
      
        inline void setValue(float value){
          value_ = value;
          triggered_ = true;
        }
      
        inline void trigger() { triggered_ = true; }
      
        // Get current value directly
        TonicFloat getValue() { return value_;};
      
      protected:
            
        void computeOutput(const SynthesisContext_ & context);
      
        TonicFloat  value_;
        bool        triggered_;
      
    };
    
    inline void ControlValue_::computeOutput(const SynthesisContext_ & context){
      output_.triggered =  (triggered_ || context.forceNewOutput);
      triggered_ = context.forceNewOutput; // if new output forced, don't reset changed status until next tick
      output_.value = value_;
    }
  }
  
  
  class ControlValue : public TemplatedControlGenerator<Tonic_::ControlValue_>{
    
    public:
    
    ControlValue(TonicFloat value = 0){
      gen()->setValue(value);
    }
    
    ControlValue & value(TonicFloat value)
    {
      gen()->setValue(value);
      return *this;
    }
    
    void trigger(){
      gen()->trigger();
    }
    
    // for higher-level access - doesn't affect tick state
    float getValue(){
      return gen()->getValue();
    }

  };

}

#endif /* defined(__TonicDemo__ControlValue__) */
