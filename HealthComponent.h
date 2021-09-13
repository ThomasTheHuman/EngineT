#pragma once
#include "Component.h"
#include "Vector2D.h"

///components that adds health to entity
class HealthComponent final : public Component
{
private:
	///amount of health
	int health;
	///maximal amount of health (unused functionality)
	int maxHealth;
public:
	HealthComponent(int health, int maxHealth);

	///heals entity by passed value (unused functionality) @param value amount of health to add to entity
	void heal(int value);

	///damages entity, triggered by AttackComponent of hostile entity @param value amount of damage to be applied
	void damage(int value);

	void update() override;
};