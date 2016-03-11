#include <tut/tut.hpp>
#include "Mathf.h"
#include <string>

namespace tut {
    
    struct dataMathf
    {
        
    };
    
    typedef test_group<dataMathf> tgMathf;
    tgMathf testGroupMathf("test Mathf");
    
    typedef tgMathf::object MathfTestObject;
    
    template<>
    template<>
    void MathfTestObject::test<1>()
    {
        set_test_name("IsPowerOf2");
        
        ensure_equals(Mathf::isPowerOf2(4), true);
        ensure_equals(Mathf::isPowerOf2(99), false);
    }
}