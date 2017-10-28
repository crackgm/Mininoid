/*
 * EOutExtendFading.cpp
 *
 *  Created on: 28 paź 2017
 *      Author: crackgm
 */

#include "EOutExtendFading.h"
#include "../Managers.h"

#include <iostream>

using namespace std;

EOutExtendFading::EOutExtendFading(float fadespeed, float maxscale) {
	Visible = true;
	Depth = -100;
	scale = 1;
	fade = 255;
	this->fadespeed = fadespeed;
	this->maxscale = maxscale;

	// TODO Auto-generated constructor stub

}

EOutExtendFading::EOutExtendFading(float fadespeed, float maxscale, sf::RectangleShape shape) {
	Visible = true;
	Depth = 100;
	scale = 1;
	fade = 255;
	this->shape = shape;
	this->fadespeed = fadespeed;
	this->maxscale = maxscale;
	// TODO Auto-generated constructor stub
}

void EOutExtendFading::Update() {


	sf::Color col =shape.getFillColor();
	shape.setFillColor(sf::Color(col.r, col.g, col.b, fade));
	shape.setScale(scale,scale);
	if(fade>0) {
		fade-=fadespeed;
		scale += fadespeed/255 * maxscale;
	} else {
		fade = 0;
	}
}
void EOutExtendFading::Render() {
	GameManager::Window->draw(shape);
}

bool EOutExtendFading::CheckFinish() {
	if(fade<=0) {
		return true;
	}
	return false;
}

EOutExtendFading::~EOutExtendFading() {

}

