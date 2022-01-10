#pragma once
#include "Components.h"
#include "SDL.h"
#include "TransformComponent.h"
#include "Component.h"
class TransformComponent;

class SpriteComponent : public Component
{
public:
	SpriteComponent();
	SpriteComponent(const std::string& id, const char* path, Vector2D dimensions, Vector2D srcPosition, float scale);
	void setTexture(const std::string& id, const char* path);
	void setSrc(Vector2D position, bool flip);

	void setRotation(int rot);

    int getRotation() const;

    void update() override;

	void render() override;

	SDL_Rect srcRect;
	SDL_Rect destRect;

private:
	SDL_Texture *texture;
	bool flip = false;
	int angle = 0;
};
