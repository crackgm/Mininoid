/*
 * AchievementManager.h
 *
 *  Created on: 5 lis 2017
 *      Author: crackgm
 */

#ifndef CODE_ACHIEVEMENTS_ACHIEVEMENTMANAGER_H_
#define CODE_ACHIEVEMENTS_ACHIEVEMENTMANAGER_H_

#include "CAchievement.h"
#include <fstream>
#include <map>
#include <string>
using namespace std;
class AchievementManager {

public:
	static fstream myFile;
	static map<string,CAchievement> aAchievements;
	static void Initialize();
	static void GainAchievement(string id);
	static void ProgressAchievement(string id, float progress);
	static void UpdateAchievements();
};
#endif /* CODE_ACHIEVEMENTS_ACHIEVEMENTMANAGER_H_ */
