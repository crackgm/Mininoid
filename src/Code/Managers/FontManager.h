/*
 * FontManager.h
 *
 *  Created on: 20 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_MANAGERS_FONTMANAGER_H_
#define CODE_MANAGERS_FONTMANAGER_H_
#include <SFML/Graphics.hpp>
#include <map>
#include <cstdlib>

using namespace std;

class FontManager {
private:
	static map<char*,sf::Font*> Fonts;
public:
	static bool LoadFont(char* filename, char* fontname);
	static sf::Font* GetFont(char* fontname);
	static void DrawText(string text, float x, float y, char* font, int size, sf::Color color);
};

#endif /* CODE_MANAGERS_FONTMANAGER_H_ */
