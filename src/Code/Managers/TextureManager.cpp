/*
 * TextureManager.cpp
 *
 *  Created on: 20 sie 2017
 *      Author: crackgm
 */

#include "../Managers.h"

map<char*,sf::Texture*> TextureManager::TextureMap;

sf::Texture* TextureManager::GetTexture(char* name) {
	return TextureManager::TextureMap[name];
}

bool TextureManager::LoadTexture(char* path, char* texname) {
	sf::Texture *tex = new sf::Texture();
	bool res = tex->loadFromFile(path);
	tex->setSmooth(true);
	TextureManager::TextureMap.insert(pair<char*,sf::Texture*>(texname,tex));
	return res;
}


bool TextureManager::LoadTexture(char* path, char* texname, bool repeat) {
	sf::Texture *tex = new sf::Texture();
	bool res = tex->loadFromFile(path);
	tex->setSmooth(true);
	tex->setRepeated(repeat);
	TextureManager::TextureMap.insert(pair<char*,sf::Texture*>(texname,tex));
	return res;
}
