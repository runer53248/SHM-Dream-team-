#pragma once

#include "Coordinates.hpp"

#include <string>

class IslandInterface {
public:
    virtual ~IslandInterface() = default;

    virtual const std::string getName() const = 0;
    virtual const Coordinates* getCoordinates() const = 0;
    virtual int getLevel() const = 0;
};
