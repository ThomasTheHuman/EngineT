#pragma once
#include "Component.h"
#include "Vector2D.h"

/// component that adds attacking functionality, it's methods are triggered by AIComponent or PlayerComponent
class AttackComponent final : public Component
{
private:
	/// amount of frames the attack takes
	int frames;
	/// base attack damage amount
	int damage;
	/// amount of frame delay between attack being triggered and damage being given
	int damageFrame;
	/// current frame of attack (if triggered)
	int currentFrame = 0; 

	/// adds damage to nearby entities of passed group @param group group of entities attacked
	template<class controller>void attack(int group);
public:
	AttackComponent(int frames, int damageFrame, int damage);
	~AttackComponent() = default;
	void update() override;
};
