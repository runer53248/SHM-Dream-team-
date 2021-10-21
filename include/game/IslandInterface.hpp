#pragma once

#include "Coordinates.hpp"

#include <memory>
#include <string>

class IslandInterface {
public:
    IslandInterface();
    virtual ~IslandInterface();

private:
    std::string name_;
    std::unique_ptr<Coordinates>position_;
    
};