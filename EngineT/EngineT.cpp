#include "EngineT.h"
#include "core/GameController.h"
#include "core/PrefabManager.h"
#include <memory>
#include "core/Map.h"

void start() {
    const int FPS = 120;

    const int frameDelay = 1000 / FPS;

    std::unique_ptr<GameController> game = std::make_unique<GameController>(
            "EngineT",
            2000,
            100,
            1024,
            1024,
            false);

    const Map *map = new Map(
            {151, 152, 153, 151, 152, 153, 152, 153, 151, 152, 153, 153, 151, 152, 153, 153, 153, 153, 153, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 0, 0, 0, 128, 151, 152, 153, 153, 153, 174, 175, 176, 174, 175, 176, 175, 176, 174, 175, 151, 151, 151, 151, 151, 152, 153, 176, 176, 176, 0, 0, 0, 0, 0, 0, 0, 0, 118, 0, 151, 152, 153, 153, 153, 153, 130, 0, 0, 0, 0, 128, 151, 152, 153, 153, 153, 153, 176, 176, 197, 198, 199, 197, 198, 199, 198, 199, 197, 198, 174, 174, 174, 174, 151, 151, 152, 151, 152, 153, 0, 0, 0, 0, 94, 118, 0, 0, 0, 0, 174, 175, 176, 176, 176, 176, 153, 153, 153, 151, 152, 153, 153, 153, 153, 176, 176, 176, 199, 199, 151, 152, 151, 152, 153, 151, 152, 153, 174, 175, 197, 197, 197, 197, 174, 151, 151, 174, 175, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 220, 198, 199, 199, 199, 199, 176, 176, 176, 153, 153, 153, 176, 176, 176, 199, 199, 151, 152, 153, 174, 175, 174, 175, 176, 151, 152, 153, 153, 152, 153, 151, 152, 153, 197, 174, 151, 197, 198, 199, 0, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 220, 197, 198, 199, 199, 199, 199, 176, 176, 176, 199, 199, 199, 222, 196, 174, 175, 176, 197, 198, 197, 198, 151, 152, 153, 153, 176, 152, 153, 151, 152, 153, 151, 152, 153, 151, 152, 153, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197, 198, 199, 199, 199, 199, 0, 0, 0, 0, 0, 197, 198, 199, 0, 196, 151, 152, 153, 153, 153, 176, 199, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 0, 118, 94, 0, 0, 0, 0, 94, 0, 0, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 151, 151, 152, 153, 176, 199, 197, 198, 199, 197, 198, 199, 197, 198, 199, 197, 198, 199, 0, 0, 0, 0, 0, 0, 118, 0, 0, 0, 0, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 174, 151, 152, 153, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 195, 0, 197, 151, 152, 153, 222, 0, 0, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 151, 152, 153, 151, 152, 153, 151, 152, 153, 195, 0, 0, 239, 240, 241, 0, 0, 0, 195, 195, 0, 196, 151, 152, 153, 130, 0, 0, 195, 195, 239, 240, 241, 0, 94, 0, 0, 0, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 174, 175, 176, 174, 175, 176, 174, 175, 176, 195, 0, 0, 262, 263, 264, 0, 0, 0, 195, 0, 0, 128, 151, 151, 152, 153, 0, 0, 0, 0, 262, 263, 264, 140, 141, 118, 0, 139, 140, 141, 142, 0, 139, 140, 141, 142, 0, 0, 0, 0, 197, 198, 199, 197, 198, 199, 197, 198, 199, 0, 0, 0, 285, 286, 287, 0, 0, 0, 0, 151, 151, 152, 153, 151, 152, 153, 0, 20, 0, 216, 285, 286, 287, 163, 164, 165, 0, 162, 163, 164, 165, 0, 162, 163, 164, 165, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 0, 0, 0, 0, 174, 151, 151, 152, 153, 152, 153, 0, 0, 0, 0, 0, 0, 185, 186, 187, 188, 0, 185, 186, 187, 188, 0, 185, 186, 187, 188, 0, 0, 0, 0, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 240, 241, 0, 0, 0, 0, 0, 197, 174, 151, 152, 153, 153, 152, 153, 130, 0, 0, 0, 0, 208, 209, 210, 211, 0, 208, 209, 210, 211, 0, 208, 209, 210, 211, 0, 0, 0, 0, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 262, 239, 239, 240, 241, 0, 0, 0, 0, 196, 197, 174, 175, 176, 176, 151, 151, 152, 153, 130, 0, 0, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 0, 0, 0, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 285, 262, 262, 263, 264, 0, 0, 0, 0, 0, 196, 197, 198, 199, 199, 153, 153, 151, 152, 151, 152, 153, 254, 255, 256, 257, 0, 254, 255, 256, 257, 0, 231, 232, 233, 234, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 285, 286, 287, 0, 0, 0, 0, 0, 0, 196, 151, 152, 153, 153, 176, 151, 151, 174, 175, 176, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 254, 255, 256, 257, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 151, 152, 153, 153, 153, 176, 199, 174, 151, 197, 198, 199, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 0, 151, 152, 153, 151, 152, 153, 153, 152, 153, 151, 151, 151, 151, 152, 151, 152, 153, 151, 152, 153, 0, 151, 152, 153, 153, 176, 176, 199, 200, 197, 174, 197, 198, 199, 130, 232, 233, 234, 0, 231, 232, 233, 234, 0, 254, 255, 256, 257, 0, 0, 174, 175, 176, 174, 175, 176, 176, 175, 176, 174, 174, 174, 174, 175, 174, 175, 176, 174, 175, 176, 152, 174, 175, 176, 176, 199, 199, 222, 0, 196, 197, 197, 198, 199, 153, 232, 233, 234, 0, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 0, 197, 198, 199, 197, 198, 199, 199, 198, 199, 197, 197, 197, 197, 198, 197, 198, 199, 197, 198, 199, 175, 197, 198, 199, 199, 222, 0, 0, 0, 0, 196, 197, 198, 199, 176, 232, 233, 234, 0, 231, 232, 233, 234, 0, 254, 255, 256, 257, 0, 151, 152, 153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197, 198, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197, 196, 199, 199, 232, 233, 234, 0, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 174, 175, 176, 216, 239, 239, 239, 239, 239, 239, 240, 241, 0, 0, 216, 239, 240, 241, 241, 241, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197, 198, 199, 232, 233, 234, 0, 231, 232, 233, 234, 0, 254, 255, 256, 257, 0, 197, 198, 199, 239, 262, 262, 262, 262, 262, 262, 263, 264, 0, 0, 239, 240, 241, 241, 264, 264, 264, 310, 0, 0, 0, 0, 239, 239, 239, 239, 240, 241, 0, 197, 198, 199, 232, 233, 234, 0, 231, 232, 233, 234, 0, 231, 232, 233, 234, 0, 0, 0, 0, 262, 285, 285, 285, 285, 285, 285, 286, 287, 0, 0, 262, 263, 264, 264, 287, 287, 287, 0, 0, 0, 0, 0, 262, 262, 262, 239, 240, 241, 218, 197, 198, 199, 255, 256, 257, 0, 254, 255, 256, 257, 0, 254, 255, 256, 257, 0, 151, 152, 153, 285, 285, 286, 287, 0, 0, 0, 0, 0, 0, 238, 285, 286, 287, 287, 310, 0, 0, 0, 0, 0, 0, 216, 285, 285, 285, 262, 263, 264, 288, 197, 198, 199, 278, 279, 280, 0, 277, 278, 279, 280, 0, 277, 278, 279, 280, 0, 174, 175, 176, 285, 286, 287, 0, 0, 0, 0, 0, 0, 0, 308, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 0, 197, 198, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197, 198, 199, 285, 286, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197, 198, 199, 0, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 197, 198, 199, 0, 0, 0, 118, 0, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 285, 286, 287, 0, 239, 240, 241, 310, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 285, 286, 287, 238, 262, 263, 264, 0, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 240, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 308, 285, 286, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 262, 263, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 218, 0, 0, 0, 0, 239, 239, 240, 241, 218, 0, 0, 0, 0, 118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 0, 0, 0, 0, 0, 262, 239, 239, 240, 241, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 285, 262, 262, 239, 239, 240, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 239, 240, 241, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 239, 240, 241, 241, 241, 241, 241, 239, 240, 241, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 239, 240, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 262, 239, 239, 240, 241, 218, 0, 0, 0, 0, 0, 0, 0, 239, 240, 241, 241, 241, 264, 264, 264, 264, 264, 239, 239, 240, 241, 0, 0, 0, 0, 239, 240, 241, 218, 0, 0, 308, 262, 263, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 262, 239, 239, 240, 241, 218, 0, 0, 0, 0, 0, 0, 262, 263, 264, 264, 264, 287, 287, 287, 287, 287, 262, 239, 240, 241, 0, 0, 0, 0, 262, 263, 264, 239, 240, 241, 0, 285, 286, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 308, 285, 262, 239, 239, 240, 241, 0, 0, 0, 0, 0, 0, 285, 286, 287, 287, 287, 310, 0, 0, 0, 308, 239, 240, 241, 241, 0, 0, 0, 0, 285, 286, 287, 262, 263, 264, 0, 308, 195, 195, 0, 0, 0, 0, 0, 0, 0, 0, 195, 195, 308, 285, 262, 239, 240, 241, 218, 0, 195, 195, 94, 0, 0, 0, 0, 0, 0, 0, 195, 195, 0, 0, 239, 240, 241, 264, 0, 0, 0, 0, 0, 0, 284, 285, 286, 287, 0, 0, 195, 195, 218, 0, 0, 0, 0, 0, 0, 0, 195, 195, 0, 308, 285, 239, 239, 240, 241, 218, 195, 195, 0, 118, 0, 0, 0, 0, 0, 0, 195, 195, 0, 0, 239, 240, 241, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 308, 262, 239, 239, 240, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 239, 240, 241, 310, 0, 0, 0, 153, 153, 153, 151, 152, 153, 153, 153, 153, 153, 153, 153, 153, 153, 0, 0, 94, 0, 0, 0, 0, 0, 0, 216, 285, 262, 239, 240, 241, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 239, 240, 241, 241, 241, 241, 241, 0, 0, 0, 0, 176, 176, 176, 152, 153, 153, 176, 176, 176, 176, 176, 176, 176, 176, 0, 0, 0, 118, 0, 0, 0, 0, 239, 240, 241, 241, 241, 241, 241, 0, 0, 0, 0, 0, 0, 0, 0, 239, 240, 241, 241, 241, 264, 264, 264, 264, 0, 0, 0, 0, 199, 199, 199, 153, 153, 176, 199, 199, 199, 199, 199, 199, 199, 199, 0, 0, 0, 0, 0, 0, 0, 0, 262, 263, 264, 264, 264, 264, 264, 0, 0, 0, 0, 0, 0, 0, 0, 262, 263, 264, 264, 264, 287, 287, 287, 287, 0, 0, 0, 0, 151, 239, 240, 239, 240, 241, 239, 240, 241, 239, 240, 241, 241, 241, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 239, 240, 241, 287, 287, 0, 0, 0, 239, 240, 241, 0, 0, 285, 286, 287, 287, 287, 310, 0, 0, 0, 0, 0, 0, 0, 152, 262, 263, 262, 263, 264, 262, 263, 264, 241, 241, 241, 264, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 308, 262, 263, 264, 310, 0, 0, 0, 0, 262, 263, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, 94, 0, 0, 0, 152, 285, 286, 285, 286, 287, 285, 286, 287, 264, 264, 264, 287, 287, 218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 285, 286, 287, 0, 0, 0, 0, 216, 285, 286, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 0, 0, 175, 176, 199, 0, 285, 286, 287, 287, 287, 287, 287, 287, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 151, 152, 153, 0, 0, 0, 0, 198, 199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 174, 175, 176, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 7, 7, 0, 0, 0, 7, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 192, 192, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 192, 192, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 192, 192, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 7, 190, 190, 190, 190, 190, 190, 190, 0, 0, 0, 0, 0, 7, 7, 7, 0, 192, 192, 0, 7, 7, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 166, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 95, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 282, 283, 168, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 25, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 28, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 26, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 74, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 72, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 95, 96, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 48, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 79, 79, 80, 7, 7, 7, 7, 0, 0, 0, 0, 48, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 95, 96, 7, 0, 0, 0, 0, 7, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 4, 102, 102, 103, 102, 102, 103, 7, 0, 0, 0, 0, 48, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 26, 102, 102, 102, 151, 152, 51, 52, 0, 0, 0, 0, 71, 96, 96, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 102, 102, 103, 174, 175, 176, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 102, 103, 151, 152, 153, 199, 52, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 151, 152, 153, 175, 176, 200, 52, 103, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 192, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 174, 175, 176, 198, 199, 0, 52, 103, 103, 103, 102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 215, 215, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197, 198, 199, 200, 174, 154, 28, 4, 4, 4, 4, 4, 4, 4, 7, 282, 283, 0, 0, 0, 0, 0, 0, 281, 282, 282, 283, 0, 0, 0, 0, 192, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 196, 176, 200, 0, 220, 222, 0, 0, 0, 196, 174, 176, 154, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 193, 0, 0, 0, 0, 0, 192, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 74, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 52, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 52, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 52, 0, 0, 0, 0, 0, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 52, 0, 0, 0, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 28, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 215, 0, 0, 215, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 281, 282, 282, 282, 282, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 74, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 96, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 52, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 190, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 48, 52, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 7, 0, 0, 0, 0, 7, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 3, 4, 5, 14, 14, 14, 48, 28, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 26, 0, 0, 0, 0, 28, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 26, 0, 28, 4, 4, 4, 26},
            {3, 4, 5, 7, 8, 9, 25, 26, 27, 28, 29, 30, 31, 48, 49, 50, 51, 52, 71, 72, 73, 74, 75, 79, 80, 95, 96, 97,
             102, 103, 146, 147, 148, 149, 195, 281, 282, 283},
             {54, 77, 100, 123, 192, 215, 232, 233, 255, 256});

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            PrefabManager::createMap(*map, "sprites/Assets.bmp", *new Vector2D(i * 50 * 16, j * 50 * 16));
        }
    }


    PrefabManager::createPlayer(Vector2D(25*16, 25*16));

    int renderFrame = true;
    while (game->running()) {
        const Uint32 frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        if (renderFrame) {
            game->render();
            renderFrame = false;
        } else {
            renderFrame = true;
        }

        const Uint32 frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    delete map;
}