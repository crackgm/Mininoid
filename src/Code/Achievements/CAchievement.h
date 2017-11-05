/*
 * CAchievement.h
 *
 *  Created on: 5 lis 2017
 *      Author: crackgm
 */

#ifndef CODE_ACHIEVEMENTS_CACHIEVEMENT_H_
#define CODE_ACHIEVEMENTS_CACHIEVEMENT_H_

#include <string>
#include <fstream>
using namespace std;

class CAchievement {
public:
	CAchievement(string id, string name, string description, string texture, float progressMax);
	CAchievement();
	string texture, id, name, description;
	float progress, progressMax;
	friend ostream& operator << ( fstream& out, const CAchievement& a );
	friend istream& operator >> ( fstream& in, CAchievement& a );

};

#endif /* CODE_ACHIEVEMENTS_CACHIEVEMENT_H_ */
