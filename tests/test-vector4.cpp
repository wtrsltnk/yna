#include "doctest.h"
#include <vector4.h>

TEST_CASE("vector4 size is equal to size of four floats")
{
    yna::framework::Vector4 v;

    CHECK(sizeof(v.X) == sizeof(float));
    CHECK(sizeof(v.Y) == sizeof(float));
    CHECK(sizeof(v.Z) == sizeof(float));
    CHECK(sizeof(v.W) == sizeof(float));
    CHECK(sizeof(v) == sizeof(float) * 4);
}

TEST_CASE("vector4 constructors fill X, Y, Z and W")
{
    CHECK(yna::framework::Vector4(1.2f).X == 1.2f);
    CHECK(yna::framework::Vector4(1.2f).Y == 1.2f);
    CHECK(yna::framework::Vector4(1.2f).Z == 1.2f);
    CHECK(yna::framework::Vector4(1.2f).W == 1.2f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f).X == 1.2f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f).Y == 3.4f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f).Z == 5.6f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f).W == 7.8f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f)[0] == 1.2f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f)[1] == 3.4f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f)[2] == 5.6f);
    CHECK(yna::framework::Vector4(1.2f, 3.4f, 5.6f, 7.8f)[3] == 7.8f);
}

TEST_CASE("Vec4 operators")
{
    REQUIRE(yna::framework::Vector4(1.2f) == yna::framework::Vector4(1.2f));
    REQUIRE((yna::framework::Vector4(2.0f) * yna::framework::Vector4(3.0f)).X == 6.0f);
    REQUIRE((yna::framework::Vector4(2.0f) + yna::framework::Vector4(3.0f)).X == 5.0f);
    REQUIRE((yna::framework::Vector4(2.0f) - yna::framework::Vector4(3.0f)).X == -1.0f);
    REQUIRE((yna::framework::Vector4(2.0f) / yna::framework::Vector4(3.0f)).X == (2.0f / 3.0f));
    REQUIRE((yna::framework::Vector4(2.0f) * 3.0f).X == 6.0f);
    REQUIRE((yna::framework::Vector4(2.0f) + 3.0f).X == 5.0f);
    REQUIRE((yna::framework::Vector4(2.0f) - 3.0f).X == -1.0f);
    REQUIRE((yna::framework::Vector4(2.0f) / 3.0f).X == (2.0f / 3.0f));

    yna::framework::Vector4 a(2.0f);
    a *= yna::framework::Vector4(3.0f);
    REQUIRE(a.X == 6.0f);

    yna::framework::Vector4 b(2.0f);
    b += yna::framework::Vector4(3.0f);
    REQUIRE(b.X == 5.0f);

    yna::framework::Vector4 c(2.0f);
    c -= yna::framework::Vector4(3.0f);
    REQUIRE(c.X == -1.0f);

    yna::framework::Vector4 d(2.0f);
    d /= yna::framework::Vector4(3.0f);
    REQUIRE(d.X == (2.0f / 3.0f));
}

TEST_CASE("Vec4 add")
{
    yna::framework::Vector4 v1(10.0f, 4.0f, 7.0f, 2.0f);
    yna::framework::Vector4 v2(1.0f, 9.0f, 11.0f, 9.0f);

    auto r = yna::framework::Vector4::Add(v1, v2);
    REQUIRE(r.X == 11.0f);
    REQUIRE(r.Y == 13.0f);
    REQUIRE(r.Z == 18.0f);
    REQUIRE(r.W == 11.0f);
}
