#include "TransformComponent.h"
#include "../core/CameraController.h"
#include "Components.h"
#include <cmath>

TransformComponent::TransformComponent(Vector2D& pos, Vector2D& offset): position(pos), seamlessOffset(offset) { }

void TransformComponent::update()
{
    if (!entity->hasComponent<PlayerComponent>()) {
        Vector2D* playerPosition = &(GameController::entityManager.getGroup(5)[0])
                ->getComponent<TransformComponent>().position;
        float distanceX = std::abs(playerPosition->x - position.x);
        float distanceY = std::abs(playerPosition->y - position.y);
        if (playerPosition->x > position.x && distanceX > std::abs(playerPosition->x - (position.x + seamlessOffset.x))) {
            position.x += seamlessOffset.x;
        } else if (playerPosition->x < position.x && distanceX > std::abs(playerPosition->x - (position.x - seamlessOffset.x))) {
            position.x -= seamlessOffset.x;
        }
        if (playerPosition->y > position.y && distanceY > std::abs(playerPosition->y - (position.y + seamlessOffset.y))) {
            position.y += seamlessOffset.y;
        } else if (playerPosition->y < position.y && distanceY > std::abs(playerPosition->y - (position.y - seamlessOffset.y))) {
            position.y -= seamlessOffset.y;
        }
    }
	position += *CameraController::cameraMovement;
	position += velocity;
}
