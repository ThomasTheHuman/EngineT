#pragma once
#include "Component.h"
#include "../core/Vector2D.h"

class PlayerComponent final : public Component
{
private:
	int movementSpeed;
	bool flip = false;
	bool onGround = false;
	bool running = false;
	bool guard = false;
	bool canJump = false;
	bool onChain = false;
    bool grip = false;
	bool climbing = false;
	bool attacking = false;
	int jumpCount = 3;
	bool dead = false;

public:

	PlayerComponent();

	explicit PlayerComponent(int speed);
	void setGround(bool ground);
	void setJump(bool jump);
	void setChain(bool chain);
	void update() override;
	bool isAttacking() const;
	void setAttacking(bool attacking);
    bool getFlip() const;
	bool getGround() const;
	void setDead(bool dead);
	bool getDead() const;
	bool getGuard() const;
	bool getGrip() const;
};