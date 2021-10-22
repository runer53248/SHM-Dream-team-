#pragma once

#include "Coordinates.hpp"
#include "IslandInterface.hpp"

#include <memory>
#include <string>

class Island : public IslandInterface{
public:
    Island(const std::string& name, std::unique_ptr<Coordinates>& position, const int level);

    std::string getName() const override { return name_; }
    Coordinates* getCoordinates() const override { return position_.get(); }
    int getLevel() const override { return level_; }

private:
    std::string name_;
    std::unique_ptr<Coordinates>position_;
    int level_;

};