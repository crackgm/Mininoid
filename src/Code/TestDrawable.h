/*
 * TestDrawable.h
 *
 *  Created on: 19 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_TESTDRAWABLE_H_
#define CODE_TESTDRAWABLE_H_

#include "BaseClasses/CDrawable.h"
#include <SFML/Graphics.hpp>
#include "Managers.h"
#include <iostream>

using namespace std;

class TestDrawable: public CDrawable, CCollidable {
public:
	sf::CircleShape shape;
	TestDrawable() {
		colname = "test";
		colshape = shape.getGlobalBounds();
		shape.setRadius(100.f);
	    shape.setTexture(TextureManager::GetTexture("test"));
	}
	void Render() {
		colshape = shape.getGlobalBounds();
		shape.setPosition(MouseManager::GetX(), MouseManager::GetY());
		GameManager::Window->draw(shape);
	}

	void HandleCollision(string name) {
		if(name=="test2") {
			shape.setRadius(10.0f);
		}

	}

};

#endif /* CODE_TESTDRAWABLE_H_ */
