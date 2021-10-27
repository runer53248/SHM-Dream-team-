#include "../include/game/Player.hpp"
#include "../utility/json/JsonSerializer.hpp"

#include <iostream>

std::unique_ptr<Player> Player::create() {
    auto player = std::unique_ptr<Player>(new Player());
    // until JsonConvert specialization is not writen
    if ( auto name =
                JsonSerializer::getValue<std::string>( "Player", "Name" ) ) {
        player->setName( name.value() );
    }
    if ( auto money =
                JsonSerializer::getValue<size_t>( "Player", "Money" ) ) {
        player->setMoney( money.value() );
    }
    return player;
}

Player::Player() { std::cout << "Player()\n"; }
Player::~Player() { std::cout << "~Player()\n"; }

size_t Player::getMoney() const { return money_; }
std::string Player::getName() const { return name_; }

void Player::setMoney( size_t money ) { money_ = money; }
void Player::setName( const std::string& name ) { name_ = name; }
