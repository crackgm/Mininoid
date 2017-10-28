/*
 * ESpark.h
 *
 *  Created on: 28 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_EFFECTS_ESPARK_H_
#define CODE_EFFECTS_ESPARK_H_
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEffect.h"
#include "../BaseClasses/CEntity.h"
#include <SFML/Graphics.hpp>

class ESpark : public CDrawable, CEntity, CEffect {
public:
	float speed, direction, x, y, alpha;
	sf::RectangleShape shape;
	ESpark(float x, float y, float size, float length, float speed, float direction, sf::Color color);
	bool CheckFinish();
	void Update();
	void Render();
	virtual ~ESpark();
};

#endif /* CODE_EFFECTS_ESPARK_H_ */
