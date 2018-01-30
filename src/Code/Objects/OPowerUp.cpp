/*
 * CPowerUp.cpp
 *
 *  Created on: 12 sty 2018
 *      Author: patryk
 */

#include "OPowerUp.h"
#include <Effects/EOutExtendFading.h>
#include <Managers/GameManager.h>
#include <Managers/PowerUpManager.h>

OPowerUp::OPowerUp(int type, float x, float y) {
	this->type = type;
	this->x = x;
	this->y = y;
	colname = "powerup";
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(20, 20));
	shape.setOrigin(10, 10);
	shape.setTexture(PowerUpManager::GetTexture(type));
}

void OPowerUp::Render() {
	GameManager::Window->draw(shape);
}

void OPowerUp::Update() {

	sf::Vector2f vec = shape.getPosition();
	vec.y += PowerUpManager::GetSpeed(type);
	shape.setPosition(vec);
	colshape = shape.getGlobalBounds();
}

void OPowerUp::HandleCollision(string name, CCollidable* other) {

}

OPowerUp::~OPowerUp() {
	new EOutExtendFading(10, 2.5,shape);
}

