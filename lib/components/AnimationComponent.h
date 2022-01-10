#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "../core/Vector2D.h"
#include <map>

// structure holding animation data:
// starting position in spritesheet and amount of frames in animation
struct Animation
{
	Animation();
	Animation(Vector2D startPos, int frames);
	Vector2D startPos;
	int frames;
};

class AnimationComponent final : public Component
{
private:
	bool playing = true;
	std::map<int, Animation> animations;
	Animation * animation = nullptr;
	int frame = 0;
	// counter that tells how many game frames has passed since last change of animation sprite
	int frameDelay = 0;
	// if true, sprites are rendered flipped from right to left
	bool flip = false; 
public:

	AnimationComponent() = default;
	~AnimationComponent() = default;
	void play();
	void stop();
	void addAnimation(int index, Vector2D startPos, int frames);
	void setAnimation(int index, bool flip);
	void update() override;
	bool lastFrame() const;
};