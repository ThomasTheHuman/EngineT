#include "PrefabManager.h"
#include "Map.h"

void PrefabManager::createPlayer(Vector2D position)
{
	auto& player(GameController::entityManager.addEntity());
	std::string textureHash = "player";
	player.addGroup(5);
	Vector2D srcPosition;
	Vector2D force(0, 1);
	player.addComponent<TransformComponent>(position);
	player.addComponent<SpriteComponent>(textureHash, "sprites/player.bmp", Vector2D(48, 48), srcPosition, 1);
	player.addComponent<ForceComponent>(force);
	player.addComponent<HealthComponent>(10, 10);
	player.addComponent<AnimationComponent>();
	player.getComponent<AnimationComponent>().addAnimation(1, Vector2D(0, 0), 4); //idle
	player.getComponent<AnimationComponent>().addAnimation(2, Vector2D(0, 1), 8); //run
	player.getComponent<AnimationComponent>().addAnimation(3, Vector2D(5, 4), 1); //jump
	player.getComponent<AnimationComponent>().addAnimation(4, Vector2D(4, 0), 4); //defend
	player.getComponent<AnimationComponent>().addAnimation(5, Vector2D(0, 2), 8); //attack
	player.getComponent<AnimationComponent>().addAnimation(6, Vector2D(6, 4), 1); //death
	player.getComponent<AnimationComponent>().addAnimation(7, Vector2D(0, 4), 1); //damage
	player.getComponent<AnimationComponent>().addAnimation(8, Vector2D(0, 3), 8); //respawn
	player.getComponent<AnimationComponent>().setAnimation(1,false);
	player.getComponent<AnimationComponent>().play();
	player.addComponent<CollisionComponent>();
	player.addComponent<PlayerComponent>();
	player.addComponent<AttackComponent>(100, 48, 1);
}

void PrefabManager::createEnemy(Vector2D position)
{
	auto& enemy(GameController::entityManager.addEntity());
	std::string textureHash = "enemy";
	enemy.addGroup(6);
	Vector2D srcPosition;
	Vector2D force(0, 1);
	enemy.addComponent<TransformComponent>(position);
	enemy.addComponent<SpriteComponent>(textureHash,"sprites/enemy.bmp", Vector2D(48, 48), srcPosition, 1);
	enemy.addComponent<ForceComponent>(force);
	enemy.addComponent<HealthComponent>(4, 4);
	enemy.addComponent<AnimationComponent>();
	enemy.getComponent<AnimationComponent>().addAnimation(1, Vector2D(0, 0), 4); //idle
	enemy.getComponent<AnimationComponent>().addAnimation(2, Vector2D(0, 1), 8); //run
	enemy.getComponent<AnimationComponent>().addAnimation(3, Vector2D(5, 4), 1); //jump
	enemy.getComponent<AnimationComponent>().addAnimation(4, Vector2D(4, 0), 4); //defend
	enemy.getComponent<AnimationComponent>().addAnimation(5, Vector2D(0, 2), 8); //attack
	enemy.getComponent<AnimationComponent>().addAnimation(6, Vector2D(6, 4), 1); //death
	enemy.getComponent<AnimationComponent>().addAnimation(7, Vector2D(0, 4), 1); //damage
	enemy.getComponent<AnimationComponent>().setAnimation(1, false);
	enemy.getComponent<AnimationComponent>().play();
	enemy.addComponent<CollisionComponent>();
	enemy.addComponent<AIComponent>(1,true);
	enemy.addComponent<AttackComponent>(100, 48, 1);
}

void PrefabManager::createEnemy2(Vector2D position)
{
    auto& enemy(GameController::entityManager.addEntity());
    std::string textureHash = "enemy2";
    enemy.addGroup(6);
    Vector2D srcPosition;
    Vector2D force(0, 1);
    enemy.addComponent<TransformComponent>(position);
    enemy.addComponent<SpriteComponent>(textureHash,"sprites/enemy_old.bmp", Vector2D(48, 48), srcPosition, 1);
    enemy.addComponent<ForceComponent>(force);
    enemy.addComponent<HealthComponent>(10, 10);
    enemy.addComponent<AnimationComponent>();
    enemy.getComponent<AnimationComponent>().addAnimation(1, Vector2D(0, 0), 4); //idle
    enemy.getComponent<AnimationComponent>().addAnimation(2, Vector2D(0, 1), 8); //run
    enemy.getComponent<AnimationComponent>().addAnimation(3, Vector2D(5, 4), 1); //jump
    enemy.getComponent<AnimationComponent>().addAnimation(4, Vector2D(4, 0), 4); //defend
    enemy.getComponent<AnimationComponent>().addAnimation(5, Vector2D(0, 2), 8); //attack
    enemy.getComponent<AnimationComponent>().addAnimation(6, Vector2D(6, 4), 1); //death
    enemy.getComponent<AnimationComponent>().addAnimation(7, Vector2D(0, 4), 1); //damage
    enemy.getComponent<AnimationComponent>().setAnimation(1, false);
    enemy.getComponent<AnimationComponent>().play();
    enemy.addComponent<CollisionComponent>();
    enemy.addComponent<AIComponent>(1,true);
    enemy.addComponent<AttackComponent>(100, 48, 2);
}

void PrefabManager::createEyeball(Vector2D position)
{
    auto& enemy(GameController::entityManager.addEntity());
    std::string textureHash = "enemy3";
    enemy.addGroup(6);
    Vector2D srcPosition;
    Vector2D force(0, 1);
    enemy.addComponent<TransformComponent>(position);
    enemy.addComponent<SpriteComponent>(textureHash,"sprites/eyeball.bmp", Vector2D(32, 32), srcPosition, 2);
    enemy.addComponent<ForceComponent>(force);
    enemy.addComponent<HealthComponent>(2, 2);
    enemy.addComponent<AnimationComponent>();
    enemy.getComponent<AnimationComponent>().addAnimation(1, Vector2D(0, 0), 8); //idle
    enemy.getComponent<AnimationComponent>().addAnimation(2, Vector2D(0, 1), 8); //run
    enemy.getComponent<AnimationComponent>().addAnimation(3, Vector2D(0, 1), 8); //jump
    enemy.getComponent<AnimationComponent>().addAnimation(4, Vector2D(0, 2), 8); //defend
    enemy.getComponent<AnimationComponent>().addAnimation(5, Vector2D(0, 2), 8); //attack
    enemy.getComponent<AnimationComponent>().addAnimation(6, Vector2D(4, 2), 1); //death
    enemy.getComponent<AnimationComponent>().addAnimation(7, Vector2D(5, 2), 3); //damage
    enemy.getComponent<AnimationComponent>().setAnimation(1, false);
    enemy.getComponent<AnimationComponent>().play();
    enemy.addComponent<CollisionComponent>();
    enemy.addComponent<AIComponent>(3,true);
    enemy.addComponent<AttackComponent>(100, 48, 1);
}

void PrefabManager::createMap(const Map& map, const char * spriteSheet)
{
	Vector2D position;
	for(int object : map.background)
	{
		if(object)
		{
			auto& background(GameController::entityManager.addEntity());
			Vector2D srcPosition((object % 23) - 1, (object / 23));
			background.addComponent<TransformComponent>(position);
			background.addComponent<SpriteComponent>(
				spriteSheet + std::to_string(object), spriteSheet, Vector2D(16, 16), srcPosition, 1);
		}
		position.x += 16;
		if (position.x >= 128*16)
		{
			position.x = 0;
			position.y += 16;
		}
	}
	position = Vector2D();
	for (int object : map.foreground)
	{
		if (object)
		{
			auto& foreground(GameController::entityManager.addEntity());
			Vector2D srcPosition((object % 23) - 1, (object / 23));
			foreground.addComponent<TransformComponent>(position);
			foreground.addComponent<SpriteComponent>(
				spriteSheet + std::to_string(object), spriteSheet, Vector2D(16, 16), srcPosition, 1);
			if(std::find(map.block.begin(), map.block.end(), object) != map.block.end())
			{
				foreground.addGroup(1);
			}
			if (std::find(map.chain.begin(), map.chain.end(), object) != map.chain.end())
			{
				foreground.addGroup(2);
			}
		}
		position.x += 16;
		if (position.x >= 128 * 16)
		{
			position.x = 0;
			position.y += 16;
		}
	}
	position = Vector2D();
	for (int object : map.foreground)
	{
		if (object)
		{
			if (object == 322)
			{ //TODO
			    if(!(bool)(rand()%2)) {
                    createEnemy(position);
                    createEnemy(position);
                    createEnemy2(position);
                } else {
                    createEyeball(position);
                    createEyeball(position);
			    }
            }
		}
		position.x += 16;
		if (position.x >= 128 * 16)
		{
			position.x = 0;
			position.y += 16;
		}
	}
}
