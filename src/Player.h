#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Player {

private:
    sf::RectangleShape shape;

    void initVariables();
    void initShapes();

public:

    // Constructors
    Player();
    ~Player();

}