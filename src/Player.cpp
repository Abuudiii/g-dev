#include "Player.h"

/**
 * @brief Constructor
 */
Player::Player() {
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

}

void Player::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}