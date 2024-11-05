from music_collection import MusicCollection
from file_handler import FileHandler
from user_interface import UserInterface
from song import Song
from instrumental_work import InstrumentalWork

class Menu:
    def __init__(self):
        self.collection = MusicCollection()
        self.file_handler = FileHandler()
        self.ui = UserInterface()
        self.collection = self.file_handler.load_collection_from_file("favorites.txt")

    def show_main_menu(self):
        while True:
            self.ui.display_menu()
            choice = self.ui.get_choice()

            if choice == 1:
                self.add_composition_menu()
            elif choice == 2:
                self.show_favorite_compositions_menu()
            elif choice == 3:
                self.remove_composition_menu()
            elif choice == 4:
                self.show_all_compositions()             
            elif choice == 5:
                self.file_handler.save_to_file(self.collection, "favorites.txt")
                self.ui.display_message("Exiting...")
                break
            else:
                self.ui.display_message("Wrong choice. Try again.")

    def add_composition_menu(self):
        while True:
            self.ui.display_message("\n1. Song\n2. Instrumental Work\nSelect the type of composition: ")
            type_choice = self.ui.get_choice()

            if type_choice == 1:
                title, duration, vocalist = self.ui.get_composition_details(True)
                self.collection.add_composition(Song(title, duration, vocalist))
                break
            elif type_choice == 2:
                title, duration, composer = self.ui.get_composition_details(False)
                self.collection.add_composition(InstrumentalWork(title, duration, composer))
                break
            else:
                self.ui.display_message("Invalid choice. Enter 1 or 2.")

    def remove_composition_menu(self):
        index = self.ui.display_composition_list_and_get_choice(self.collection.get_compositions())
        if index > 0 and index <= len(self.collection.get_compositions()):
            self.collection.remove_composition(index - 1)
        else:
            self.ui.display_message("Invalid index. No composition removed.")

    def show_favorite_compositions_menu(self):
        chosen = set()
        while True:
            self.ui.display_composition_list(self.collection.get_compositions(), chosen)
            choice = self.ui.get_choice()

            if choice > 0 and choice <= len(self.collection.get_compositions()):
                if choice - 1 in chosen:
                    chosen.remove(choice - 1)
                else:
                    chosen.add(choice - 1)
            elif choice == 0:
                break
            else:
                self.ui.display_message("Invalid choice. Please try again.")

        self.ui.display_favorites_summary(chosen, self.collection.get_compositions())

    def show_all_compositions(self):
        self.ui.display_message("\n=== All Compositions ===\n")
        for composition in self.collection.get_compositions():
            composition.show()
