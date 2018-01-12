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
#include "Notification/NotificationManager.h"
#include "Objects/OComboDrawer.h"
#include "Achievements/AchievementManager.h"

class TestState: public CState {
	OPaddle *paddle;
	OBlock *blocks[5][13];
	OMargin *left, *right;
	OBall *ball;
	OComboDrawer *cdrawer;
	sf::RectangleShape shape;
	sf::RenderTexture background;
	float xx=0;
	void Create() {
		NotificationManager::Notify("Playing on: TestState", 10);
		background.create(800,600);


		paddle = new OPaddle();
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 13; j++)
			blocks[i][j] = new OBlock(42.5+j*55,25+i*20);
		}
		left = new OMargin(0);
		right = new OMargin(800-42.5);
		ball = new OBall(400,500);
		cdrawer = new OComboDrawer();



	}
	void Update(){
		xx+=0.25f;
		if(xx>=126) xx = 0;
		AchievementManager::ProgressAchievement("timeplayed1",1);

	}
	void Render(){
		background.clear(sf::Color::Red);
						shape.setSize(sf::Vector2f(128,128));
						shape.setTexture(TextureManager::GetTexture("background"),true);


						for(int i = -1; i < 800/128+1; i++) {
							for(int j = -1; j < 600/128+1; j++) {

								shape.setPosition(i*126+xx*-1, j*126+xx);
								background.draw(shape);
							}
						}
						background.display();
						shape.setSize(sf::Vector2f(800,600));
						shape.setTexture(&background.getTexture(),true);
						shape.setPosition(sf::Vector2f(0,0));

		GameManager::Window->draw(shape);
		FontManager::DrawText(GameManager::Variables::KeyboardInput, 10, 10, "Verdana", 10, sf::Color::White);
	}
	virtual ~TestState() {
		delete left;
		delete right;
		delete paddle;
		delete ball;
		delete cdrawer;
	};
};

#endif /* CODE_TESTSTATE_H_ */
