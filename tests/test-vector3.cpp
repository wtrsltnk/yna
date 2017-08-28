#include "catch.hpp"
#include <vector3.h>

TEST_CASE("vector3 size is equal to size of two floats", "[vector3]")
{
    yna::framework::Vector3 v;

    REQUIRE(sizeof(v.X) == sizeof(float));
    REQUIRE(sizeof(v.Y) == sizeof(float));
    REQUIRE(sizeof(v.Z) == sizeof(float));
    REQUIRE(sizeof(v) == sizeof(float) * 3);
}
