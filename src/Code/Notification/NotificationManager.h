/*
 * NotificationManager.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_NOTIFICATION_NOTIFICATIONMANAGER_H_
#define CODE_NOTIFICATION_NOTIFICATIONMANAGER_H_

#include <list>
#include "CNotification.h"
#include "../BaseClasses/CEntity.h"

using namespace std;

class NotificationManager {
public:
	static list<CNotification*> notifications;
	NotificationManager();
	static void Update();
	static void Render();
	static void Notify(char* message, int time);
	virtual ~NotificationManager();
};

#endif /* CODE_NOTIFICATION_NOTIFICATIONMANAGER_H_ */
