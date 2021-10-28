#pragma once

#include <SDL_rect.h>
#include "Component.h"
#include "../core/Vector2D.h"

///components that adds health to entity
class HealthComponent final : public Component
{
private:
	///amount of health
	int health;
	///maximal amount of health (unused functionality)
	int maxHealth;
	///healthbar rect
    SDL_Rect healthbar;

    bool isPlayer;

    void recalculateHealthbar();

public:
	HealthComponent(int health, int maxHealth, bool isPlayer);

	///heals entity by passed value (unused functionality) @param value amount of health to add to entity
	void heal(int value);

	///returns health in 0-1 range
	double getHealth();

	///damages entity, triggered by AttackComponent of hostile entity @param value amount of damage to be applied
	void damage(int value);

	void update() override;

	void render() override;
};