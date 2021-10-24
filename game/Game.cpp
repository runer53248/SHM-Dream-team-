#include "../include/game/Game.hpp"

#include <iostream>

std::unique_ptr<Game> Game::create( const std::string& configFile ) {
    JsonSerializer::clear();
    if ( JsonSerializer::load( configFile ) ) {
        if ( auto opt =
                 JsonSerializer::get<std::unique_ptr<Game>>( "Game", 0 ) ) {
            auto game = std::move( opt.value() );

            game->player = Player::create();
            game->map = Map::create();

            return game;
        }
    }
    return {};
}

Game::Game() { std::cout << "Game()\n"; }

Game::~Game() { std::cout << "~Game()\n"; }

bool Game::init() { return true; }

void Game::run() {
    std::cout << "GAME : " << name_ << '\n';
    if ( player ) {
        std::cout << "Player name : " << player->getName() << '\n';
        std::cout << "Player money : " << player->getMoney() << '\n';
    }

    if ( map ) {
        std::cout << "Map size : " << map->getSize().x << " X "
                  << map->getSize().y << '\n';
    }
}

std::string Game::getName() const { return name_; }
void Game::setName( const std::string& name ) { name_ = name; }

template <> std::unique_ptr<Game> JsonConvert::from_json( const Json& json ) {
    auto text = json.getValue<std::string>( "GameName" );

    auto game = std::unique_ptr<Game>(new Game());

    game->setName( text );
    return game;
}

template <> Json JsonConvert::to_json( const std::unique_ptr<Game>& game ) {
    Json json;
    json.putValue( "GameName", game->getName() );
    return json;
}
