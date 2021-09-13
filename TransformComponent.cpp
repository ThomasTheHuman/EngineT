#include "TransformComponent.h"
#include "CameraController.h"
#include "Components.h"

TransformComponent::TransformComponent()
{
	position.x = 0;
	position.y = 0;
}

TransformComponent::TransformComponent(Vector2D& pos)
{
	position = pos;
}

Vector2D TransformComponent::getAbsolute() const
{
	Vector2D v = position;
	v.x += CameraController::viewport.x;
	v.y += CameraController::viewport.y;
	return v;
}

void TransformComponent::setAbsolute(Vector2D pos)
{
	pos.x -= CameraController::viewport.x;
	pos.y -= CameraController::viewport.y;
	position = pos;
}

void TransformComponent::update()
{
	position += *CameraController::cameraMovement;
	position += velocity;
}
