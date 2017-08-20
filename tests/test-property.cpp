#include "catch.hpp"
#include <property.h>

class RegularClass
{
public:
    RegularClass(int initial) : _localGetProperty(initial), SomeGetProperty(_localGetProperty) { }

    int _localGetProperty;

    property<int> SomeProperty;
    get_property<int> SomeGetProperty;
};

TEST_CASE("get_property works with class variable", "[property]")
{
    RegularClass sut(10);

    REQUIRE(sut._localGetProperty == 10);
    REQUIRE(sut.SomeGetProperty == 10);
    sut._localGetProperty = 15;
    REQUIRE(sut._localGetProperty == 15);
    REQUIRE(sut.SomeGetProperty == 15);
}
