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

    // Movement Attributes
    float movementSpeed;

    // Init Functions
    void initVariables();
    void initShape();

public:

    // Constructors
    Player(float x = 0.f, float y = 0.f);
    ~Player();

    // Accessors


    // Modifiers


    // Update Functions
    void update(sf::RenderTarget* target);
    void updateInput();

    // Render Functions
    void render(sf::RenderTarget* target);
};