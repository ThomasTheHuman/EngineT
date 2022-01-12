import pyenginet as EngineT
from pyenginet import Entity, ComponentType

map_size = [160, 160]

EngineT.init()

Entity() \
    .add_group(5) \
    .add_component(ComponentType.TRANSFORM,
                   0,
                   0,
                   *map_size) \
    .add_component(ComponentType.SPRITE,
                   "player",
                   "sprites/player.bmp",
                   48, 48, 0, 0, 1) \
    .add_component(ComponentType.FORCE,
                   0,
                   1) \
    .add_component(ComponentType.HEALTH,
                   10,
                   10,
                   True) \
    .add_component(ComponentType.ANIMATION) \
    .add_animation(1, 0, 0, 4) \
    .add_animation(2, 0, 1, 8) \
    .add_animation(3, 5, 4, 1) \
    .add_animation(4, 4, 0, 4) \
    .add_animation(5, 0, 2, 8) \
    .add_animation(6, 6, 4, 1) \
    .add_animation(7, 0, 4, 1) \
    .add_animation(8, 0, 3, 8) \
    .add_component(ComponentType.COLLISION) \
    .add_component(ComponentType.PLAYER,
                   1) \
    .add_component(ComponentType.ATTACK,
                   100,
                   48,
                   1)

EngineT.run()
