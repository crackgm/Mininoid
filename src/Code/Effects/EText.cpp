/*
 * EText.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#include "EText.h"
#include <SFML/Graphics.hpp>
#include "../Managers.h"

#include <iostream>

using namespace std;

EText::EText(string text, float x, float y, char* font, int size, sf::Color color, int alpha, bool centered) {
	this->text = text;
	this->x = x;
	this->y = y;
	this->font = font;
	this->size = size;
	this->color = color;
	this->centered = centered;
	this->angle = 0;
	this->scale = 1;
	this->alpha = alpha;
	this->Depth = 200;
	// TODO Auto-generated constructor stub

}

void EText::Update() {
	txt.setString(this->text);
	txt.setFont(*FontManager::GetFont(font));
	txt.setCharacterSize(size);
	this->color.a = this->alpha;
	txt.setColor(color);
	txt.setPosition(x,y);
	txt.setScale(this->scale, this->scale);
	txt.setRotation(this->angle);
	txt.setStyle(sf::Text::Bold);
	if (centered) {
		sf::FloatRect textRect = txt.getGlobalBounds();
		txt.setOrigin(textRect.width/2, textRect.height/2);
	} else {
		txt.setOrigin(0, 0);
	}
}

void EText::Render() {
	GameManager::Window->draw(this->txt);
}

EText::~EText() {
	GameManager::Window->draw(this->txt);
}

