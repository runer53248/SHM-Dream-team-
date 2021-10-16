#pragma once

#include <utility>

enum class Axis { X, Y };

class Coordinates {
public:
    template<Axis>
    struct Coord {
        explicit constexpr Coord(int coord)
                : value(coord) {}

        constexpr bool operator==(const Coord& other) const {
            return value == other.value;
        }

        const int value{};
    };

    constexpr Coordinates(const Coord<Axis::X>& posX, const Coord<Axis::Y>& posY)
            : posX_(posX), posY_(posY) {}

    constexpr bool operator==(const Coordinates& other) const {
        return posX_ == other.posX_ && posY_ == other.posY_;
    }

private:
    const Coord<Axis::X> posX_;
    const Coord<Axis::Y> posY_;
};
