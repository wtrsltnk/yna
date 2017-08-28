#include "catch.hpp"
#include <vector2.h>

TEST_CASE("vector2 size is equal to size of two floats", "[vector2]")
{
    yna::framework::Vector2 v;

    REQUIRE(sizeof(v.X) == sizeof(float));
    REQUIRE(sizeof(v.Y) == sizeof(float));
    REQUIRE(sizeof(v) == sizeof(float) * 2);
}
