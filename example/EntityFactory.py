from pyenginet import Entity
from pyenginet import ComponentType
import MapLoader


class EntityFactory:

    @staticmethod
    def spawn_player(x, y):
        Entity() \
            .add_group(5) \
            .add_component(ComponentType.TRANSFORM, x, y, *MapLoader.MapLoader.get_map_size()) \
            .add_component(ComponentType.SPRITE, "player", "sprites/player.bmp", 48, 48, 0, 0, 1) \
            .add_component(ComponentType.FORCE, 0, 1) \
            .add_component(ComponentType.HEALTH, 10, 10, True) \
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
            .add_component(ComponentType.PLAYER, 1) \
            .add_component(ComponentType.ATTACK, 100, 48, 1)
        return EntityFactory

    @staticmethod
    def spawn_skeleton(x, y):
        Entity() \
            .add_group(6) \
            .add_component(ComponentType.TRANSFORM, x, y, *MapLoader.MapLoader.get_map_size()) \
            .add_component(ComponentType.SPRITE, "enemy", "sprites/enemy.bmp", 48, 48, 0, 0, 1) \
            .add_component(ComponentType.FORCE, 0, 1) \
            .add_component(ComponentType.HEALTH, 10, 10, False) \
            .add_component(ComponentType.ANIMATION) \
            .add_animation(1, 0, 0, 4) \
            .add_animation(2, 0, 1, 8) \
            .add_animation(3, 5, 4, 1) \
            .add_animation(4, 4, 0, 4) \
            .add_animation(5, 0, 2, 8) \
            .add_animation(6, 6, 4, 1) \
            .add_animation(7, 0, 4, 1) \
            .add_component(ComponentType.COLLISION) \
            .add_component(ComponentType.AI, 1, True) \
            .add_component(ComponentType.ATTACK, 100, 48, 1)
        return EntityFactory

    @staticmethod
    def spawn_background_asset(_id, x, y):
        src_x = (_id % MapLoader.MapLoader.sprite_sheet_width) - 1
        src_y = (_id / MapLoader.MapLoader.sprite_sheet_width)
        Entity() \
            .add_group(0) \
            .add_component(ComponentType.TRANSFORM, x, y, *MapLoader.MapLoader.get_map_size()) \
            .add_component(ComponentType.SPRITE, 'assets',
                           MapLoader.MapLoader.sprite_sheet,
                           MapLoader.MapLoader.tile_size,
                           MapLoader.MapLoader.tile_size,
                           int(src_x), int(src_y), 1)
        return EntityFactory

    @staticmethod
    def spawn_asset(_id, x, y):
        asset = Entity()
        src_x = (_id % MapLoader.MapLoader.sprite_sheet_width) - 1
        src_y = (_id / MapLoader.MapLoader.sprite_sheet_width)
        if _id in MapLoader.MapLoader.blocks:
            asset.add_group(1)
        elif _id in MapLoader.MapLoader.chains:
            asset.add_group(2)
        else:
            asset.add_group(3)
        asset.add_component(ComponentType.TRANSFORM, x, y, *MapLoader.MapLoader.get_map_size())
        asset.add_component(ComponentType.SPRITE, 'assets',
                            MapLoader.MapLoader.sprite_sheet,
                            MapLoader.MapLoader.tile_size,
                            MapLoader.MapLoader.tile_size,
                            int(src_x), int(src_y), 1)
        return EntityFactory
