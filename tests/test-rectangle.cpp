#include "doctest.h"
#include <rectangle.h>
#include <point.h>

TEST_CASE("rectangle size is equal to size of four ints")
{
    yna::framework::Rectangle r;

    CHECK(sizeof(r.X) == sizeof(int));
    CHECK(sizeof(r.Y) == sizeof(int));
    CHECK(sizeof(r.Width) == sizeof(int));
    CHECK(sizeof(r.Height) == sizeof(int));
    CHECK(sizeof(r) == sizeof(int) * 4);
}

TEST_CASE("rectangle properties should return correct values")
{
    yna::framework::Rectangle r(10, 10, 100, 100);

    CHECK(r.Bottom() == 110);
    CHECK(r.Center() == yna::framework::Point(60, 60));
    CHECK(r.IsEmpty() == false);
    CHECK(r.Left() == 10);
    CHECK(r.Location() == yna::framework::Point(10, 10));
    CHECK(r.Right() == 110);
    CHECK(r.Top() == 10);
}

TEST_CASE("rectangle contains should work")
{
    yna::framework::Rectangle r(10, 10, 100, 100);

    CHECK(r.Contains(0, 0) == false);
    CHECK(r.Contains(20, 0) == false);
    CHECK(r.Contains(20, 20) == true);
    CHECK(r.Contains(120, 20) == false);
    CHECK(r.Contains(yna::framework::Point(0, 0)) == false);
    CHECK(r.Contains(yna::framework::Point(20, 0)) == false);
    CHECK(r.Contains(yna::framework::Point(20, 20)) == true);
    CHECK(r.Contains(yna::framework::Point(120, 20)) == false);
    CHECK(r.Contains(yna::framework::Rectangle(25, 25, 20, 20)) == true);
    CHECK(r.Contains(yna::framework::Rectangle(5, 5, 20, 20)) == false);
}

TEST_CASE("rectangle intersects should work")
{
    yna::framework::Rectangle r(10, 10, 100, 100);

    CHECK(r.Intersects(yna::framework::Rectangle(25, 25, 20, 20)) == true);
    CHECK(r.Intersects(yna::framework::Rectangle(5, 5, 20, 20)) == true);
    CHECK(r.Intersects(yna::framework::Rectangle(150, 15, 70, 20)) == false);
}

TEST_CASE("rectangle inflate should work")
{
    yna::framework::Rectangle r(10, 10, 100, 100);

    r.Inflate(25, 25);

    CHECK(r.X == -15);
    CHECK(r.Y == -15);
    CHECK(r.Width == 150);
    CHECK(r.Height == 150);
}
