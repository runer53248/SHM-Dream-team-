#include "../include/game/Island.hpp"

Island::Island(const std::string& name, std::unique_ptr<Coordinates>& position, const int level)
    : name_(name)
    , position_(std::make_unique<Coordinates>(*position))
    , level_(level)
{

}