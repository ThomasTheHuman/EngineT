#include "TextureManager.h"


SDL_Texture* TextureManager::load(const char* filename)
{
	const std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>
	surface(SDL_LoadBMP(filename), SDL_FreeSurface);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(
		GameController::renderer, 
		surface.get());
	return texture;
}

void TextureManager::render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, bool flip, int angle)
{
	SDL_RenderCopyEx(
		GameController::renderer, 
		tex, 
		&src, 
		&dest, 
		angle,
		nullptr,
		flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}
