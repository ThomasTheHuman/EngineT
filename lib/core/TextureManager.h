#pragma once
#include <memory>
#include "GameController.h"

class TextureManager
{
public:
	static SDL_Texture* load(const char* filename);
	static void render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, bool flip, int angle);
};

