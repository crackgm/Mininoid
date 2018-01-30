/*
 * CPowerUp.h
 *
 *  Created on: 12 sty 2018
 *      Author: patryk
 */

#ifndef CODE_POWERUPS_OPOWERUP_H_
#define CODE_POWERUPS_OPOWERUP_H_
#include <BaseClasses/CCollidable.h>
#include <BaseClasses/CEntity.h>
#include <BaseClasses/CDrawable.h>
#include <SFML/Graphics.hpp>

class OPowerUp : public CEntity, CDrawable, CCollidable  {
public:
	OPowerUp(int type, float x, float y);
	void Render();
	void Update();
	void HandleCollision(string name, CCollidable *other);
	int type;
	sf::RectangleShape shape;
	float x, y;
	virtual ~OPowerUp();
};

#endif /* CODE_POWERUPS_OPOWERUP_H_ */
