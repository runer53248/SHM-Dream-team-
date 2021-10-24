#pragma once

#include "Coordinates.hpp"
#include "IslandInterface.hpp"

#include <memory>
#include <string>

class Island : public IslandInterface{
public:
    Island(const std::string& name, const Coordinates* position, int level);
    
    const std::string getName() const override { return name_; }
    const Coordinates* getCoordinates() const override { return position_; }
    int getLevel() const override { return level_; }

private:
    const std::string name_;
    const Coordinates* position_;
    int level_;
};
