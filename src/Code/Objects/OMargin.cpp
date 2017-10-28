/*
 * OMargin.cpp
 *
 *  Created on: 5 wrz 2017
 *      Author: crackgm
 */

#include "OMargin.h"

OMargin::OMargin(float x) {
	this->x = x;
	Depth = -1;
		colname = "margin";
		shape.setPosition(x,0);
		shape.setSize(sf::Vector2f(42.5,600));
		shape.setOrigin(0, 0);
		shape.setFillColor(sf::Color(125,125,125));
		colshape = shape.getGlobalBounds();
	// TODO Auto-generated constructor stub

}

OMargin::~OMargin() {
	// TODO Auto-generated destructor stub
}

void OMargin::HandleCollision(string name, CCollidable *other) {

}

void OMargin::Render() {
	GameManager::Window->draw(shape);
}
