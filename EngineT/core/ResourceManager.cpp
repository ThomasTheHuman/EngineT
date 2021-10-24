#include "ResourceManager.h"

ResourceManager::~ResourceManager()
{
	for(const auto& texture : textures)
	{
		SDL_DestroyTexture(texture.second);
	}
}

void ResourceManager::addTexture(const std::string& id, const char* path)
{
	if (!textures.contains(id)) {
		textures.emplace(id, TextureManager::load(path));
	}
}

SDL_Texture* ResourceManager::getTexture(const std::string& id)
{
	return textures[id];
}