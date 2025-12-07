#include <Game.h>

/**
 * @brief Constructor to initialize
 */
Game::Game() {
    this->initVariables();
    this->initWindow();
}

/**
 * @brief Destructor to clean up heap allocated memory
 */
Game::~Game() {
    delete this->window;
}

/**
 * @brief Inits member variables
 * @return (void)
 */
void Game::initVariables() {
    this->endGame = false;
}

/**
 * @brief Sets up window and its attributes
 * @return (void)
 */
void Game::initWindow() {
    this->videoMode = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(this->videoMode, "Game Practice!", sf::Style::Close | sf::Style::Titlebar);
}

/**
 * @brief Main update for game loop that handles all game related updates
 * @return (void)
 */
void Game::update() {
    
}

/**
 * @brief Main render loop that renders out all game related objects
 * @return (void)
 */
void Game::render() {
    this->window->clear();

    // Render Game Objects

    this->window->display();
}