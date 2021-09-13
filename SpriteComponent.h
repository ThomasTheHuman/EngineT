#pragma once
#include "Components.h"
#include "SDL.h"
#include "TransformComponent.h"
#include "Component.h"
class TransformComponent;

/// component that renders entity on screen
class SpriteComponent : public Component
{
public:
	SpriteComponent();
	SpriteComponent(const std::string& id, const char* path, Vector2D dimensions, Vector2D srcPosition, float scale);
	/// sets spritesheet
	void setTexture(const std::string& id, const char* path);
	/// sets sprite from spritesheet to be rendered
	void setSrc(Vector2D position, bool flip);

	void setRotation(int rot);

    int getRotation() const;

    void update() override;

	void render() override;

	///holds position and dimmension of sprite in spritesheet
	SDL_Rect srcRect;
	///holds position and dimmension of place on screen to render sprite on
	SDL_Rect destRect;

private:
	///spritesheet of entity
	SDL_Texture *texture;
	///if true, sprite is flipped right to left
	bool flip = false;
	///rotation of texture
	int angle = 0;
};
