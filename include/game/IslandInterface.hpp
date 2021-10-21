#pragma once

#include "Coordinates.hpp"

#include <string>

class IslandInterface {
public:
    virtual ~IslandInterface();

    virtual std::string getName() = 0;
    virtual Coordinates* getCoordinates() = 0;
    virtual int getLevel() = 0;
};
