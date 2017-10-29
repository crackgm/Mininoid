/*
 * EText.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_EFFECTS_ETEXT_H_
#define CODE_EFFECTS_ETEXT_H_
#include <SFML/Graphics.hpp>
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include <string>
using namespace std;
class EText : public CDrawable, CEntity {
public:
	EText(string text, float x, float y, char* font, int size, sf::Color color, int alpha = 255, bool centered=true);
	string text;
	char *font;
	float x, y;
	int size, alpha;
	sf::Color color;
	bool centered;
	sf::Text txt;
	void Render();
	void Update();
	float scale, angle;
	virtual ~EText();
};

#endif /* CODE_EFFECTS_ETEXT_H_ */
