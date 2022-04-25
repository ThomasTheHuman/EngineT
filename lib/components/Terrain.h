
#ifndef ENGINEJ_TERRAIN_H
#define ENGINEJ_TERRAIN_H

#include "Component.h"
#include "../types/Chunk.h"
#include "Renderable.h"

struct Terrain : Component {
    Chunk chunks[MAP_SIZE][MAP_SIZE]{};
    Renderable sprites[MAP_TEXTURE_COUNT]{};
};

#endif //ENGINEJ_TERRAIN_H
