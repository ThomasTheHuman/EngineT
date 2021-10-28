#include "HealthComponent.h"
#include "Components.h"

double HealthComponent::getHealth() {
    return (double)health/maxHealth;
}

void HealthComponent::recalculateHealthbar() {
    if (health == maxHealth && !isPlayer) {
        healthbar.w = 0;
    } else {
        healthbar.w = (isPlayer ? 236 : 48) * (float)health/maxHealth;
    }
}

HealthComponent::HealthComponent(int health, int maxHealth, bool isPlayer)
: health(health), maxHealth(maxHealth), healthbar(), isPlayer(isPlayer) {
    if (isPlayer) {
        healthbar.h = 10;
        healthbar.x = 10;
        healthbar.y = 10;
    } else {
        healthbar.h = 1;
    }
    recalculateHealthbar();
}

void HealthComponent::heal(int value)
{
	health += value;
	if(health>maxHealth)
	{
		health = maxHealth;
	}
	recalculateHealthbar();
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
	recalculateHealthbar();
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
			recalculateHealthbar();
		}
	}
}

void HealthComponent::render() {
    if (!isPlayer) {
        healthbar.x = (int)entity->getComponent<TransformComponent>().position.x;
        healthbar.y = (int)entity->getComponent<TransformComponent>().position.y;
    }

    int healthColor = isPlayer ? healthbar.w : (healthbar.w * 5.3);

    SDL_SetRenderDrawColor(GameController::renderer, 255 - healthColor, healthColor, 0, 255 );
    SDL_RenderFillRect(GameController::renderer, &healthbar);
}
