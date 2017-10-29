/*
 * OComboDrawer.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#include "OComboDrawer.h"
#include "../Managers.h"
#include "../Effects/EText.h"
#include "../Effects/ETextComeFromLeft.h"
#include "../Effects/ETextLeaveToLeft.h"
#include "../Effects/ETextBounce.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;


int OComboDrawer::ComboCounter;
OComboDrawer::OComboDrawer() {
	OComboDrawer::ComboCounter = 0;
	this->time = 0;
	this->lastcombo = 0;
	this->text.clear();
	this->txt = new EText("Combo! x", 400, 300, "Verdana", 30, sf::Color::Red, 0);
}

void OComboDrawer::Update() {

	if(this->lastcombo == 1 && OComboDrawer::ComboCounter > 1) {
		new ETextComeFromLeft(txt, 0.5, 400);
	}
	if (OComboDrawer::ComboCounter > 1) {

		this->text.str("");
		this->text << "COMBO X" << OComboDrawer::ComboCounter << "!";
		this->txt->text = this->text.str();

		if(this->lastcombo != OComboDrawer::ComboCounter && OComboDrawer::ComboCounter > 2) {
			new ETextBounce(txt,2);
		}
	}
	if(OComboDrawer::ComboCounter == 0 && this->lastcombo > 1) {
		new ETextLeaveToLeft(txt,0.5,400);
	}
	this->lastcombo = OComboDrawer::ComboCounter;
	if(time>0) {
		time--;
	}
}


OComboDrawer::~OComboDrawer() {
	delete this->txt;
}

