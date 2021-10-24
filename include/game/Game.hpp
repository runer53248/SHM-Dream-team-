#pragma once
#include "../../include/game/Map.hpp"
#include "../../include/game/Player.hpp"
#include "../utility/json/JsonSerializer.hpp"

#include <memory>
#include <string>
#include <iostream>

class Game {
public:
    static std::unique_ptr<Game> create( const std::string& configFile );

    Game() {
        std::cout << "Game()\n";
    }

    ~Game() {
        std::cout << "~Game()\n";
    }

    bool init();
    void run();

    std::string getName() const { return name_; }
    void setName(const std::string& name) { name_ = name; }

private:
    std::string name_ = "SHM game.";
    std::unique_ptr<Player> player;
    std::unique_ptr<Map> map;
};

template <> std::unique_ptr<Game> JsonConvert::from_json( const Json& json );
template <> Json JsonConvert::to_json( const std::unique_ptr<Game>& game );
