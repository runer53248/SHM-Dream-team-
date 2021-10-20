#include "../include/game/Game.hpp"
#include "../utility/json/JsonSerializer.hpp"

#include <iostream>

int main() {
    { // for json creation
        auto game = std::make_unique<Game>( "SHM game." );
        JsonSerializer::put( "Game", game );
        JsonSerializer::putValue( "Options", 0, "name", "exit" );
        JsonSerializer::putValue( "Options", 1, "name", "load game" );
        JsonSerializer::putValue( "Options", 2, "name", "new game" );

        JsonSerializer::putValue( "Player", "Name", "player1" );
        JsonSerializer::putValue( "Player", "Money", 10'000 );
        JsonSerializer::putValue( "Player", "Day", 0 );

        JsonSerializer::putValue( "Ships", 10, "Ship", nullptr );
        JsonSerializer::putValue( "Islands", 10, "Island", nullptr );
        JsonSerializer::putValue( "Map", "name", "default" );
        JsonSerializer::putValue( "Map", "width", 10 );
        JsonSerializer::putValue( "Map", "height", 10 );
        JsonSerializer::putValue( "MapIsland", 0, "island", "Majorka" );
        JsonSerializer::putValue( "MapIsland", 1, "island", "Rodos" );
        JsonSerializer::putValue( "MapIsland", 2, "island", "Bali" );
        JsonSerializer::putValue( "MapIsland", 3, "island", "Grand Canari" );

        JsonSerializer::save( "./game/data/config.json" );
        JsonSerializer::clear();
    }

    if ( JsonSerializer::load( "./game/data/config.json" ) ) {
        if ( auto opt =
                 JsonSerializer::get<std::unique_ptr<Game>>( "Game", 0 ) ) {
            auto game = std::move(opt.value());
            if ( game->init() ) {
                game->run();
            }
        }
    }
    return 0;
}
