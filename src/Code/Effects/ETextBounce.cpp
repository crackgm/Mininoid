/*
 * ETextBounce.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#include "ETextBounce.h"
#include <cmath>

ETextBounce::ETextBounce(EText *txt, float time) {
	this->txt = txt;
	this->time = time*60;
	this->scale = 1;
	this->angle = 0;
	this->temp = 0;
	this->speed = 3.14/this->time;
	// TODO Auto-generated constructor stub

}

void ETextBounce::Update() {
	this->scale = 1 + sin(this->temp)/2;
	this->angle = sin(this->temp*2)*2;
	this->temp += this->speed;
	this->txt->scale = this->scale;
	this->txt->angle = this->angle;
	this->time--;
}

bool ETextBounce::CheckFinish() {
	if(this->time <= 0) {
		return true;
	}
	return false;
}

ETextBounce::~ETextBounce() {
	// TODO Auto-generated destructor stub
}

