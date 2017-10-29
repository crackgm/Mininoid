/*
 * EOutFade.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */


#ifndef CODE_EFFECTS_EOUTFADE_H_
#define CODE_EFFECTS_EOUTFADE_H_
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include "../BaseClasses/CEffect.h"
#include <SFML/Graphics.hpp>

class EOutFade : public CDrawable, CEntity, CEffect {
public:
	float fade, fadespeed;
	sf::RectangleShape shape;
	EOutFade(float fadespeed);
	EOutFade(float fadespeed, sf::RectangleShape shape);
	void Render();
	void Update();
	bool CheckFinish();
	virtual ~EOutFade();
};


#endif /* CODE_EFFECTS_EOUTFADE_H_ */
