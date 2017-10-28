/*
 * CCollidable.h
 *
 *  Created on: 21 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_BASECLASSES_CCOLLIDABLE_H_
#define CODE_BASECLASSES_CCOLLIDABLE_H_

#include "CEntity.h"
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class CCollidable {
public:
	CCollidable();
	bool colenable;
	string colname;
	sf::FloatRect colshape;
	virtual void HandleCollision(string name, CCollidable *other)=0;
	virtual ~CCollidable();
};

#endif /* CODE_BASECLASSES_CCOLLIDABLE_H_ */
