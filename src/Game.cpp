#include "Game.h"

/**
 * @brief Constructor
 * - Calls member variables and initializes them
 * - Uses init functions to do this
 */
Game::Game()
{
    // Init variables and window (heap allocation)
    this->initVariables();
    this->initWindow();
    this->initEnemies();
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
 * @brief Initializes member variables
 * @return (void)
 * - Sets window to nullptr
 */
void Game::initVariables() {
    this->window = nullptr;

    // Game Logic
    this->points = 0;
    this->enemySpawnTimer = 0.f;  
    this->enemySpawnTimerMax = 1000.f;
    this->maxEnemies = 5;
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

    this->window->setFramerateLimit(100);
}


/**
 * @brief Initializes and configures enemy object
 * @return (void)
 */
void Game::initEnemies() {
    this->enemy.setPosition(this->videoMode.height/2, this->videoMode.width/2);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(2.f, 2.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Red);
    this->enemy.setOutlineThickness(1.f);
}








/**
 * @brief Checks window status to allow polling
 * @return bool
 */
const bool Game::isWindowOpen() const {
    return this->window->isOpen();
} 



/**
 * @brief Polls for events
 * @return (void)
 * - Loops and checks for events
 * - Switch case handles appropriate actions
 */
void Game::pollEvents() {
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
 * @brief Handles logic for mouse position member variable
 * @return (void)
 */
void Game::updateMousePosition() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::spawnEnemy() {
    
}

/**
 * @brief Keeps track of time and spawns enemies accordingly.
 * @return (void)
 */
void Game::updateEnemies() {

    // Spawning enemy based off a time and resetting the timer
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            // Spawn Enemy
            this->spawnEnemy();
            this->enemySpawnTimer =0.f;
        } else {
            this->enemySpawnTimer += 1.f;
        }
    }
}

void Game::renderEnemies() {

}








/**
 * @brief Polls for events and makes appropriate updates
 * @return (void)
 */
void Game::update() {
    this->pollEvents();

    this->updateEnemies(); 

    this->updateMousePosition();
}

/**
 * @brief Renders game objects
 * @return (void)
 * - Clears current window
 * - Draws Objects
 * - Displays output to screen
 */
void Game::render() {
    
    this->window->clear();
    
    // Draw Game
    this->renderEnemies();
    
    this->window->display();
}