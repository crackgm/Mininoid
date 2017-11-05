/*
 * CNotification.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#include "CNotification.h"
#include "../Managers.h"
#include<SFML/Graphics.hpp>
CNotification::CNotification(string message, int time, sf::Color rectColor, sf::Color textColor) {
	this->message = message;
	this->time = time;
	this->rectColor = rectColor;
	this->textColor = textColor;
	this->shape.setFillColor(sf::Color(this->rectColor.r,this->rectColor.g,this->rectColor.b, 127));
	this->shape.setSize(sf::Vector2f(800, 20));
	this->timeOn = 0;
	this->shape.setPosition(0,-20);
}


void CNotification::SetY(float y) {
	this->shape.setPosition(0, y);
}

float CNotification::GetY() {
	return (this->shape.getPosition().y);
}

void CNotification::Update() {
	this->timeOn++;
}

bool CNotification::IsDone() {
	if(timeOn/60 == time) {
		return true;
	}
	return false;
}

void CNotification::Render() {
	GameManager::Window->draw(shape);
	FontManager::DrawText(this->message.c_str(), 20, this->GetY()+5, "Verdana", 10, this->textColor);
}

CNotification::~CNotification() {
	// TODO Auto-generated destructor stub
}

