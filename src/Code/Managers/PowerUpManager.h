/*
 * PowerUpManager.h
 *
 *  Created on: 12 sty 2018
 *      Author: patryk
 */

#ifndef CODE_MANAGERS_POWERUPMANAGER_H_
#define CODE_MANAGERS_POWERUPMANAGER_H_
#include <SFML/Graphics.hpp>
#include <Managers/GameManager.h>
#include <vector>
#include <BaseClasses/CEntity.h>

using namespace std;

class PowerUpManager : public CEntity {
public:
	struct pu {
		float speed, activeTime, runningTime;
		string texname;
	};
	static vector<pu> powerUps;

	PowerUpManager();
	static sf::Texture *GetTexture(int type);
	static float GetSpeed(int type);
	virtual ~PowerUpManager();
};

#endif /* CODE_MANAGERS_POWERUPMANAGER_H_ */
