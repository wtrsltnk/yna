#include "catch.hpp"
#include <vector4.h>

TEST_CASE("vector4 size is equal to size of two floats", "[vector4]")
{
    yna::framework::Vector4 v;

    REQUIRE(sizeof(v.X) == sizeof(float));
    REQUIRE(sizeof(v.Y) == sizeof(float));
    REQUIRE(sizeof(v.Z) == sizeof(float));
    REQUIRE(sizeof(v.W) == sizeof(float));
    REQUIRE(sizeof(v) == sizeof(float) * 4);
}
