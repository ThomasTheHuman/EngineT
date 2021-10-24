from ._pyenginet import create_entity  # noqa: F401
from ._pyenginet import add_entity_to_group  # noqa: F401


class Entity:
    def __init__(self):
        self.id = create_entity()

    def add_group(self, group):
        add_entity_to_group(self.id, group)
