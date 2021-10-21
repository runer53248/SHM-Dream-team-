#pragma once

#include "Coordinates.hpp"

#include <string>

class IslandInterface {
public:
    virtual ~IslandInterface() = default;

    virtual std::string getName() const = 0;
    virtual Coordinates* getCoordinates() const = 0;
    virtual int getLevel() const = 0;
};
