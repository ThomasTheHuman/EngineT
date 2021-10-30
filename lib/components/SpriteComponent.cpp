#include "SpriteComponent.h"

SpriteComponent::SpriteComponent():
texture(nullptr), srcRect(), destRect()
{
	srcRect.x = srcRect.y = 0;
	srcRect.w = srcRect.h = 64;
	destRect.w = destRect.h = 64;
}

SpriteComponent::SpriteComponent(const std::string& id, const char* path, 
	const Vector2D dimensions, const Vector2D srcPosition, float scale):
texture(nullptr), srcRect(), destRect()
{
	srcRect.w = dimensions.x;
	srcRect.h = dimensions.y;
    destRect.w = dimensions.x * scale;
    destRect.h = dimensions.y * scale;
	srcRect.x = srcPosition.x * dimensions.x;
	srcRect.y = srcPosition.y * dimensions.y;
	setTexture(id, path);
}

void SpriteComponent::setTexture(const std::string& id, const char* path)
{
	GameController::resourceManager->addTexture(id, path);
	texture = GameController::resourceManager->getTexture(id);
}

void SpriteComponent::setSrc(Vector2D position, bool flip)
{
	srcRect.x = srcRect.w * position.x;
	srcRect.y = srcRect.h * position.y;
	this->flip = flip;
}

void SpriteComponent::update()
{
	destRect.x = (int)entity->getComponent<TransformComponent>().position.x;
	destRect.y = (int)entity->getComponent<TransformComponent>().position.y;
}

void SpriteComponent::render()
{
	Entity* player = GameController::entityManager.getGroup(5)[0];
	double distanceToPlayer = player->getComponent<TransformComponent>().position
	        .distanceTo(entity->getComponent<TransformComponent>().position);
	if(distanceToPlayer < 255)
	{
	    SDL_SetTextureAlphaMod( texture, 255 - distanceToPlayer);
		TextureManager::render(texture, srcRect, destRect, flip, angle);
	}
}

void SpriteComponent::setRotation(int rot) {
    angle = rot;
}

int SpriteComponent::getRotation() const {
    return angle;
}
