from ._pyenginet import create_entity  # noqa: F401
from ._pyenginet import add_entity_to_group  # noqa: F401
from ._pyenginet import add_component_to_entity  # noqa: F401
from ._pyenginet import add_animation  # noqa: F401


class Entity:
    def __init__(self):
        self.id = create_entity()

    def add_group(self, group):
        add_entity_to_group(self.id, group)

    def add_component(self, component_type, *args):
        add_component_to_entity(self.id, component_type.value, *args)

    def add_animation(self, _id, start_x, start_y, frames):
        add_animation(self.id, _id, start_x, start_y, frames)
