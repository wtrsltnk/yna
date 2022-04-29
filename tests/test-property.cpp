#include "doctest.h"
#include <property.h>
//#include <type.h>
#include <iostream>

class RegularClass
{
public:
    RegularClass(int initial) : _localGetProperty(initial), SomeGetProperty(_localGetProperty) { }

    int _localGetProperty;

    property<int> SomeProperty;
    get_property<int> SomeGetProperty;
};

TEST_CASE("get_property works with class variable")
{
    RegularClass sut(10);

    CHECK(sut._localGetProperty == 10);
    CHECK(sut.SomeGetProperty.get() == 10);

    sut._localGetProperty = 15;

    CHECK(sut._localGetProperty == 15);
    CHECK(sut.SomeGetProperty.get() == 15);
}
