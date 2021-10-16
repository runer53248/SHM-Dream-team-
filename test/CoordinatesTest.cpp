#include <gtest/gtest.h>
#include "game/Coordinates.hpp"

TEST(CoordinatesTest, Basic) {
    constexpr Coordinates first((Coordinates::Coord<Axis::X>(10)), (Coordinates::Coord<Axis::Y>(20)));
    constexpr Coordinates second((Coordinates::Coord<Axis::X>(10)), (Coordinates::Coord<Axis::Y>(20)));
    ASSERT_EQ(first, second);
}
