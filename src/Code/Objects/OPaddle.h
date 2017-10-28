/*
 * OPaddle.h
 *
 *  Created on: 30 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_OBJECTS_OPADDLE_H_
#define CODE_OBJECTS_OPADDLE_H_
#include "../Managers.h"
#include "../BaseClasses/CCollidable.h"
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include <SFML/Graphics.hpp>
class OPaddle : public CCollidable, CDrawable, CEntity {
public:
	float yanim;
	sf::RectangleShape shape;
	void HandleCollision(string name, CCollidable *other);
	void Render();
	void Update();
	OPaddle();
	virtual ~OPaddle();
};

#endif /* CODE_OBJECTS_OPADDLE_H_ */
