#pragma once

#include "Coordinates.hpp"
#include "IslandInterface.hpp"

#include <memory>
#include <string>

class Island : public IslandInterface{
public:
    Island(const std::string& name, const Coordinates& position, int level);

    std::string getName() const override { return name_; }
    Coordinates* getCoordinates() const override { return position_.get(); }
    int getLevel() const override { return level_; }

private:
    std::string name_;
    Coordinates position_;
    int level_;

};