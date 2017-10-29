/*
 * ETextComeFromLeft.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#include "ETextComeFromLeft.h"
#include <iostream>

using namespace std;

ETextComeFromLeft::ETextComeFromLeft(EText *txt, float time, float x) {
	this->txt = txt;
	this->alpha = 0;
	this->time = time*60;
	this->speed = x/this->time;
	this->aspeed = 255/this->time;
	this->x=0;
	this->toX = x;
}

void ETextComeFromLeft::Update() {
	this->x += this->speed;
	this->txt->x = this->x;
	this->alpha += this->aspeed;
	this->time--;
	this->txt->alpha = this->alpha;
}

bool ETextComeFromLeft::CheckFinish() {
	if (this->time<=0) {
		return true;
	}
	return false;
}

ETextComeFromLeft::~ETextComeFromLeft() {
	// TODO Auto-generated destructor stub
}

