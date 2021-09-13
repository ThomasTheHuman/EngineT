#include "ForceComponent.h"
#include "Components.h"

ForceComponent::ForceComponent() : force(Vector2D()){}

ForceComponent::ForceComponent(Vector2D& force) : force(force){}

void ForceComponent::setForce(Vector2D& force)
{
	this->force = force;
}

void ForceComponent::reset()
{
	frameDelay = 1;
}

void ForceComponent::update()
{

	if (frameDelay >= 17) { frameDelay = 0; }
	if (frameDelay == 0)
	{
		entity->getComponent<TransformComponent>().velocity += force;
	}
	frameDelay++;
}
