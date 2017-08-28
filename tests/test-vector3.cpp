#include "doctest.h"
#include <vector3.h>

TEST_CASE("vector3 size is equal to size of three floats")
{
    yna::framework::Vector3 v;

    CHECK(sizeof(v.X) == sizeof(float));
    CHECK(sizeof(v.Y) == sizeof(float));
    CHECK(sizeof(v.Z) == sizeof(float));
    CHECK(sizeof(v) == sizeof(float) * 3);
}

TEST_CASE("vector3 constructors fill X, Y and Z")
{
    CHECK(yna::framework::Vector3(1.2f).X == 1.2f);
    CHECK(yna::framework::Vector3(1.2f).Y == 1.2f);
    CHECK(yna::framework::Vector3(1.2f).Z == 1.2f);
    CHECK(yna::framework::Vector3(1.2f, 3.4f, 5.6f).X == 1.2f);
    CHECK(yna::framework::Vector3(1.2f, 3.4f, 5.6f).Y == 3.4f);
    CHECK(yna::framework::Vector3(1.2f, 3.4f, 5.6f).Z == 5.6f);
    CHECK(yna::framework::Vector3(1.2f, 3.4f, 5.6f)[0] == 1.2f);
    CHECK(yna::framework::Vector3(1.2f, 3.4f, 5.6f)[1] == 3.4f);
    CHECK(yna::framework::Vector3(1.2f, 3.4f, 5.6f)[2] == 5.6f);
}

TEST_CASE("vector3 operators")
{
    CHECK(yna::framework::Vector3(1.2f) == yna::framework::Vector3(1.2f));
    CHECK((yna::framework::Vector3(2.0f) * yna::framework::Vector3(3.0f)).X == 6.0f);
    CHECK((yna::framework::Vector3(2.0f) + yna::framework::Vector3(3.0f)).X == 5.0f);
    CHECK((yna::framework::Vector3(2.0f) - yna::framework::Vector3(3.0f)).X == -1.0f);
    CHECK((yna::framework::Vector3(2.0f) / yna::framework::Vector3(3.0f)).X == (2.0f / 3.0f));
    CHECK((yna::framework::Vector3(2.0f) * 3.0f).X == 6.0f);
    CHECK((yna::framework::Vector3(2.0f) + 3.0f).X == 5.0f);
    CHECK((yna::framework::Vector3(2.0f) - 3.0f).X == -1.0f);
    CHECK((yna::framework::Vector3(2.0f) / 3.0f).X == (2.0f / 3.0f));

    yna::framework::Vector3 a(2.0f);
    a *= yna::framework::Vector3(3.0f);
    CHECK(a.X == 6.0f);

    yna::framework::Vector3 b(2.0f);
    b += yna::framework::Vector3(3.0f);
    CHECK(b.X == 5.0f);

    yna::framework::Vector3 c(2.0f);
    c -= yna::framework::Vector3(3.0f);
    CHECK(c.X == -1.0f);

    yna::framework::Vector3 d(2.0f);
    d /= yna::framework::Vector3(3.0f);
    CHECK(d.X == (2.0f / 3.0f));
}
