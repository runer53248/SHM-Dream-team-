#include "../include/game/Map.hpp"
#include "../utility/json/JsonSerializer.hpp"

#include <iostream>

std::unique_ptr<Map> Map::create() { 
    auto map = std::unique_ptr<Map>(new Map()); 
    // until JsonConvert specialization is not writen
    if(auto x = JsonSerializer::getValue<size_t>( "Map", "width" )){
        if(auto y = JsonSerializer::getValue<size_t>( "Map", "height" )){
            map->setSize(x.value(), y.value());
        }
    }
    return map;
}

Map::Map() { std::cout << "Map()\n"; }
Map::~Map() { std::cout << "~Map()\n"; }

MapSize Map::getSize() const { return size_; }

void Map::setSize( size_t x, size_t y ) {
    size_.x = x;
    size_.y = y;
}
