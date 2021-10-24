#pragma once
#include "IslandInterface.hpp"

#include <memory>

struct MapSize {
    size_t x;
    size_t y;
};

//example implementation to show load from json
class Map {
public:
    //will load data from global json
    static std::unique_ptr<Map> create();

    ~Map();

    MapSize getSize() const;

    void setSize( size_t x, size_t y );

private:
    Map();

    MapSize size_;
};