#include "Player.h"

//=============================================================================
// CONSTRUCTORS & DESTRUCTORS
//=============================================================================

/**
 * @brief Constructor
 */
Player::Player(float x, float y) {
    this->shape.setPosition(x , y);

    this->initVariables();
    this->initShape();
}

/**
 * @brief Destructor
 */
Player::~Player() {

}

//=============================================================================
// INIT FUNCTIONS
//=============================================================================

/**
 * @brief Inits member variables
 * @return (void)
 */
void Player::initVariables() {
    this->movementSpeed = 10.f;
}

/**
 * @brief Inits member shape
 * @return (void)
 */
void Player::initShape() {
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

//=============================================================================
// ACCESSORS
//=============================================================================

//=============================================================================
// MODIFIERS
//=============================================================================

//=============================================================================
// UPDATE FUNCTIONS
//=============================================================================

/**
 * @brief Calls Player objects update related functionality
 * @return (void)
 */
void Player::update() {
    this->updateInput();
}

/**
 * @brief Allows user to move player with WASD keys
 * @return (void)
 */
void Player::updateInput() {

    // Keyboard Input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->shape.move(-this->movementSpeed, 0.f);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->shape.move(this->movementSpeed, 0.f);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->shape.move(0.f, -this->movementSpeed);

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->shape.move(0.f, this->movementSpeed);

    }

}

//=============================================================================
// RENDER FUNCTIONS
//=============================================================================

/**
 * @brief Updated player object to target window
 * @param target
 * @return (void)
 */
void Player::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}
