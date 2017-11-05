/*
 * GameManager.cpp
 *
 *  Created on: 18 sie 2017
 *      Author: crackgm
 */

#include "../Managers.h"
#include "../BaseClasses/CDrawable.h"
#include "../BaseClasses/CEntity.h"
#include "../BaseClasses/CCollidable.h"
#include "../BaseClasses/CEffect.h"
#include "../Notification/NotificationManager.h"
#include "../Achievements/AchievementManager.h"

#include <iostream>
#include <queue>
using namespace std;

sf::RenderWindow *GameManager::Window;
int GameManager::Variables::Framerate = 60;
int GameManager::Variables::WindowWidth = 800;
int GameManager::Variables::WindowHeight = 600;
string GameManager::Variables::KeyboardInput = "";

void GameManager::InitializeGame() {
	GameManager::Window = new sf::RenderWindow(sf::VideoMode(GameManager::Variables::WindowWidth, GameManager::Variables::WindowHeight), "Mininoid!", sf::Style::Close|sf::Style::Titlebar);
	GameManager::Window->setFramerateLimit(GameManager::Variables::Framerate);
	GameManager::Window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width/2-GameManager::Variables::WindowWidth/2, sf::VideoMode::getDesktopMode().height/2-GameManager::Variables::WindowHeight/2));
	AchievementManager::Initialize();
}

void GameManager::UpdateGame() {
	while (GameManager::Window->isOpen())
	    {
	        sf::Event event;
	        while (GameManager::Window->pollEvent(event))
	        {
	            if (event.type == sf::Event::Closed)
	            	GameManager::Window->close();
	            else if (event.type == sf::Event::TextEntered) {
	            	if (event.text.unicode == '\b') {
	            		if(GameManager::Variables::KeyboardInput.size() > 0) {
	            			GameManager::Variables::KeyboardInput.pop_back();
	            		}
	            	} else
	            		GameManager::Variables::KeyboardInput += static_cast<char>(event.text.unicode);
	            }
	        }
	        MouseManager::MouseUpdater();
	        NotificationManager::Update();
	        GameManager::HandleCollisions();
	        GameManager::UpdateEntities();
	        GameManager::RenderDrawables();
	        GameManager::CheckFinishEffects();
	    }
}

void GameManager::RenderDrawables() {
	GameManager::Window->clear();

	StateManager::PeekState()->Render();
	StateManager::PeekState()->DrawableList.sort([](const CDrawable* a, const CDrawable* b) {return a->Depth < b->Depth;});
	list<CDrawable*>::iterator it;
	for (it = StateManager::PeekState()->DrawableList.begin(); it != StateManager::PeekState()->DrawableList.end(); ++it) {
		(*it)->Render();
	}

	NotificationManager::Render();

	GameManager::Window->display();
}

void GameManager::CheckFinishEffects() {
		queue<CEffect*> q;
		list<CEffect*>::iterator it;
		for (it = StateManager::PeekState()->EffectList.begin(); it != StateManager::PeekState()->EffectList.end(); ++it) {
			if((*it)->CheckFinish()) q.push(*it);
		}
		while(q.size()>0) {
			delete q.front();
			q.pop();
		}

}

void GameManager::UpdateEntities() {
		StateManager::PeekState()->Update();
		list<CEntity*>::iterator it;
		for (it = StateManager::PeekState()->EntityList.begin(); it != StateManager::PeekState()->EntityList.end(); ++it) {
			(*it)->Update();
		}

}

void GameManager::HandleCollisions() {
		list<CCollidable*>::iterator it;
		queue<pair<CCollidable*,pair<string,CCollidable*>>> q;
		for (it = StateManager::PeekState()->CollidableList.begin(); it != StateManager::PeekState()->CollidableList.end(); ++it) {
			if(!(*it)->colenable) continue;
			list<CCollidable*>::iterator it2;
			for (it2 = StateManager::PeekState()->CollidableList.begin(); it2 != StateManager::PeekState()->CollidableList.end(); ++it2) {
				if(!(*it2)->colenable) continue;
				if (*it != *it2 && *it!=nullptr && *it2!=nullptr) {
					if((*it)->colshape.intersects((*it2)->colshape)) {
						q.push(pair<CCollidable*,pair<string,CCollidable*>>(*it,pair<string,CCollidable*>((*it2)->colname,*it2)));
					}
				}
			}
		}

		while(q.size()>0) {
			q.front().first->HandleCollision(q.front().second.first,q.front().second.second);
			q.pop();
		}

}

void GameManager::FinalizeGame() {
	AchievementManager::UpdateAchievements();
}

