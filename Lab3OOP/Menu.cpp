#include "Menu.h"
#include "Song.h"
#include "InstrumentalWork.h"
#include <iostream>
#include <iomanip>
#include <set>


Menu::Menu() {
    collection.loadCollectionFromFile("favorites.txt");
}

void Menu::showMainMenu() {
    int choice;
    do {
        std::cout << "1. Add composition\n";
        std::cout << "2. Show favorite compositions\n";
        std::cout << "3. Remove composition\n"; 
        std::cout << "4. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addCompositionMenu();
            break;
        case 2:
            showFavoriteCompositionsMenu();
            break;
        case 3:
            removeCompositionMenu();
            break;
        case 4:
            collection.saveToFile("favorites.txt");
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Wrong choice. Try again.\n";
        }
    } while (choice != 4);
}

void Menu::addCompositionMenu() {
tryAgain:
    std::string title, vocalist, composer;
    int duration, typeChoice;

    std::cout << "\n1. Song\n";
    std::cout << "2. Instrumental Work\n";
    std::cout << "Select the type of composition: ";
    std::cin >> typeChoice;

    if (typeChoice == 1) {
        std::cout << "\nEnter name: ";
        std::cin >> title;
        std::cout << "Enter duration (in seconds): ";
        std::cin >> duration;
        std::cout << "Enter the name of the vocalist: ";
        std::cin >> vocalist;
        collection.addComposition(new Song(title, duration, vocalist));
    }
    else if (typeChoice == 2) {
        std::cout << "\nEnter name: ";
        std::cin >> title;
        std::cout << "Enter duration (in seconds): ";
        std::cin >> duration;
        std::cout << "Enter the name of the composer: "; 
        std::cin >> composer;
        collection.addComposition(new InstrumentalWork(title, duration, composer));
    }
    else {
        std::cout << "Enter 1 or 2";
        goto tryAgain;
    }
}
void Menu::removeCompositionMenu() {
    int index;
    for (size_t i = 0; i < collection.getCompositions().size(); ++i) {
        std::cout << std::setw(2) << i + 1 << ". "
            << collection.getCompositions()[i]->getTitle()
            << " (" << collection.getCompositions()[i]->getDuration() << " sec)\n";
    }
    std::cout << "Enter the index of the composition to remove (0 to cancel): ";
    std::cin >> index;
    if (index > 0) {
        collection.removeComposition(index - 1); 
    }
}

void Menu::showFavoriteCompositionsMenu() {
    std::cout << "\n=== Choose Favorite Compositions ===\n";

    std::set<size_t> chosen; 
    int choice = 0;

    do {
        std::cout << "Enter the number of the composition to toggle selection (0 to finish):\n";

        for (size_t i = 0; i < collection.getCompositions().size(); ++i) {
            if (chosen.count(i)) {
                std::cout << "* ";
            }
            else {
                std::cout << "  ";
            }
            std::cout << std::setw(2) << i + 1 << ". "
                << collection.getCompositions()[i]->getTitle()
                << " (" << collection.getCompositions()[i]->getDuration() << " sec)\n";
        }

        std::cin >> choice;

        if (choice > 0 && static_cast<size_t>(choice) <= collection.getCompositions().size()) {
            if (chosen.count(choice - 1)) {
                chosen.erase(choice - 1); 
            }
            else {
                chosen.insert(choice - 1); 
            }
        }
        else if (choice != 0) {
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    int totalDuration = 0;
    for (auto index : chosen) {
        totalDuration += collection.getCompositions()[index]->getDuration();
    }
    std::cout << "\nTotal listening time for selected compositions: " << totalDuration << " seconds.\n";

    for (auto index : chosen) {
        if (const Song* song = dynamic_cast<const Song*>(collection.getCompositions()[index])) {
            std::cout << "Vocalist: " << song->getVocalist() << std::endl;
        }
    }
    std::cout << "\n";
}