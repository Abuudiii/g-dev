#include "Player.h"

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
    this->shape.setSize(sf::Vector2f(100.f, 100.f));
}

void Player::update() {


    // Keyboard Input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

    }
}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}