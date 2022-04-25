#ifndef ENGINEJ_TILE_H
#define ENGINEJ_TILE_H

#include "../CONF.h"

struct Tile {
    short traverseLevel = 0; // higher -> harder to travel through
    int sprites[TILE_LAYERS]{};
};

#endif //ENGINEJ_TILE_H
