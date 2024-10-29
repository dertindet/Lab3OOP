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
    
    def save_to_file(self, filename: str):
        with open(filename, 'w') as file:
            for comp in self.compositions:
                if isinstance(comp, Song):
                    file.write(f"Song\n{comp.get_title()}\n{comp.get_duration()}\n{comp.get_vocalist()}\n")
                elif isinstance(comp, InstrumentalWork):
                    file.write(f"InstrumentalWork\n{comp.get_title()}\n{comp.get_duration()}\n{comp.get_composer()}\n")
        print(f"Compositions successfully saved to file: {filename}\n")
            
    def load_collection_from_file(self, filename: str):
        try:
            with open(filename, 'r') as file:
                while True:
                    type_line = file.readline().strip()
                    if not type_line:
                        break
                    title = file.readline().strip()
                    duration = int(file.readline().strip())
                    if type_line == "Song":
                        vocalist = file.readline().strip()
                        self.compositions.append(Song(title, duration, vocalist))
                    elif type_line == "InstrumentalWork":
                        composer = file.readline().strip()
                        self.compositions.append(InstrumentalWork(title, duration, composer))
            print(f"Data successfully loaded from file: {filename}\n")
        except FileNotFoundError:
            print(f"Could not open file for reading: {filename}")
