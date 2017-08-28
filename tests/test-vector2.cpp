#include "doctest.h"
#include <vector2.h>

TEST_CASE("vector2 size is equal to size of two floats")
{
    yna::framework::Vector2 v;

    CHECK(sizeof(v.X) == sizeof(float));
    CHECK(sizeof(v.Y) == sizeof(float));
    CHECK(sizeof(v) == sizeof(float) * 2);
}

TEST_CASE("vector2 constructors fill X and Y")
{
    CHECK(yna::framework::Vector2(1.2f).X == 1.2f);
    CHECK(yna::framework::Vector2(1.2f).Y == 1.2f);
    CHECK(yna::framework::Vector2(1.2f, 3.4f).X == 1.2f);
    CHECK(yna::framework::Vector2(1.2f, 3.4f).Y == 3.4f);
    CHECK(yna::framework::Vector2(1.2f, 3.4f)[0] == 1.2f);
    CHECK(yna::framework::Vector2(1.2f, 3.4f)[1] == 3.4f);
}

TEST_CASE("vector2 operators")
{
    CHECK(yna::framework::Vector2(1.2f) == yna::framework::Vector2(1.2f));
    CHECK((yna::framework::Vector2(2.0f) * 3.0f).X == 6.0f);
    CHECK((yna::framework::Vector2(2.0f) + 3.0f).X == 5.0f);
    CHECK((yna::framework::Vector2(2.0f) - 3.0f).X == -1.0f);
    CHECK((yna::framework::Vector2(2.0f) / 3.0f).X == (2.0f / 3.0f));
    CHECK((yna::framework::Vector2(2.0f) * yna::framework::Vector2(3.0f)).X == 6.0f);
    CHECK((yna::framework::Vector2(2.0f) + yna::framework::Vector2(3.0f)).X == 5.0f);
    CHECK((yna::framework::Vector2(2.0f) - yna::framework::Vector2(3.0f)).X == -1.0f);
    CHECK((yna::framework::Vector2(2.0f) / yna::framework::Vector2(3.0f)).X == (2.0f / 3.0f));

    yna::framework::Vector2 a(2.0f);
    a *= yna::framework::Vector2(3.0f);
    CHECK(a.X == 6.0f);

    yna::framework::Vector2 b(2.0f);
    b += yna::framework::Vector2(3.0f);
    CHECK(b.X == 5.0f);

    yna::framework::Vector2 c(2.0f);
    c -= yna::framework::Vector2(3.0f);
    CHECK(c.X == -1.0f);

    yna::framework::Vector2 d(2.0f);
    d /= yna::framework::Vector2(3.0f);
    CHECK(d.X == (2.0f / 3.0f));
}
