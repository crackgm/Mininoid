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
	static map<string,sf::Texture*> TextureMap;
public:
	static bool LoadTexture(string path, string texname);
	static bool LoadTexture(string path, string texname, bool repeat);
	static sf::Texture* GetTexture(string name);
};

#endif /* CODE_MANAGERS_TEXTUREMANAGER_H_ */
