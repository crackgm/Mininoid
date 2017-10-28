/*
 * OBlock.h
 *
 *  Created on: 5 wrz 2017
 *      Author: crackgm
 */

#ifndef CODE_OBJECTS_OBLOCK_H_
#define CODE_OBJECTS_OBLOCK_H_

#include "../Managers.h"
#include "../BaseClasses/CCollidable.h"
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include <SFML/Graphics.hpp>
class OBlock : public CCollidable, CDrawable, CEntity {
public:
	float x, y;
	sf::RectangleShape shape;
	void HandleCollision(string name, CCollidable *other);
	void Render();
	void Update();
	OBlock(float x, float y);
	virtual ~OBlock();
};
#endif /* CODE_OBJECTS_OBLOCK_H_ */
