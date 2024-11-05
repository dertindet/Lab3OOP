from instrumental_work import InstrumentalWork
from song import Song
import sys

class UserInterface:
    def display_message(self, message: str):
        print(message)

    def display_menu(self):
        print("\n1. Add composition\n2. Show favorite compositions\n3. Remove composition\n4. Show all compositions\n5. Exit\nSelect an option: ")

    def get_choice(self):
        try:
            choice = int(input())
            return choice
        except ValueError:
            print("Error: Invalid input. Please enter a number.", file=sys.stderr)
            return None
        
    def display_composition_list_and_get_choice(self, compositions):
        try: 
            for i, comp in enumerate(compositions, start=1):
                print(f"{i}. {comp.get_title()} ({comp.get_duration()} sec)")
            index = int(input("Enter the index of the composition to remove (0 to cancel): "))
            return index
        except ValueError:
            print("Error: Invalid input. Please enter a valid number.", file=sys.stderr)
            return None


    def display_composition_list(self, compositions, chosen):
        for i, comp in enumerate(compositions, start=1):
            marker = "*" if i - 1 in chosen else " "
            print(f"{marker} {i}. {comp.get_title()} ({comp.get_duration()} sec)")

    def display_favorites_summary(self, chosen, compositions):
        total_duration = sum(compositions[index].get_duration() for index in chosen)
        print(f"\nTotal listening time for selected compositions: {total_duration} seconds.\n")

        for index in chosen:
            comp = compositions[index]
            if isinstance(comp, Song):
                print("Vocalist:", comp.get_vocalist())

    def get_composition_details(self, is_song):
        title = input("Enter name: ")

        while True:
            try:
                duration = int(input("Enter duration (in seconds): "))
                break
            except ValueError:
                print("Error: Duration must be a number. Please try again.", file=sys.stderr)

        if is_song:
            print("Enter the name of the vocalist: ")
        else:
            print("Enter the name of the composer: ")

        detail = input()
        return title, duration, detail
    
    def exceptionMessage(self, e):
        print(e, file=sys.stderr)
        
    def valueErrorMessage(self):
        print("Error: Wrong choice, try again", file=sys.stderr)

