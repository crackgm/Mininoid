/*
 * AchievementManager.cpp
 *
 *  Created on: 5 lis 2017
 *      Author: crackgm
 */

#include "AchievementManager.h"
#include <sys/stat.h>
#include "CAchievement.h"
#include <iostream>
#include "../Notification/NotificationManager.h"
using namespace std;
map<string,CAchievement> AchievementManager::aAchievements;
fstream AchievementManager::myFile;

void AchievementManager::Initialize() {
	myFile.open("Data/Achievements.bin", ios::in | ios::out | ios::binary);

	aAchievements.insert(pair<string,CAchievement>("timeplayed1",
			CAchievement(	"timeplayed1",
							"One hour maniac!",
							"Play Mininoid! for one hour!",
							"achtimeplayed1",
							60*60*60)));

	aAchievements.insert(pair<string,CAchievement>("combo2",
			CAchievement(	"combo2",
							"Combo master x2!",
							"Get combo x2 in game!",
							"achcombo2",
							1)));

	CAchievement ach;
	if(!myFile.is_open()) cout << "couldn't not open file" << endl;
	while (myFile >> ach) {
		aAchievements[ach.id] = ach;
		cout << ach.id << ": " << ach.progress << "/" << ach.progressMax << endl;
	}
	myFile.close();
}

void AchievementManager::GainAchievement(string id) {
	if(aAchievements[id].progress!=0) return;

	aAchievements[id].progress=1;
	myFile.open("Data/Achievements.bin", ios::in | ios::out | ios::binary);
	myFile.clear();
	for (std::map<string,CAchievement>::iterator it=aAchievements.begin(); it!=aAchievements.end(); ++it)
	    myFile << it->second;

	myFile.close();
	NotificationManager::Notify("Gained achievement: " + aAchievements[id].name, 20);

}


void AchievementManager::UpdateAchievements() {
	myFile.open("Data/Achievements.bin", ios::in | ios::out | ios::binary);
	myFile.clear();
	for (std::map<string,CAchievement>::iterator it=aAchievements.begin(); it!=aAchievements.end(); ++it)
	    myFile << it->second;

	myFile.close();
}

void AchievementManager::ProgressAchievement(string id, float progress) {
	if(aAchievements[id].progress!=-1)
		aAchievements[id].progress += progress;
	if(aAchievements[id].progress >= aAchievements[id].progressMax) {
		myFile.open("Data/Achievements.bin", ios::in | ios::out | ios::binary);
		myFile.clear();
		aAchievements[id].progress = -1;
		for (std::map<string,CAchievement>::iterator it=aAchievements.begin(); it!=aAchievements.end(); ++it)
		    myFile << it->second;

		myFile.close();

		NotificationManager::Notify("Gained achievement: " + aAchievements[id].name, 20);
	}
}
