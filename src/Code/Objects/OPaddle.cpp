/*
 * OPaddle.cpp
 *
 *  Created on: 30 sie 2017
 *      Author: crackgm
 */

#include "OPaddle.h"
#include <SFML/Graphics.hpp>
#include "../Effects/ESpark.h"
#include "../Effects/EOutFade.h"
#include <ctime>
OPaddle::OPaddle() {
	Depth = -1;
	colname = "paddle";
	shape.setSize(sf::Vector2f(142,22));
	shape.setOrigin(142/2, 22/2);
	shape.setTexture(TextureManager::GetTexture("paddle"));
	colshape = shape.getGlobalBounds();
	yanim = 0;
}

void OPaddle::Update() {
	if(MouseManager::GetX()>71+42.5)
		if(MouseManager::GetX()<729-42.5)
			shape.setPosition(MouseManager::GetX(), 570);
		else shape.setPosition(729-42.5, 570);
	else shape.setPosition(71+42.5, 570);
	if(yanim>0) {
		yanim -= 0.5;
	}
	if(yanim < 0) {
		yanim = 0;
	}
	shape.setPosition(shape.getPosition().x, 570+yanim);
	colshape = shape.getGlobalBounds();
	new EOutFade(50, shape);
}

void OPaddle::Render() {

	GameManager::Window->draw(shape);
}

void OPaddle::HandleCollision(string name, CCollidable *other) {
	if(name=="ball") {
		if(yanim == 0) yanim = 10;
		for(int i=0; i < 5; i++) {
			new ESpark(other->colshape.left+other->colshape.width/2, shape.getPosition().y, 2, 20, 2, 190+ rand()%160, sf::Color::Yellow);
		}
	} else if (name=="powerup") {

		delete other;
	}
}

OPaddle::~OPaddle() {
	// TODO Auto-generated destructor stub
}

