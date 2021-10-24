#pragma once
#include <utility>
#include <vector>

/// structure holding game map
struct Map
{
	Map(std::vector<int> background, std::vector<int> foreground, std::vector<int> block, std::vector<int> chain)
	: background(std::move(background)),
	foreground(std::move(foreground)),
	block(std::move(block)),
	chain(std::move(chain)){}
	/// vector of background objects ids
	std::vector<int> background;
	/// vector of foreground objects ids
	std::vector<int> foreground;
	/// vector of ids of objects that cause collision with entities with CollisionComponent
	std::vector<int> block;
	/// vector of ids of objects that can be used by player as chain/ladder
	std::vector<int> chain;
};
