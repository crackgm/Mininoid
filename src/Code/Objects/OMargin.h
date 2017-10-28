/*
 * OMargin.h
 *
 *  Created on: 5 wrz 2017
 *      Author: crackgm
 */

#ifndef CODE_OBJECTS_OMARGIN_H_
#define CODE_OBJECTS_OMARGIN_H_
#include "../Managers.h"
#include "../BaseClasses/CCollidable.h"
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include <SFML/Graphics.hpp>
class OMargin : public CCollidable, CDrawable {
public:
	OMargin(float x);
	float x;
	sf::RectangleShape shape;
	virtual ~OMargin();
	void Render();
	void HandleCollision(string name, CCollidable *other);
};

#endif /* CODE_OBJECTS_OMARGIN_H_ */
