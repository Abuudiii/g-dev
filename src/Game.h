#pragma once

#include <iostream>
#include <vector>

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

    // Mouse Positions
    sf::Vector2i mousePosWindow;

    // Game Logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    // Game Objects
    sf::RectangleShape enemy;
    std::vector<sf::RectangleShape> enemies;

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

    // Update Functions
    void update();
    void updateMousePosition();
    void updateEnemies();

    // Render Functions
    void render();
    void renderEnemies();
};