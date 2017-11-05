/*
 * CNotification.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_NOTIFICATION_CNOTIFICATION_H_
#define CODE_NOTIFICATION_CNOTIFICATION_H_
#include "../BaseClasses/CEntity.h"
#include "../BaseClasses/CDrawable.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class CNotification {
public:
	string message;
	int time, timeOn;
	sf::RectangleShape shape;
	sf::Color rectColor;
	sf::Color textColor;
	void SetY(float y);
	float GetY();
	CNotification(string message, int time, sf::Color rectColor = sf::Color::Black, sf::Color textColor = sf::Color::White);
	void Render();
	void Update();
	bool IsDone();
	virtual ~CNotification();
};

#endif /* CODE_NOTIFICATION_CNOTIFICATION_H_ */
