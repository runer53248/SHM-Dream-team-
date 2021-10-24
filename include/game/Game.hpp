#pragma once
#include "../../include/game/Map.hpp"
#include "../../include/game/Player.hpp"
#include "../utility/json/JsonSerializer.hpp"

#include <iostream>
#include <memory>
#include <string>

class Game {
    template <typename T = std::unique_ptr<Game>> 
    friend T JsonConvert::from_json( const Json& json );
public:
    static std::unique_ptr<Game> create( const std::string& configFile );

    ~Game();

    bool init();
    void run();

    std::string getName() const;
    void setName( const std::string& name );

private:
    Game();

    std::string name_ = "SHM game.";
    std::unique_ptr<Player> player;
    std::unique_ptr<Map> map;
};

template <> std::unique_ptr<Game> JsonConvert::from_json( const Json& json );
template <> Json JsonConvert::to_json( const std::unique_ptr<Game>& game );
