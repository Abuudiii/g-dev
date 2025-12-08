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
    this->updateInput();
}

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


void Player::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}