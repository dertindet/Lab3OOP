from music_collection import MusicCollection
from song import Song
from instrumental_work import InstrumentalWork

class Menu:
    def __init__(self):
        self.collection = MusicCollection()
        self.collection.load_collection_from_file("favorites.txt")

    def show_main_menu(self):
        while True:
            print("1. Add composition\n2. Show favorite compositions\n3. Remove composition\n4. Exit")
            choice = int(input("Select an option: "))

            if choice == 1:
                self.add_composition_menu()
            elif choice == 2:
                self.show_favorite_compositions_menu()
            elif choice == 3:
                self.remove_composition_menu()
            elif choice == 4:
                self.collection.save_to_file("favorites.txt")
                print("Exiting...")
                break
            else:
                print("Wrong choice. Try again.")

    def add_composition_menu(self):
        while True:
            print("1. Song\n2. Instrumental Work")
            type_choice = int(input("Select the type of composition: "))

            title = input("Enter name: ")
            duration = int(input("Enter duration (in seconds): "))

            if type_choice == 1:
                vocalist = input("Enter the name of the vocalist: ")
                self.collection.add_composition(Song(title, duration, vocalist))
                break
            elif type_choice == 2:
                composer = input("Enter the name of the composer: ")
                self.collection.add_composition(InstrumentalWork(title, duration, composer))
                break
            else:
                print("Enter 1 or 2")

    def remove_composition_menu(self):
        for i, comp in enumerate(self.collection.get_compositions(), start=1):
            print(f"{i}. {comp.get_title()} ({comp.get_duration()} sec)")
        index = int(input("Enter the index of the composition to remove (0 to cancel): "))
        if index > 0:
            self.collection.remove_composition(index - 1)

    def show_favorite_compositions_menu(self):
        chosen = set()
        while True:
            print("Enter the number of the composition to toggle selection (0 to finish):")
            for i, comp in enumerate(self.collection.get_compositions(), start=1):
                marker = "*" if i - 1 in chosen else " "
                print(f"{marker} {i}. {comp.get_title()} ({comp.get_duration()} sec)")

            choice = int(input())
            if choice == 0:
                break
            elif 1 <= choice <= len(self.collection.get_compositions()):
                if choice - 1 in chosen:
                    chosen.remove(choice - 1)
                else:
                    chosen.add(choice - 1)
            else:
                print("Invalid choice. Please try again.")

        total_duration = sum(self.collection.get_compositions()[index].get_duration() for index in chosen)
        print(f"\nTotal listening time for selected compositions: {total_duration} seconds.\n")

        for index in chosen:
            comp = self.collection.get_compositions()[index]
            if isinstance(comp, Song):
                print("Vocalist:", comp.get_vocalist())
        print("\n")


if __name__ == "__main__":
    menu = Menu()
    menu.show_main_menu()