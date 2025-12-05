#include "Game.h"


/**
 * @brief Constructor
 * - Calls member variables for initialization
 */
Game::Game()
{
    // Init variables and window (heap allocation)
    this->initVariables();
    this->initWindow();
}


/**
 * @brief Destructor
 * Frees the heap allocated window pointer
 */
Game::~Game()
{
    // Freeing heap allocated memory
    delete this->window;
}

/**
 * @brief Polls for events
 * @return (void)
 * - Loops and checks for events
 * - Switch case handles appropriate actions
 */
void Game::update() {

    while (this->window->pollEvent(this->ev)) {

        switch (this->ev.type) {

            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;

            default:
                break;
        }
    }
}

/**
 * @brief Renders game objects
 * @return (void)
 * - Clears current frame
 * - Draws Objects
 * - Displays output to screen
 */
void Game::render() {

    this->window->clear(sf::Color(255, 0, 0, 255));

    // Draw Game

    this->window->display();
}

void Game::pollEvents() {

}


/**
 * @brief Initializes member variables
 * @return (void)
 * - Sets window to nullptr
 */
void Game::initVariables() {
    this->window = nullptr;
}


/**
 * @brief Initializes window
 * @return (void)
 * - Sets width and height
 * - Allocates new window on heap
 * - Initializes window with configured params
 */
void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Game!", sf::Style::Titlebar | sf::Style::Close);
}

/**
 * @brief Checks window status to allow polling
 * @return bool
 */
const bool Game::isWindowOpen() const {
    return this->window->isOpen();
} 