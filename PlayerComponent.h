#pragma once
#include "Component.h"
#include "Vector2D.h"

///component that gives user control over entity
class PlayerComponent final : public Component
{
private:
	///speed of movement
	int movementSpeed;
	///if true, sprite is flipped right to left
	bool flip = false;
	///true, if entity touches ground
	bool onGround = false;
	///true, if entity is moving
	bool running = false;
	///true if entity is defending itself
	bool guard = false;
	///if true, entity can perform a jump
	bool canJump = false;
	///true if entity touches chain or ladder
	bool onChain = false;
	///true if entity holds chain or ladder
    bool grip = false;
	///true if entity climbs a chain or ladder
	bool climbing = false;
	///true during performing an attack
	bool attacking = false;
	///amount of jumps entity can perform (renewed to max 3 after griping a chain or touching ground)
	int jumpCount = 3;
	///if true, entity is dead, RIP
	bool dead = false;

public:

	PlayerComponent();

	explicit PlayerComponent(int speed);
	///basic setter method
	void setGround(bool ground);
	///basic setter method
	void setJump(bool jump);
	///basic setter method
	void setChain(bool chain);
	void update() override;
	///basic getter method
	bool isAttacking() const;
	///basic setter method
	void setAttacking(bool attacking);
	///basic getter method
	bool getFlip() const;
	///basic getter method
	bool getGround() const;
	///basic setter method
	void setDead(bool dead);
	///basic getter method
	bool getDead() const;
	///basic getter method
	bool getGuard() const;
	bool getGrip() const;
};