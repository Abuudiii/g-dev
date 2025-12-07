#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Player {

private:
    // Object Attributes
    sf::RectangleShape shape;

    // Init Functions
    void initVariables();
    void initShape();

public:

    // Constructors
    Player();
    ~Player();

    // Accessors


    // Modifiers


    // Update Functions
    void update();

    // Render Functions
    void render(sf::RenderTarget* target);
};