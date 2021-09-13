#pragma once
#include <memory>
#include "GameController.h"
//#include <SDL_image.h>

/// class of static methods used to load and render textures
class TextureManager
{
public:
	/// loads texture from file
	/// @param filename path to texture file
	/// @return pointer to texture
	static SDL_Texture* load(const char* filename);
	/// renders texture on screen
	/// @param tex pointer to texture to be rendered
	/// @param src rectangle holding position and dimensions of part of texture to be rendered
	/// @param dest rectangle holding position and dimension on screen where to render the image
	/// @param flip if true, texture is flipped left to right
	static void render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, bool flip, int angle);
};

