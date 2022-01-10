#pragma once

#include <SDL_rect.h>
#include "Component.h"
#include "../core/Vector2D.h"

class AttackComponent final : public Component
{
private:
	int frames;
	int damage;
	int damageFrame;
	int currentFrame = 0;

	// attack bar rect
	SDL_Rect attackbar;

	void recalculateAttackbar();

	// adds damage to nearby entities of passed group
	template<class controller>void attack(int group);
public:
	AttackComponent(int frames, int damageFrame, int damage);
	~AttackComponent() = default;
	void update() override;
	void render() override;
};
