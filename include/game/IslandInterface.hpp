#pragma once

#include "Coordinates.hpp"

#include <memory>
#include <string>

class IslandInterface {
public:
    IslandInterface(std::string& name, std::unique_ptr<Coordinates>& position, int level_);
    virtual ~IslandInterface();

    std::string getName() const { return name_; }
    Coordinates* getCoordinates() const { return position_.get(); }
    int getLevel() const { return level_; }

private:
    std::string name_;
    std::unique_ptr<Coordinates>position_;
    int level_;

};