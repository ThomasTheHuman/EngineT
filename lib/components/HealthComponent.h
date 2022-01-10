#pragma once

#include <SDL_rect.h>
#include "Component.h"
#include "../core/Vector2D.h"

class HealthComponent final : public Component
{
private:
	int health;
	int maxHealth;
	// healthbar rect
    SDL_Rect healthbar;

    bool isPlayer;

    void recalculateHealthbar();

public:
	HealthComponent(int health, int maxHealth, bool isPlayer);

	void heal(int value);

	// returns health in 0-1 range
	double getHealth();

	void damage(int value);

	void update() override;

	void render() override;
};