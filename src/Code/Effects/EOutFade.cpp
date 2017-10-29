/*
 * EFadeOut.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */
#include "EOutFade.h"
#include "../Managers.h"

#include <iostream>

using namespace std;

EOutFade::EOutFade(float fadespeed) {
	Visible = true;
	Depth = -100;
	fade = 255;
	this->fadespeed = fadespeed;

	// TODO Auto-generated constructor stub

}

EOutFade::EOutFade(float fadespeed, sf::RectangleShape shape) {
	Visible = true;
	Depth = -2;
	fade = 255;
	this->shape = shape;
	this->fadespeed = fadespeed;
	// TODO Auto-generated constructor stub
}

void EOutFade::Update() {


	sf::Color col =shape.getFillColor();
	shape.setFillColor(sf::Color(col.r, col.g, col.b, fade));
	if(fade>0) {
		fade-=fadespeed;
	} else {
		fade = 0;
	}
}
void EOutFade::Render() {
	GameManager::Window->draw(shape);
}

bool EOutFade::CheckFinish() {
	if(fade<=0) {
		return true;
	}
	return false;
}

EOutFade::~EOutFade() {

}

