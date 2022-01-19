#include "TransformComponent.h"
#include "../core/CameraController.h"
#include "Components.h"
#include <cmath>

TransformComponent::TransformComponent(Vector2D& pos, Vector2D& offset): position(pos), seamlessOffset(offset) { }

void TransformComponent::update()
{
    if (!entity->hasComponent<PlayerComponent>()) {
        Vector2D* playerPosition
        = &(GameController::entityManager.getGroup(5)[0])
                ->getComponent<TransformComponent>().position;
        Vector2D difference = Vector2D(
                playerPosition->x - position.x,
                playerPosition->y - position.y
                );
        Vector2D distance = Vector2D(
                std::abs(difference.x),
                std::abs(difference.y)
                );
        if (playerPosition->x > position.x
        && distance.x > std::abs(difference.x - seamlessOffset.x)) {
            position.x += seamlessOffset.x;
        } else if (playerPosition->x < position.x
        && distance.x > std::abs(difference.x + seamlessOffset.x)) {
            position.x -= seamlessOffset.x;
        }
        if (playerPosition->y > position.y
        && distance.y > std::abs(difference.y - seamlessOffset.y)) {
            position.y += seamlessOffset.y;
        } else if (playerPosition->y < position.y
        && distance.y > std::abs(difference.y + seamlessOffset.y)) {
            position.y -= seamlessOffset.y;
        }
    }
	position += *CameraController::cameraMovement;
	position += velocity;
}
