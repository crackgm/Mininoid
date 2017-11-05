/*
 * CAchievement.cpp
 *
 *  Created on: 5 lis 2017
 *      Author: crackgm
 */

#include "CAchievement.h"
#include <iostream>
using namespace std;

CAchievement::CAchievement(string id, string name, string description, string texture, float progressMax) {
	this->id = id;
	this->name = name;
	this->description = description;
	this->texture = texture;
	this->progressMax = progressMax;
	this->progress = 0;
}
CAchievement::CAchievement() {
	this->id = "";
	this->name = "";
	this->description = "";
	this->texture = "";
	this->progressMax = 1;
	this->progress = 0;
}

ostream& operator << ( fstream& out, const CAchievement& a ){
	return out << a.id << "\n" << a.name << "\n" << a.description << "\n" << a.texture << "\n" << a.progress << "\n" << a.progressMax << "\n";
}

istream& operator >> ( fstream& in, CAchievement& a ) {
	std::getline(in, a.id);
	std::getline(in, a.name);
	std::getline(in, a.description);
	std::getline(in, a.texture);
	in >> a.progress;
	in.ignore(1024, '\n');
	in >> a.progressMax;
	in.ignore(1024, '\n');
	return in;
}
