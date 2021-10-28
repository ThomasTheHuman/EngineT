import pyenginet as EngineT
from pyenginet import Entity
from pyenginet import ComponentType
import json

EngineT.init()

player = Entity()
player\
    .add_group(5)\
    .add_component(ComponentType.TRANSFORM, 0, 0)\
    .add_component(ComponentType.SPRITE, "player", "sprites/player.bmp", 48, 48, 0, 0, 1)\
    .add_component(ComponentType.FORCE, 0, 1)\
    .add_component(ComponentType.HEALTH, 10, 10, True)\
    .add_component(ComponentType.ANIMATION)\
    .add_animation(1, 0, 0, 4)\
    .add_animation(2, 0, 1, 8)\
    .add_animation(3, 5, 4, 1)\
    .add_animation(4, 4, 0, 4)\
    .add_animation(5, 0, 2, 8)\
    .add_animation(6, 6, 4, 1)\
    .add_animation(7, 0, 4, 1)\
    .add_animation(8, 0, 3, 8)\
    .add_component(ComponentType.COLLISION)\
    .add_component(ComponentType.PLAYER, 1)\
    .add_component(ComponentType.ATTACK, 100, 48, 1)

map_file = open('map.json',)
map_json = json.load(map_file)
position_x = 0
position_y = 0
offset_x = 0
offset_y = 0
sprite_sheet = 'sprites/Assets.bmp'
for obj in map_json['layers'][0]['data']:
    block = Entity()
    src_x = (obj % 23) - 1
    src_y = (obj / 23)
    block.add_group(0)
    block.add_component(ComponentType.TRANSFORM, position_x + offset_x, position_y + offset_y)
    block.add_component(ComponentType.SPRITE, sprite_sheet + str(obj), sprite_sheet, 16, 16, int(src_x), int(src_y), 1)
    position_x += 16
    if position_x >= 50*16:
        position_x = 0
        position_y += 16

# Closing file
map_file.close()

EngineT.run()
