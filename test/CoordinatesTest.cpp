#include <gtest/gtest.h>
#include <utility>
#include "game/Coordinates.hpp"

TEST(CoordinatesTest, Basic) {
    constexpr int x{10};
    constexpr int y{-5};
    constexpr Coordinates myPosition((Coordinates::CoordX(x)), (Coordinates::CoordY(y)));
    ASSERT_EQ(myPosition.getPosition().first, Coordinates::CoordX(x));
    ASSERT_EQ(myPosition.getPosition().second, Coordinates::CoordY(y));
}
