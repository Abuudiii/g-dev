#include <Game.h>

//=============================================================================
// CONSTRUCTORS & DESTRUCTORS
//=============================================================================

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

//=============================================================================
// INIT FUNCTIONS
//=============================================================================

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

//=============================================================================
// ACCESSORS
//=============================================================================

/**
 * @brief Checks if game is still running
 * @return bool
 */
const bool Game::isRunning() const {
    return this->window->isOpen();
}

//=============================================================================
// MODIFIERS
//=============================================================================

//=============================================================================
// UPDATE FUNCTIONS
//=============================================================================

/**
 * @brief Main update for game loop that handles all game related updates
 * @return (void)
 */
void Game::update() {
    this->pollEvents();
}

/**
 * @brief Polls for window events
 * @return (void)
 */
void Game::pollEvents() {

    // Poll Event Loop
    while(this->window->pollEvent(this->ev)) {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            break;

        default:
            break;
        }

    }
}

//=============================================================================
// RENDER FUNCTIONS
//=============================================================================

/**
 * @brief Main render loop that renders out all game related objects
 * @return (void)
 */
void Game::render() {
    this->window->clear();

    // Render Game Objects
    this->player.render(this->window);

    this->window->display();
}
