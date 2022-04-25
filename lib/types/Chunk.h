#ifndef ENGINEJ_CHUNK_H
#define ENGINEJ_CHUNK_H

#include "Tile.h"
#include "../CONF.h"
#include <atomic>

struct Chunk {
    Tile tiles[CHUNK_SIZE][CHUNK_SIZE]{};
};

#endif //ENGINEJ_CHUNK_H
