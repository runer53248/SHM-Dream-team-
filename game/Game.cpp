#include "../include/game/Game.hpp"

#include <iostream>

Game::Game( const std::string text ): text_( text ) {}

bool Game::init() { return true; }

void Game::run() { std::cout << "GAME : " << text_ << '\n'; }

template <> std::unique_ptr<Game> JsonConvert::from_json( const Json& json ) {
    auto text = json.getValue<std::string>( "GameName" );
    auto game = std::make_unique<Game>(text);
    return game;
}

template <> Json JsonConvert::to_json( const std::unique_ptr<Game>& game ) {
    Json json;
    json.putValue( "GameName", game->getText() );
    return json;
}
