/*
 * OBall.h
 *
 *  Created on: 13 wrz 2017
 *      Author: crackgm
 */

#ifndef CODE_OBJECTS_OBALL_H_
#define CODE_OBJECTS_OBALL_H_
#include "../Managers.h"
#include "../BaseClasses/CCollidable.h"
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include <SFML/Graphics.hpp>

class OBall: public CCollidable, CDrawable, CEntity {
public:
	float x, y;
	bool collided;
	sf::Vector2f ballvector;
	float speed;
	sf::RectangleShape shape;
	void HandleCollision(string name, CCollidable *other);
	void Render();
	void Update();
	OBall(float x, float y);
	virtual ~OBall();
};

#endif /* CODE_OBJECTS_OBALL_H_ */
