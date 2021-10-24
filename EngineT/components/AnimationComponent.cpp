#include "AnimationComponent.h"

Animation::Animation() : startPos(Vector2D(0,0)), frames(0)
{
}

Animation::Animation(Vector2D startPos, int frames) : startPos(startPos), frames(frames)
{
}

void AnimationComponent::play()
{
	playing = true;
}

void AnimationComponent::stop()
{
	playing = false;
}

void AnimationComponent::addAnimation(int index, Vector2D startPos, int frames)
{
	animations[index] = Animation(startPos, frames);
}

void AnimationComponent::setAnimation(int index, bool flip)
{
	if(animation != &animations[index])
	{
		animation = &animations[index];
		frame = 0;
	}
	this->flip = flip;
}

void AnimationComponent::update()
{
	if (playing && animation) {
		if (frame >= animation->frames) { frame = 0; }
		if (frameDelay >= 10) { frameDelay = 0; }
		if (frameDelay == 0)
		{
			entity->getComponent<SpriteComponent>()
				.setSrc(Vector2D(animation->startPos.x + frame, animation->startPos.y), flip);
			frame++;
		}
		frameDelay++;
	}
}

bool AnimationComponent::lastFrame() const
{
	return frame == animation->frames;
}
