import pyenginet as EngineT
from MapLoader import MapLoader
from EntityFactory import EntityFactory


EngineT.init()

blocks = [3, 4, 5, 7, 8, 9, 25, 26, 27, 28, 29, 30, 31, 48,
          49, 50, 51, 52, 71, 72, 73, 74, 75, 79, 80, 95, 96, 97,
          102, 103, 146, 147, 148, 149, 195, 281, 282, 283]

chains = [54, 77, 100, 123, 192, 215, 232, 233, 255, 256]

MapLoader\
    .set_blocks(blocks)\
    .set_chains(chains)\
    .load("map.json", "sprites/Assets.bmp", 16, 23)

EntityFactory.spawn_player(100, 25*16)

for i in range(10):
    EntityFactory.spawn_skeleton(200*-1, 25*16)

EngineT.run()
