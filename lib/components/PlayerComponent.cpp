#include "PlayerComponent.h"
#include <SDL.h>
#include "Components.h"
#include "../core/GameController.h"

PlayerComponent::PlayerComponent() : movementSpeed(1)
{
}

PlayerComponent::PlayerComponent(int speed) : movementSpeed(speed)
{
}

void PlayerComponent::setGround(bool ground)
{
    if (ground) {
        entity->getComponent<SpriteComponent>().setRotation(0);
    }
	onGround = ground;
}

void PlayerComponent::setJump(bool jump)
{
	canJump = jump;
}

void PlayerComponent::setChain(bool chain)
{
	onChain = chain;
}

void PlayerComponent::update()
{
	if (dead)
	{
		if (onGround)
		{
			//entity->getComponent<AnimationComponent>().setAnimation(6, flip);
		}
		else
		{
			entity->getComponent<AnimationComponent>().setAnimation(7, flip);
		}
	}
	else
	{
		if (onGround || grip)
		{
            if (jumpCount < 3)
			{
				jumpCount++;
			}
		}

		if (GameController::event.type == SDL_KEYDOWN)
		{
			switch (GameController::event.key.keysym.sym)
			{
			case SDLK_x:
				attacking = true;
				grip = false;
				guard = false;
				break;
			case SDLK_LEFT:
			    if (flip) {
                    entity->getComponent<SpriteComponent>().setRotation(
                            -entity->getComponent<SpriteComponent>().getRotation());
			    }
				flip = false;
				running = true;
				break;
			case SDLK_RIGHT:
			    if (!flip) {
                    entity->getComponent<SpriteComponent>().setRotation(
                            -entity->getComponent<SpriteComponent>().getRotation());
			    }
				flip = true;
				running = true;
				break;
			case SDLK_LSHIFT:
				if (onChain && !onGround)
				{
                    entity->getComponent<SpriteComponent>().setRotation((flip * -90) + 45);
                    grip = true;
				}
				else if (onGround && entity->getComponent<TransformComponent>().velocity.x == 0)
				{
					guard = true;
				}
				break;
			case SDLK_SPACE:
                if (canJump && jumpCount > 0)
				{
					jumpCount--;
					if (onGround)
					{
						entity->getComponent<TransformComponent>().velocity.y = -2;
						entity->getComponent<ForceComponent>().reset();
					}
					else if (onChain && grip)
					{
						climbing = true;
					}
					else
					{
                        entity->getComponent<SpriteComponent>().setRotation(rand()%180 - 90);
                        entity->getComponent<TransformComponent>().velocity.y = -2;
						entity->getComponent<ForceComponent>().reset();
						if (flip)
						{
							entity->getComponent<TransformComponent>().velocity.x = -1;
						}
						else
						{
							entity->getComponent<TransformComponent>().velocity.x = 1;
						}
						flip = !flip;
					}
				}
			default:
				break;
			}
		}

		if (GameController::event.type == SDL_KEYUP)
		{
			switch (GameController::event.key.keysym.sym)
			{
			case SDLK_LEFT:
				entity->getComponent<TransformComponent>().velocity.x = 0;
				running = false;
				break;
			case SDLK_RIGHT:
				entity->getComponent<TransformComponent>().velocity.x = 0;
				running = false;
				break;
			case SDLK_SPACE:
				climbing = false;
				break;
			case SDLK_LSHIFT:
				guard = false;
				grip = false;
				climbing = false;
				break;
			default:
				break;
			}
		}

		if (!onGround)
		{
			if (attacking)
			{
				entity->getComponent<AnimationComponent>().setAnimation(5, flip);
			}
			else if (guard)
			{
				entity->getComponent<AnimationComponent>().setAnimation(4, flip);
			}
			else
			{
				entity->getComponent<AnimationComponent>().setAnimation(3, flip);
				if (running && entity->getComponent<TransformComponent>().velocity.x == 0)
				{
					entity->getComponent<TransformComponent>().velocity.x = flip ? movementSpeed : -movementSpeed;
				}
			}
		}
		else if (running)
		{
			entity->getComponent<AnimationComponent>().setAnimation(2, flip);
			entity->getComponent<TransformComponent>().velocity.x = flip ? movementSpeed : -movementSpeed;
		}
		else if (guard)
		{
			entity->getComponent<AnimationComponent>().setAnimation(4, flip);
		}
		else if (attacking)
		{
			entity->getComponent<AnimationComponent>().setAnimation(5, flip);
		}
		else
		{
			entity->getComponent<AnimationComponent>().setAnimation(1, flip);
		}

		if (climbing)
		{
			entity->getComponent<TransformComponent>().velocity.x = 0;
			entity->getComponent<TransformComponent>().velocity.y = -1;
		}
		else if (grip)
		{
			entity->getComponent<TransformComponent>().velocity.x /= 1.2f;
			entity->getComponent<TransformComponent>().velocity.y /= 1.2f;
		}

		if (!onChain) {
		    grip = false;
		}
	}
}

bool PlayerComponent::isAttacking() const
{
	return attacking;
}

void PlayerComponent::setAttacking(bool attacking)
{
	this->attacking = attacking;
}

bool PlayerComponent::getFlip() const
{
	return flip;
}

bool PlayerComponent::getGround() const
{
	return onGround;
}

void PlayerComponent::setDead(bool dead)
{
	this->dead = dead;
}

bool PlayerComponent::getDead() const
{
	return dead;
}

bool PlayerComponent::getGuard() const
{
	return guard;
}

bool PlayerComponent::getGrip() const {
    return grip;
}
