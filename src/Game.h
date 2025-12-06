#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

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

    // Mouse Positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Game Logic
    unsigned points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;

    // Game Objects
    sf::RectangleShape enemy;
    std::vector<sf::RectangleShape> enemies;

    // Text Objects
    sf::Font font;
    sf::Text text;

public:
    // Constructor & Destructors
    Game();
    virtual ~Game();

    // Accessors
    const bool isWindowOpen() const;

    // Functions
    void initEnemies();
    void spawnEnemy();
    void pollEvents();
    void initText();

    // Update Functions
    void update();
    void updateMousePosition();
    void updateEnemies();
    void updateText();

    // Render Functions
    void render();
    void renderEnemies();
    void renderText();
};