#pragma once

#include "Coordinates.hpp"

#include <memory>
#include <string>

class IslandInterface {
public:
    IslandInterface(std::string& name, std::unique_ptr<Coordinates>& position);
    virtual ~IslandInterface();
    Coordinates* getCoordinates() const { return position_.get(); }

private:
    std::string name_;
    std::unique_ptr<Coordinates>position_;
    uint8_t level_;
};