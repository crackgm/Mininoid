/*
 * ESpark.cpp
 *
 *  Created on: 28 paź 2017
 *      Author: crackgm
 */

#include "ESpark.h"
#include "../Managers.h"
#include <cmath>
ESpark::ESpark(float x, float y, float size, float length, float speed, float direction, sf::Color color){
	this->Visible = true;
	this->Depth = 100;
	this->speed = speed;
	this->direction = direction;
	shape.setSize(sf::Vector2f(length,size));
	shape.setRotation(direction);
	shape.setFillColor(color);
	shape.setPosition(x,y);
	this->x = x;
	this->y = y;
	this->alpha=255;
	shape.setOrigin(1,size/2);
}

void ESpark::Update() {
	shape.setPosition(x,y);
	y += speed*sin(direction*3.14/180);
	x += speed*cos(direction*3.14/180);
	sf::Color col =shape.getFillColor();
	shape.setFillColor(sf::Color(col.r, col.g, col.b, alpha));

	if(alpha>0) {
		alpha -= speed*15;
	} else if(alpha<=0){
		alpha = 0;
	}
}

void ESpark::Render() {
	GameManager::Window->draw(shape);
}

bool ESpark::CheckFinish() {
	if(alpha<=0) return true;
	return false;
}

ESpark::~ESpark() {
	// TODO Auto-generated destructor stub
}

