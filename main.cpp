#include <iostream>
#include "Game.h"

using namespace sf;

int main() {

    // Init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    // Init Game Object
    Game game;

    // Game Looping
    while (game.isWindowOpen()) {
        // Update
        game.update();

        // Render
        game.render();
        
    } // Main Window Loop

    return 0;
}