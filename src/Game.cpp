#include "Game.h"

//=============================================================================
// CONSTRUCTORS & DESTRUCTORS
//=============================================================================

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
    this->initText();
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

//=============================================================================
// INIT FUNCTIONS
//=============================================================================

/**
 * @brief Initializes member variables
 * @return (void)
 * - Sets window to nullptr
 */
void Game::initVariables() {
    // Window Init
    this->window = nullptr;

    // Game Logic
    this->points = 0;
    this->enemySpawnTimerMax = 50.f;
    this->enemySpawnTimer = 0.f;
    this->maxEnemies = 50;
    this->mouseHeld = false;
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
    this->enemy.setSize(sf::Vector2f(10.f, 10.f));
    this->enemy.setScale(sf::Vector2f(2.f, 2.f));
    this->enemies.reserve(this->maxEnemies);
    // this->enemy.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

/**
 * @brief Initializes font for text
 * @return (void)
 * - Loads font file and inits text
 * - Configures font attributes
 */
void Game::initText() {

    // Loads font and configures text
    this->font.loadFromFile("../src/fonts/Arial.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(20);
    this->text.setStyle(sf::Text::Bold);
    this->text.setFillColor(sf::Color::Red);
}

//=============================================================================
// UPDATE FUNCTIONS
//=============================================================================

/**
 * @brief Polls for events and makes appropriate updates
 * @return (void)
 */
void Game::update() {
    this->pollEvents();
    this->updateMousePosition();
    this->updateEnemies();
    this->updateText();
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
 * @brief Handles logic for mouse position
 * @return (void)
 */
void Game::updateMousePosition() {
    // We take window and map to view as floats
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

/**
 * @brief Keeps track of time and spawns enemies accordingly
 * @return (void)
 * - Spawns new enemies based off timer
 * - Checks if enemies are out of frames or dead and deletes
 * - Basically handles the frame by frame update logic
 */
void Game::updateEnemies() {

    // Spawning enemy based off a time and resetting the timer
    if (this->enemies.size() < this->maxEnemies) { 
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {

            // Spawn Enemy
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;

        } else {

            // Increment timer for each update
            this->enemySpawnTimer += 1.f;

        }
    }

    // Move and update enemies
    for (int i = 0; i < this->enemies.size(); i++) {
        this->enemies[i].move(0.f, 2.f);

        // Delete if clicked
        if (this->enemies[i].getPosition().y > this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i); // Using iterator + ith index to delete the right enemy object
        }
    } // End of for loop

    // Check if mouse is clicked
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        
        // Check to ensure mouse can't be held
        if (this->mouseHeld == false) {

            this->mouseHeld = true;
            bool deleted = false; // Variable to track if an object needs deleting

            // Loop and delete if needed
            for (size_t i  = 0; i < this->enemies.size() && deleted == false; i++) {

                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                    // Deleted enemy if clicked on
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                    // Gain Points
                    this->points += 1.f;
                }
            } // End of for loop
        } 
        
    } else {
            this->mouseHeld = false;
    }
}

/**
 * @brief Updates our text to show count as it updates
 * @return (void)
 */
void Game::updateText() {
    this->text.setString("Points: " + std::to_string(this->points));
}

//=============================================================================
// HELPER FUNCTIONS
//=============================================================================

/**
 * @brief Checks window status to allow polling
 * @return bool
 */
const bool Game::isWindowOpen() const {
    return this->window->isOpen();
}

/**
 * @brief Spawns enemies and configures attributes
 * @return (void)
 * - Calculates position to stay within frame
 * - Sets enemy color
 * - Pushes enemy to vector
 */
void Game::spawnEnemy() {
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );

    this->enemy.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

    // Spawns Enemy
    this->enemies.emplace_back(this->enemy);
}

//=============================================================================
// RENDER FUNCTIONS
//=============================================================================

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
    this->renderText();

    this->window->display();
}

/**
 * @brief Renders each enemy in vector
 * @return (void)
 */
void Game::renderEnemies() {
    for(auto& x : this->enemies) {
        this->window->draw(x);
    }
}

/**
 * @brief Draws font to window
 * @return (void)
 */
void Game::renderText() {
    this->window->draw(this->text);
}
