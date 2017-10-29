/*
 * ETextLeaveToLeft.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#include "ETextLeaveToLeft.h"

ETextLeaveToLeft::ETextLeaveToLeft(EText *txt, float time, float x) {
	this->txt = txt;
	this->alpha = 255;
	this->time = time*60;
	this->speed = txt->x/this->time;
	this->aspeed = 255/this->time;
	this->x=this->txt->x;
	this->startx = x;

}
void ETextLeaveToLeft::Update() {
	this->x -= this->speed;
	this->txt->x = this->x;
	this->alpha -= this->aspeed;
	this->time--;
	if(this->alpha < 0) {
		this->alpha = 0;
	}
	this->txt->alpha = this->alpha;

}

bool ETextLeaveToLeft::CheckFinish() {
	if (this->time<=0) {
		return true;
	}
	return false;
}

ETextLeaveToLeft::~ETextLeaveToLeft() {
	// TODO Auto-generated destructor stub
}

