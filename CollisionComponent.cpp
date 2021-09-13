#include "CollisionComponent.h"
#include "Components.h"
#include <SDL.h>

void CollisionComponent::update()
{
	SDL_Rect myBound = entity->getComponent<SpriteComponent>().destRect;
	//TODO hardcoded
	myBound.x += 16;
	myBound.w -= 32;
	myBound.y += 8;
	myBound.h -= 10;
	//^^
	SDL_Rect myDetector = myBound;
	myDetector.x--;
	myDetector.y--;
	myDetector.h += 2;
	myDetector.w += 2;

	int collisionCount = 0;
	Vector2D collisions;

	bool detector[2] = { false, false }; //top-bottom,right-left

	bool onGround = false;
	bool canJump = false;
	bool onChain = false;
	
	for(Entity *obstacle : GameController::entityManager.getGroup(1))
	{
		SDL_Rect obstacleBound = obstacle->getComponent<SpriteComponent>().destRect;
		SDL_Rect intersection;
		if(SDL_IntersectRect(&obstacleBound,&myBound,&intersection))
		{
			collisions.y += intersection.h;
			collisions.x += intersection.w;
			collisionCount++;
		} else if (SDL_IntersectRect(&obstacleBound, &myDetector, &intersection))
		{
			if (2 >= intersection.w >= 1)
			{
				if (intersection.x == myBound.x - 1) //left detector
				{
					canJump = true;
					if (entity->getComponent<TransformComponent>().velocity.x < 0)
					{
						detector[1] = true;
					}
				}
				if (intersection.x == myBound.x + myBound.w) //right detector
				{
					canJump = true;
					if (entity->getComponent<TransformComponent>().velocity.x > 0)
					{
						detector[1] = true;
					}
				}
			}
			else if(intersection.h == 1)
			{
				if (intersection.y == myBound.y + myBound.h) //bottom detector
				{
					onGround = true;
					canJump = true;
					if (entity->getComponent<TransformComponent>().velocity.y > 0)
					{
						detector[0] = true;
					}
				}
				if (intersection.y == myBound.y - 1) //top detector
				{
					if (entity->getComponent<TransformComponent>().velocity.y < 0)
					{
						detector[0] = true;
					}
				}
			}
		}
	}

	for (Entity* chain : GameController::entityManager.getGroup(2))
	{
		SDL_Rect chainBound = chain->getComponent<SpriteComponent>().destRect;
		if (SDL_HasIntersection(&chainBound, &myBound))
		{
		    if (entity->hasComponent<PlayerComponent>() && entity->getComponent<PlayerComponent>().getGrip()) {
		        if (entity->getComponent<PlayerComponent>().getFlip()) {
                    entity->getComponent<TransformComponent>().position.x = chainBound.x - 24;
                } else {
                    entity->getComponent<TransformComponent>().position.x = chainBound.x - 10;
                }
            }
			onChain = true;
			canJump = true;
			break;
		}
	}

	if(collisionCount)
	{
		collisions = collisions / Vector2D(collisionCount, collisionCount);
		if (collisions.x < collisions.y) //right-left
		{
			if (entity->getComponent<TransformComponent>().velocity.x > 0)
			{
				entity->getComponent<TransformComponent>().position.x -= collisions.x;
			}
			else
			{
				entity->getComponent<TransformComponent>().position.x += collisions.x;
			}
			entity->getComponent<TransformComponent>().velocity.x = 0;
		} else if (collisions.x > collisions.y) //top-down
		{
			if (entity->getComponent<TransformComponent>().velocity.y > 0)
			{
				entity->getComponent<TransformComponent>().position.y -= collisions.y;
			}
			else
			{
				entity->getComponent<TransformComponent>().position.y += collisions.y;
			}
			entity->getComponent<TransformComponent>().velocity.y = 0;
		}
	}

	int detectionIndex = 0;
	for(bool detection:detector)
	{
		if (detection)
		{
			switch(detectionIndex)
			{
			case 0:
				entity->getComponent<TransformComponent>().velocity.y = 0;
				break;
			case 1:
				entity->getComponent<TransformComponent>().velocity.x = 0;
				break;
			default:
				break;
			}
		}
		detectionIndex++;
	}
	if(entity->hasComponent<PlayerComponent>())
	{
		entity->getComponent<PlayerComponent>().setGround(onGround);
		entity->getComponent<PlayerComponent>().setJump(canJump);
		entity->getComponent<PlayerComponent>().setChain(onChain);
	} else if(entity->hasComponent<AIComponent>())
	{
		entity->getComponent<AIComponent>().setGround(onGround);
		entity->getComponent<AIComponent>().setJump(canJump);
		entity->getComponent<AIComponent>().setChain(onChain);
	}
}
