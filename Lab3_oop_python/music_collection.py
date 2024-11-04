from song import Song
from instrumental_work import InstrumentalWork
from composition import Composition

class MusicCollection:
    def __init__(self):
        self.compositions = []

    def add_composition(self, composition: Composition):
        self.compositions.append(composition)

    def remove_composition(self, index: int) -> bool:
        if 0 <= index < len(self.compositions):
            del self.compositions[index]
            return True
        return False

    def get_compositions(self) -> list:
        return self.compositions
    
