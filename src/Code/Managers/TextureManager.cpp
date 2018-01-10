/*
 * TextureManager.cpp
 *
 *  Created on: 20 sie 2017
 *      Author: crackgm
 */

#include "../Managers.h"

map<string,sf::Texture*> TextureManager::TextureMap;

sf::Texture* TextureManager::GetTexture(string name) {
	return TextureManager::TextureMap[name];
}

bool TextureManager::LoadTexture(string path, string texname) {
	sf::Texture *tex = new sf::Texture();
	bool res = tex->loadFromFile(path);
	tex->setSmooth(true);
	TextureManager::TextureMap.insert(pair<string,sf::Texture*>(texname,tex));
	return res;
}


bool TextureManager::LoadTexture(string path, string texname, bool repeat) {
	sf::Texture *tex = new sf::Texture();
	bool res = tex->loadFromFile(path);
	tex->setSmooth(true);
	tex->setRepeated(repeat);
	TextureManager::TextureMap.insert(pair<string,sf::Texture*>(texname,tex));
	return res;
}
