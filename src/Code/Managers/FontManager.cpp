/*
 * FontManager.cpp
 *
 *  Created on: 20 sie 2017
 *      Author: crackgm
 */

#include "../Managers.h"
#include <SFML/Graphics.hpp>
map<char*,sf::Font*> FontManager::Fonts;


sf::Font* FontManager::GetFont(char* fontname) {
	return FontManager::Fonts[fontname];
}

bool FontManager::LoadFont(char* filename, char* fontname) {
	sf::Font *fnt = new sf::Font();
	bool res = fnt->loadFromFile(filename);
	FontManager::Fonts.insert(pair<char*,sf::Font*>(fontname,fnt));
	return res;
}
void FontManager::DrawText(string text, float x, float y, char* font, int size, sf::Color &color) {
	sf::Text txt;
	txt.setString(text);
	txt.setFont(*FontManager::GetFont(font));
	txt.setCharacterSize(size);
	txt.setColor(color);
	txt.setPosition(x,y);
	GameManager::Window->draw(txt);
}
