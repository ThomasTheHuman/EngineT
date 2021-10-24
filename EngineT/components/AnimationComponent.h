#pragma once
#include "Component.h"
#include "SpriteComponent.h"
#include "../core/Vector2D.h"
#include <map>

/// structure holding animation data:
/// starting position in spritesheet and amount of frames in animation
struct Animation
{
	Animation();
	Animation(Vector2D startPos, int frames);
	Vector2D startPos;
	int frames;
};

/// component adding animation functionality to entity, requires SpriteComponent
class AnimationComponent final : public Component
{
private:
	/// if true, the animation is playing
	bool playing = false;
	/// map of animations added
	std::map<int, Animation> animations;
	/// currently set animation
	Animation * animation = nullptr;
	/// current frame
	int frame = 0;
	/// counter that tells how many game frames has passed since last change of animation sprite
	int frameDelay = 0;
	/// if true, sprites are rendered flipped from right to left
	bool flip = false; 
public:

	AnimationComponent() = default;
	~AnimationComponent() = default;
	///plays animation
	void play();
	///stops animation
	void stop();
	///adds new animation
	void addAnimation(int index, Vector2D startPos, int frames);
	///sets animation to be played
	void setAnimation(int index, bool flip);
	void update() override;
	///@return true if current frame of animation is the last one
	bool lastFrame() const;
};