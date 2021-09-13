#include "HealthComponent.h"
#include "Components.h"

HealthComponent::HealthComponent(int health, int maxHealth)
: health(health), maxHealth(maxHealth){}

void HealthComponent::heal(int value)
{
	health += value;
	if(health>maxHealth)
	{
		health = maxHealth;
	}
}

void HealthComponent::damage(int value)
{
    int randomRotation = rand()%180 - 90;
	if (entity->hasComponent<AIComponent>())
	{
		if(!entity->getComponent<AIComponent>().getGuard())
		{
			health -= value;
            entity->getComponent<SpriteComponent>().setRotation(randomRotation);
        }
	}
	else
	{
		if (!entity->getComponent<PlayerComponent>().getGuard())
		{
			health -= value;
            entity->getComponent<SpriteComponent>().setRotation(randomRotation);
        }
	}
	if(health <= 0)
	{
		health = 0;
		if(entity->hasComponent<AIComponent>())
		{
			entity->getComponent<AIComponent>().setDead(true);
            entity->getComponent<SpriteComponent>().setRotation(randomRotation * 2);
        }
		else
		{
			entity->getComponent<PlayerComponent>().setDead(true);
            entity->getComponent<SpriteComponent>().setRotation(randomRotation * 2);
        }
	}
}

void HealthComponent::update()
{
	if (health == 0 
		&& entity->hasComponent<PlayerComponent>() 
		&& entity->getComponent<PlayerComponent>().getGround())
	{
		entity->getComponent<AnimationComponent>().setAnimation(8,true);
		if (entity->getComponent<AnimationComponent>().lastFrame())
		{
			health = maxHealth;
			entity->getComponent<PlayerComponent>().setDead(false);
		}
	}
}
