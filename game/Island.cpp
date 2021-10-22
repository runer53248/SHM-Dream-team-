#include "../include/game/Island.hpp"

Island::Island(std::string& name, std::unique_ptr<Coordinates>& position, int level)
    : name_(name)
    , position_(std::make_unique<Coordinates>(*position))
    , level_(level)
{

}

Island::~Island() 
{ 

}