#pragma once

#include <utility>

class Coordinates {
public:
    struct CoordX {
        explicit constexpr CoordX(int coordX)
            : value(coordX) {}

        constexpr bool operator==(const CoordX& other) const {
            return value == other.value;
        }

        int value{0};
    };

    struct CoordY {
        explicit constexpr CoordY(int coordY)
            : value(coordY) {}

        constexpr bool operator==(const CoordY& other) const {
            return value == other.value;
        }

        int value{0};
    };

    constexpr Coordinates(const CoordX& posX, const CoordY& posY)
        : posX_(posX), posY_(posY) {}

    constexpr std::pair<CoordX, CoordY> getPosition() const {
        return std::make_pair(posX_, posY_);
    }

private:
    const CoordX posX_;
    const CoordY posY_;
};
