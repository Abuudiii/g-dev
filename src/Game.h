#pragma once

#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Game {

private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;

    // Private Init Functions
    void initVariables();
    void initWindow();

public:
    // Constructors
    Game();
    ~Game();

    // Accessors (get from class)

    // Modifiers (modify stuff in class)

    // Init Functions
    
    // Update Functions
    void update();

    // Render Functions
    void render();
};