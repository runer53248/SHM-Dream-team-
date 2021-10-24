#pragma once
#include "../utility/json/JsonSerializer.hpp"

#include <iostream>
#include <memory>

//example implementation to show load from json
class Player {
public:
    static std::unique_ptr<Player> create() {
        auto player = std::make_unique<Player>();
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

    Player() { std::cout << "Player()\n"; }
    ~Player() { std::cout << "~Player()\n"; }

    size_t getMoney() const { return money_; }
    std::string getName() const { return name_; }

    void setMoney( size_t money ) { money_ = money; }
    void setName( std::string name ) { name_ = name; }

private:
    size_t money_;
    std::string name_;
};