#include "../include/game/Game.hpp"

int main() {
    auto game = Game::create("config.json");
    if(game) {
        if(game->init()){
            game->run();
        }
    }
    return 0;
}
