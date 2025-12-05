#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/**
 * @brief Game class to display output
 * @author Abdullah Sheikh
 * @since Thu Dec 04 2025
 */
class Game
{
private:
    // Private Members
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    // Private Functions
    void initVariables();
    void initWindow();

public:
    // Constructor & Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool isWindowOpen() const;

    // Functions
    void update();
    void render();
    void pollEvents();
};