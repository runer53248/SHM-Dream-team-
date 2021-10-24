#pragma once
#include "IslandInterface.hpp"
#include "../utility/json/JsonSerializer.hpp"

#include <iostream>
#include <memory>

struct MapSize {
    size_t x;
    size_t y;
};

//example implementation to show load from json
class Map {
public:
    static std::unique_ptr<Map> create() { 
        auto map = std::make_unique<Map>(); 
        // until JsonConvert specialization is not writen
        if(auto x = JsonSerializer::getValue<size_t>( "Map", "width" )){
            if(auto y = JsonSerializer::getValue<size_t>( "Map", "height" )){
                map->setSize(x.value(), y.value());
            }
        }
        return map;
    }

    Map() { std::cout << "Map()\n"; }
    ~Map() { std::cout << "~Map()\n"; }

    MapSize getSize() const { return size_; }

    void setSize( size_t x, size_t y ) {
        size_.x = x;
        size_.y = y;
    }

private:
    MapSize size_;
};