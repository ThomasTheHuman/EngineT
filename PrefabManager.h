#pragma once
#include "GameController.h"

struct Map;

/// class of static methods used to create game objects
class PrefabManager
{
public:
	/// creates player entity
	/// @param position vector representing initial position of entity 
	static void createPlayer(Vector2D position);
	/// creates enemy entity
	/// @param position vector representing initial position of entity 
	static void createEnemy(Vector2D position);
    static void createEnemy2(Vector2D position);
    static void createEyeball(Vector2D position);
    /// generates game map entities by parsing map {@link Map} and sprite sheet
	/// @param map {@link Map}
	/// @param spriteSheet path to file with map textures
	static void createMap(const Map& map, const char* spriteSheet);
};
