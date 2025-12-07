#include "Game.h"

int main() {
    // Init Srand
    srand(static_cast<unsigned>(time(0)));

    // Init Game Object
    Game game;

    // Game Loop
    while (game.isRunning()) {
        game.update();
        game.render();
    }

    // End of application
    return 0;
}