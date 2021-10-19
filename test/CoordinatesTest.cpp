#include <gtest/gtest.h>
#include "game/Coordinates.hpp"

TEST(CoordinatesTest, ShouldBeEqual) {
    constexpr Coordinates first((Coordinates::Coord<Axis::X>(10)), (Coordinates::Coord<Axis::Y>(20)));
    constexpr Coordinates second((Coordinates::Coord<Axis::X>(10)), (Coordinates::Coord<Axis::Y>(20)));
    ASSERT_EQ(first, second);
    constexpr Coordinates third((Coordinates::Coord<Axis::X>(0)), (Coordinates::Coord<Axis::Y>(0)));
    ASSERT_EQ(first == third, false);
}

TEST(CoordinatesTest, ShouldNotBeEqual) {
    constexpr Coordinates first((Coordinates::Coord<Axis::X>(10)), (Coordinates::Coord<Axis::Y>(20)));
    constexpr Coordinates second((Coordinates::Coord<Axis::X>(0)), (Coordinates::Coord<Axis::Y>(0)));
    ASSERT_EQ(first == second, false);
}
