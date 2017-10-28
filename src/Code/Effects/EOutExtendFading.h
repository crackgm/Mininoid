/*
 * EOutExtendFading.h
 *
 *  Created on: 28 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_EFFECTS_EOUTEXTENDFADING_H_
#define CODE_EFFECTS_EOUTEXTENDFADING_H_
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include "../BaseClasses/CEffect.h"
#include <SFML/Graphics.hpp>

class EOutExtendFading : public CDrawable, CEntity, CEffect {
public:
	float fade, scale, fadespeed, maxscale;
	sf::RectangleShape shape;
	EOutExtendFading(float fadespeed, float maxscale);
	EOutExtendFading(float fadespeed, float maxscale, sf::RectangleShape shape);
	void Render();
	void Update();
	bool CheckFinish();
	virtual ~EOutExtendFading();
};

#endif /* CODE_EFFECTS_EOUTEXTENDFADING_H_ */
