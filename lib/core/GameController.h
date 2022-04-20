#pragma once
#include <memory>
#include <vector>
#include "SDL.h"
#include "Entity.h"
#include "../systems/System.h"

class GameController
{
public:

    [[noreturn]] GameController();
	~GameController();		
private:
    std::vector<System*> systems;
};
