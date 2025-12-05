#include "Game.h"

/*
    Constructor and Destructor
*/
Game::Game()
{
    // Init variables and window (heap allocation)
    this->initVariables();
    this->initWindow();
}


Game::~Game()
{
    // Freeing heap allocated memory
    delete this->window;
}

/*
    Public Function Definitions
*/
void Game::update() {

    /*
        Polls for events
        1. Switch case checks for events occuring
        2. Takes acion accordingly
    */
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

void Game::render() {

    /*
        Renders game objects
        1. Clear old display
        2. Draw objects
        3. Display frame in window
    */

    this->window->clear(sf::Color(255, 0, 0, 255));

    // Draw Game

    this->window->display();
}

void Game::pollEvents() {

}

/*
    Private Function Definitions
*/
void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->videoMode.getDesktopMode;
    this->window = new sf::RenderWindow(this->videoMode, "Game!", sf::Style::Titlebar | sf::Style::Close);
}

/*
    Accessor Functions
*/
const bool Game::isWindowOpen() const {
    return this->window->isOpen();
} 