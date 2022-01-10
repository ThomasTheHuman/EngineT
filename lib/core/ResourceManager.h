#pragma once

#include <map>
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"

class ResourceManager
{
public:
	ResourceManager() = default;
	~ResourceManager();
	void addTexture(const std::string& id, const char* path);
	SDL_Texture* getTexture(const std::string& id);
private:
	std::map<std::string, SDL_Texture*> textures;
};