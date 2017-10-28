/*
 * TestState.h
 *
 *  Created on: 19 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_TESTSTATE_H_
#define CODE_TESTSTATE_H_

#include "BaseClasses/CState.h"
#include "BaseClasses/CDrawable.h"
#include "TestDrawable.h"
#include "TestCollidable.h"
#include <SFML/Graphics.hpp>
#include "Managers.h"
#include "Objects/OPaddle.h"
#include "Objects/OBlock.h"
#include "Objects/OMargin.h"
#include "Objects/OBall.h"

class TestState: public CState {
	OPaddle *paddle;
	OBlock *blocks[5][13];
	OMargin *left, *right;
	OBall *ball;
	void Create() {
		paddle = new OPaddle();
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 13; j++)
			blocks[i][j] = new OBlock(42.5+j*55,25+i*20);
		}
		left = new OMargin(0);
		right = new OMargin(800-42.5);
		ball = new OBall(400,500);
	}
	void Update(){

	}
	void Render(){
		FontManager::DrawText(GameManager::Variables::KeyboardInput, 10, 10, "Verdana", 10, sf::Color::White);
	}
	virtual ~TestState() {};
};

#endif /* CODE_TESTSTATE_H_ */
