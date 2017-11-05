/*
 * NotificationManager.cpp
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#include "NotificationManager.h"
#include "CNotification.h"
#include <list>
#include <queue>
#include <iostream>
using namespace std;

list<CNotification*> NotificationManager::notifications;

NotificationManager::NotificationManager() {
	// TODO Auto-generated constructor stub

}

void NotificationManager::Notify(string message, int time) {
	NotificationManager::notifications.push_back(new CNotification(message,time));
}

void NotificationManager::Update() {
	list<CNotification*>::iterator it;
	queue<CNotification*> q;
	int index = 0;
	for (it = NotificationManager::notifications.begin(); it != NotificationManager::notifications.end(); ++it) {
		(*it)->Update();

		if(!(*it)->IsDone()) {
			if((*it)->GetY()>20*index) {
				(*it)->SetY((*it)->GetY()-1);
			} else if ((*it)->GetY()<20*index) {
				(*it)->SetY((*it)->GetY()+1);
			}
			index++;
		} else {
			(*it)->SetY((*it)->GetY()-2);
			if((*it)->GetY()<-30) {
				q.push(*it);
			}
		}

	}

	while(q.size() > 0) {
		CNotification *t = q.front();
		for (it = NotificationManager::notifications.begin(); it != NotificationManager::notifications.end(); ++it) {
			if((*it) == t){
				NotificationManager::notifications.erase(it);
				delete t;
				break;
			}
		}
		q.pop();
	}

}


void NotificationManager::Render() {
	list<CNotification*>::iterator it;
	for (it = NotificationManager::notifications.begin(); it != NotificationManager::notifications.end(); ++it) {
		(*it)->Render();
	}


}

NotificationManager::~NotificationManager() {
	// TODO Auto-generated destructor stub
}

