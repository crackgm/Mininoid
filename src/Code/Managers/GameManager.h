/*
 * GameManager.h
 *
 *  Created on: 18 sie 2017
 *      Author: crackgm
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_
#include <SFML/Graphics.hpp>
#include <cstdlib>
using namespace std;

class GameManager {
public:
	static sf::RenderWindow *Window;
	static void UpdateGame();
	static void InitializeGame();
	static void FinalizeGame();
	class Variables {
	public:
		static int Framerate;
		static int WindowWidth;
		static int WindowHeight;
		static string KeyboardInput;
	};
private:
	static void RenderDrawables();
	static void UpdateEntities();
	static void HandleCollisions();
	static void CheckFinishEffects();
};

#endif /* GAMEMANAGER_H_ */
