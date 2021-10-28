#include "../include/game/Game.hpp"
#include "../include/game/Map.hpp"
#include "../include/game/Player.hpp"

#include <iostream>

std::unique_ptr<Game> Game::create( const std::string& configFile ) {
    JsonSerializer::clear();
    if ( JsonSerializer::load( configFile ) ) {
        if ( auto opt =
                 JsonSerializer::get<std::unique_ptr<Game>>( "Game", 0 ) ) {
            auto game = std::move( opt.value() );
            return game;
        }
    }
    return {};
}

Game::Game() { std::cout << "Game()\n"; }

Game::~Game() { std::cout << "~Game()\n"; }

bool Game::init() {
    // here we can for example set diffrent json files to player and map
    // or give player some options to chose
    player = Player::create();
    map = Map::create();
    return player && map;
}

void Game::run() { mainLoop(); }

void Game::mainLoop() {
    bool finish = false;
    while ( !finish ) {
        std::cout << "GAME : " << name_ << '\n';
        if ( player ) {
            std::cout << "Player name : " << player->getName() << '\n';
            std::cout << "Player money : " << player->getMoney() << '\n';
        }

        if ( map ) {
            std::cout << "Map size : " << map->getSize().x << " X "
                      << map->getSize().y << '\n';
        }

        std::cout << "Press [Enter] to end game.\n";
        std::getchar();
        finish = true;
    }
    std::cout << "Game " << std::quoted(getName()) << " ended.\n";
}

std::string Game::getName() const { return name_; }
void Game::setName( const std::string& name ) { name_ = name; }

template <> std::unique_ptr<Game> JsonConvert::from_json( const Json& json ) {
    auto text = json.getValue<std::string>( "GameName" );

    auto game = std::unique_ptr<Game>( new Game() );

    game->setName( text );
    return game;
}

template <> Json JsonConvert::to_json( const std::unique_ptr<Game>& game ) {
    Json json;
    json.putValue( "GameName", game->getName() );
    return json;
}
