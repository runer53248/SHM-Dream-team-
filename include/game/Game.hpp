#pragma once
#include "../utility/json/JsonSerializer.hpp"

#include <string>

class Game {
public:
    Game( const std::string text );

    bool init();
    void run();

    std::string getText() const { return text_; }

private:
    std::string text_ = "SHM game.";
};

template <> std::unique_ptr<Game> JsonConvert::from_json( const Json& json );
template <> Json JsonConvert::to_json( const std::unique_ptr<Game>& game );
