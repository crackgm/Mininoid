/*
 * OBall.cpp
 *
 *  Created on: 13 wrz 2017
 *      Author: crackgmd
 */

#include "OBall.h"
#include <math.h>
#include <iostream>
#include "../Effects/ESpark.h"
using namespace std;

OBall::OBall(float x, float y) {
	this->x = x;
	this->y = y;
	Depth = -1;
	colname = "ball";
	shape.setPosition(x,y);
	shape.setSize(sf::Vector2f(18,18));
	shape.setOrigin(9, 9);
	shape.setTexture(TextureManager::GetTexture("ball"));
	colshape = shape.getGlobalBounds();
	speed = 8;
	ballvector = sf::Vector2f(cos(0.785398163)*speed,sin(0.785398163)*(-speed));
	collided = false;
}



void OBall::Update() {
	collided = false;
	this->x += ballvector.x;
	this->y += ballvector.y;
	this->shape.setPosition(this->x, this->y);

	if(this->x <= 42.5) {
		ballvector.x *= -1;
		for(int i=0; i < 5; i++) {
			new ESpark(42.5,y, 2, 20, 2, -80+ rand()%160, sf::Color::Yellow);
		}
	} else if(this->x >= 800-42.5) {
		ballvector.x *= -1;
		for(int i=0; i < 5; i++) {
			new ESpark(800-42.5,y, 2, 20, 2, +180 + -80+ rand()%160, sf::Color::Yellow);
		}
	}

	if(this->y <= 0) {
		this->y = 0;
		ballvector.y *= -1;
	}

	if(this->y >= 600) {
		this->y = 400;
		this->x = 500;
		ballvector = sf::Vector2f(cos(0.785398163)*speed,sin(0.785398163)*(-speed));
	}
	colshape = shape.getGlobalBounds();
}

void OBall::Render() {
	GameManager::Window->draw(shape);
}

void OBall::HandleCollision(string name, CCollidable * other) {
	if (name=="block") {
		if(!collided) {
			if(other->colshape.left < this->x && this->x < other->colshape.left+other->colshape.width) {
				if(other->colshape.top+other->colshape.height < this->y || this->y < other->colshape.top) {
					ballvector.y *= -1;
					//cout << "ycol" <<endl;
				}
			} else
				if(other->colshape.top+other->colshape.height >= this->y || this->y >= other->colshape.top) {
					ballvector.x *= -1;
					//cout << "xcol" << endl;
				}
			collided = true;
			delete other;
		}
	} else if (name=="paddle") {
		float angle = atan2f(y - 570, x - MouseManager::GetX());
		ballvector = sf::Vector2f(cos(angle)*speed, sin(angle)*speed);
	}

}

OBall::~OBall() {
	// TODO Auto-generated destructor stub
}

