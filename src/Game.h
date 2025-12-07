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

    // Game Loop Variables
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    sf::Event ev;
    bool endGame;

    // Private Init Functions
    void initVariables();
    void initWindow();

public:
    // Constructors
    Game();
    ~Game();

    // Accessors (get from class)
    const bool isRunning() const;
    void pollEvents();

    // Modifiers (modify stuff in class)

    // Init Functions
    
    // Update Functions
    void update();

    // Render Functions
    void render();
}; 