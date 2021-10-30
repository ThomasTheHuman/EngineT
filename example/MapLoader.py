import json
import EntityFactory


class MapLoader:
    blocks = []
    chains = []
    map_size_x = 0
    map_size_y = 0
    sprite_sheet = ""
    sprite_sheet_width = 0
    tile_size = 0

    @classmethod
    def set_blocks(cls, _blocks):
        cls.blocks = _blocks
        return MapLoader

    @classmethod
    def set_chains(cls, _chains):
        cls.chains = _chains
        return MapLoader

    @classmethod
    def get_map_size(cls):
        return [cls.map_size_x, cls.map_size_y]

    @classmethod
    def load(cls, filename, sprite_sheet, tile_size, sprite_sheet_width):
        map_file = open(filename,)
        map_json = json.load(map_file)
        position_x = position_y = 0
        cls.map_size_x = map_json['width'] * tile_size
        cls.map_size_y = map_json['height'] * tile_size
        cls.tile_size = tile_size
        cls.sprite_sheet = sprite_sheet
        cls.sprite_sheet_width = sprite_sheet_width
        for obj in map_json['layers'][0]['data']:
            if obj != 0:
                EntityFactory.EntityFactory.spawn_background_asset(obj, position_x, position_y)
            position_x += cls.tile_size
            if position_x >= cls.map_size_x:
                position_x = 0
                position_y += cls.tile_size

        position_x = 0
        position_y = 0
        for obj in map_json['layers'][1]['data']:
            if obj != 0:
                EntityFactory.EntityFactory.spawn_asset(obj, position_x, position_y)
            position_x += cls.tile_size
            if position_x >= cls.map_size_x:
                position_x = 0
                position_y += cls.tile_size

        map_file.close()
        return MapLoader
