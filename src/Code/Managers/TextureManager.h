/*
 * TextureManager.h
 *
 *  Created on: 20 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_MANAGERS_TEXTUREMANAGER_H_
#define CODE_MANAGERS_TEXTUREMANAGER_H_
#include <map>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace std;

class TextureManager {
private:
	static map<char*,sf::Texture*> TextureMap;
public:
	static bool LoadTexture(char* path, char* texname);
	static bool LoadTexture(char* path, char* texname, bool repeat);
	static sf::Texture* GetTexture(char* name);
};

#endif /* CODE_MANAGERS_TEXTUREMANAGER_H_ */
