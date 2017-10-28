/*
 * OBlock.cpp
 *
 *  Created on: 5 wrz 2017
 *      Author: crackgm
 */

#include "OBlock.h"
#include "../Effects/EOutExtendFading.h"
#include <ctime>

OBlock::OBlock(float x, float y) {
	this->x = x;
	this->y = y;
	Depth = -1;
	colname = "block";
	shape.setPosition(x,y);
	shape.setSize(sf::Vector2f(55,20));
	shape.setOrigin(0, 0);
	shape.setTexture(TextureManager::GetTexture("block"));
	shape.setFillColor(sf::Color(rand()%256,rand()%256,rand()%256));
	colshape = shape.getGlobalBounds();
}


void OBlock::Update() {
	colshape = shape.getGlobalBounds();
}

void OBlock::HandleCollision(string name, CCollidable *other) {

}

void OBlock::Render() {
	GameManager::Window->draw(shape);
}
OBlock::~OBlock() {
	shape.setPosition(x+55/2,y+20/2);
	shape.setOrigin(55/2, 20/2);
	new EOutExtendFading(10, 2.5,shape);
	// TODO Auto-generated destructor stub
}

