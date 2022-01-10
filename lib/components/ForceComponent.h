#pragma once
#include "Component.h"
#include "../core/Vector2D.h"

class ForceComponent final : public Component
{
private:
	// amount of game frames since speed of entity was last increased
	int frameDelay = 0;
public:
	Vector2D force;

	ForceComponent();
	ForceComponent(Vector2D& force);
	~ForceComponent() = default;

	void setForce(Vector2D& force);
	// resets frameDelay to 1
	void reset();
	void update() override;
};