#include "../include/game/Game.hpp"

#include <iostream>

int main() {
    Game game;
    if ( game.init() ) {
        game.run();
    }
    return 0;
}
