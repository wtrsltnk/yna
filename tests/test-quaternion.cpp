#include "doctest.h"
#include <quaternion.h>

TEST_CASE("quaternion size is equal to size of four floats")
{
    yna::framework::Quaternion q;

    CHECK(sizeof(q.X) == sizeof(float));
    CHECK(sizeof(q.Y) == sizeof(float));
    CHECK(sizeof(q.Z) == sizeof(float));
    CHECK(sizeof(q.W) == sizeof(float));
    CHECK(sizeof(q) == sizeof(float) * 4);
}
