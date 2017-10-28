/*
 * TestCollidable.h
 *
 *  Created on: 21 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_TESTCOLLIDABLE_H_
#define CODE_TESTCOLLIDABLE_H_
#include "Managers.h"
#include "BaseClasses/CDrawable.h"
#include "BaseClasses/CCollidable.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class TestCollidable : public CDrawable, CCollidable {
public:
	sf::RectangleShape shape;
	TestCollidable() {
		shape.setSize(sf::Vector2f(100,100));
		shape.setFillColor(sf::Color::Red);
		shape.setPosition(200,200);

		colname = "test2";
		colshape = shape.getGlobalBounds();
	}
	void Render() {
		GameManager::Window->draw(shape);
	}

	void HandleCollision(string name) {
		if(name == "test") {
			delete this;
		}
	}
};

#endif /* CODE_TESTCOLLIDABLE_H_ */
