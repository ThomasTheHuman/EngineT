#pragma once

#include <map>
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"

/// class that checks if texture was already loaded and stores textures
class ResourceManager
{
public:
	ResourceManager() = default;
	~ResourceManager();
	/// if texture is not already in {@link textures}, it is loaded using {@link TextureManager} and stored
	/// @param id name of texture
	/// @param path path to texture file
	void addTexture(const std::string& id, const char* path);
	///gets texture by it's name
	///@param id name of texture
	///@return pointer to texture
	SDL_Texture* getTexture(const std::string& id);
private:
	/// stores loaded textures
	std::map<std::string, SDL_Texture*> textures;
};