from song import Song
from instrumental_work import InstrumentalWork
from music_collection import MusicCollection

class FileHandler:
    def load_collection_from_file(self, filename: str):
        collection = MusicCollection()
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
                        collection.add_composition(Song(title, duration, vocalist))
                    elif type_line == "InstrumentalWork":
                        composer = file.readline().strip()
                        collection.add_composition(InstrumentalWork(title, duration, composer))
            print(f"Data successfully loaded from file: {filename}\n")
        except FileNotFoundError:
            print(f"Could not open file for reading: {filename}")
        return collection

    def save_to_file(self, collection: MusicCollection, filename: str):
        with open(filename, 'w') as file:
            for comp in collection.get_compositions():
                if isinstance(comp, Song):
                    file.write(f"Song\n{comp.get_title()}\n{comp.get_duration()}\n{comp.get_vocalist()}\n")
                elif isinstance(comp, InstrumentalWork):
                    file.write(f"InstrumentalWork\n{comp.get_title()}\n{comp.get_duration()}\n{comp.get_composer()}\n")
        print(f"Compositions successfully saved to file: {filename}\n")

