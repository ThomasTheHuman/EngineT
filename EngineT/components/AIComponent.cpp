#include "AIComponent.h"
#include "Components.h"
#include "../core/GameController.h"

AIComponent::AIComponent() : movementSpeed(1), enemy(false)
{
}

AIComponent::AIComponent(int speed, bool enemy) : movementSpeed(speed), enemy(enemy)
{
}

void AIComponent::setGround(bool ground)
{
    if (ground) {
        entity->getComponent<SpriteComponent>().setRotation(0);
    }
	onGround = ground;
}

void AIComponent::setJump(bool jump)
{
	canJump = jump;
}

void AIComponent::setChain(bool chain)
{
	onChain = chain;
}

void AIComponent::update()
{
	if(dead)
	{
		if(onGround)
		{
			entity->getComponent<TransformComponent>().velocity.x = 0;
			entity->getComponent<AnimationComponent>().setAnimation(6, flip);
		}
		else
		{
			entity->getComponent<AnimationComponent>().setAnimation(7, flip);
		}
	}
	else
	{
		Entity* player = GameController::entityManager.getGroup(5)[0];
		Vector2D* myPosition = &entity->getComponent<TransformComponent>().position;
		Vector2D* playerPosition = &player->getComponent<TransformComponent>().position;
		if (onGround || grip)
		{
			if (jumpCount < 3)
			{
				jumpCount++;
			}
		}

		if (enemy && playerPosition->distanceTo(*myPosition) <= 256
			&& !player->getComponent<PlayerComponent>().getDead())
		{
			if (playerPosition->distanceTo(*myPosition) <= 24)
			{
				running = false;
				attacking = true;
			}
			else
			{
				if (playerPosition->x < myPosition->x && !(rand()%100)) {
					flip = false;
					running = true;
				}
				else if (playerPosition->x > myPosition->x && !(rand()%100)) {
					flip = true;
					running = true;
				}
				if (playerPosition->y < myPosition->y) {
					if (canJump && jumpCount > 0)
					{
						jumpCount--;
						if (onGround && !(rand()%100))
						{
							entity->getComponent<TransformComponent>().velocity.y = -1;
							entity->getComponent<ForceComponent>().reset();
						}
						else if (onChain && grip)
						{
							climbing = true;
						}
					}
				}
			}
		} else
		{
            flip = (rand()%100) ? flip : !flip;
            running = (rand()%100) ? running : !running;
		}

		for (Entity *other : GameController::entityManager.getGroup(6))
		{
			if(entity != other)
			{
				if (entity->getComponent<TransformComponent>().position
							.distanceTo(other->getComponent<TransformComponent>().position) <= 16)
				{
					entity->getComponent<TransformComponent>().velocity.x = 0;
					if (entity->getComponent<TransformComponent>().position.x >
						other->getComponent<TransformComponent>().position.x)
					{
						entity->getComponent<TransformComponent>().position += Vector2D(0.005,0);
					}
					else
					{
						entity->getComponent<TransformComponent>().position += Vector2D(-0.005, 0);
					}
				}
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
			entity->getComponent<TransformComponent>().velocity.x = 0;
			entity->getComponent<TransformComponent>().velocity.y = 0;
		}
	}
}

bool AIComponent::isAttacking() const
{
	return attacking;
}

void AIComponent::setAttacking(bool attacking)
{
	this->attacking = attacking;
}

bool AIComponent::getFlip() const
{
	return flip;
}

bool AIComponent::getGround() const
{
	return onGround;
}

void AIComponent::setDead(bool dead)
{
	this->dead = dead;
}

bool AIComponent::getGuard() const
{
	return guard;
}
