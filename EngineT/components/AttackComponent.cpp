#include "AttackComponent.h"
#include "Components.h"


void AttackComponent::recalculateAttackbar() {
    attackbar.w = 48 * (float)currentFrame/damageFrame;
    if (attackbar.w > 48) {
        attackbar.w = 48;
    }
}

AttackComponent::AttackComponent(int frames, int damageFrame, int damage)
	: frames(frames), damage(damage), damageFrame(damageFrame), attackbar(){
    attackbar.h = 1;
}

void AttackComponent::update()
{
	if (entity->hasComponent<PlayerComponent>())
	{
		attack<PlayerComponent>(6);
	}
	else
	{
		attack<AIComponent>(5);
	}
    recalculateAttackbar();
}
template<class controller>
void AttackComponent::attack(int group)
{
	if (entity->getComponent<controller>().isAttacking())
	{
		if (currentFrame == damageFrame)
		{
			for (auto* enemy : GameController::entityManager.getGroup(group))
			{
				if (entity->getComponent<TransformComponent>().position.distanceTo(
					enemy->getComponent<TransformComponent>().position) <= 32)
				{
					bool flip = entity->getComponent<controller>().getFlip();
					if (entity->getComponent<controller>().getGround())
					{
						enemy->getComponent<HealthComponent>().damage(damage);
						enemy->getComponent<TransformComponent>().velocity =
							Vector2D((flip ? 1 : -1) * damage, -1);
					}
					else
					{
						enemy->getComponent<HealthComponent>().damage(3 * damage);
						enemy->getComponent<TransformComponent>().velocity =
							Vector2D((flip ? 2 : -2) * damage, -1);
					}
					//break;
				}
			}
		}
		if (currentFrame > frames)
		{
			currentFrame = 0;
			entity->getComponent<controller>().setAttacking(false);
		}
		else
		{
			currentFrame++;
		}
	}
}

void AttackComponent::render() {
    attackbar.x = (int)entity->getComponent<TransformComponent>().position.x;
    attackbar.y = (int)entity->getComponent<TransformComponent>().position.y + 1;

    SDL_SetRenderDrawColor(GameController::renderer,attackbar.w < 48 ? 255 : 0, 0, 0, 255 );
    SDL_RenderFillRect(GameController::renderer, &attackbar);
}
