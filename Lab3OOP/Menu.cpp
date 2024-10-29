#include "Menu.h"
#include "Song.h"
#include "InstrumentalWork.h"
#include <iostream>
#include <iomanip>
#include <set>
#include "FileHandler.h"


Menu::Menu() {
    fileHandler.loadFromFile(collection, "favorites.txt");
}

void Menu::showMainMenu() {
    int choice;
    do {
        ui.displayMenu();
        choice = ui.getChoice();


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
            showAllCompositions(); 
            break;
        case 5:
            fileHandler.saveToFile(collection, "favorites.txt");
            ui.displayMessage("Exiting...");
            break;
        default:
            ui.displayMessage("Wrong choice. Try again.");
        }
    } while (choice != 5);
}

void Menu::addCompositionMenu() {
tryAgain:
    std::string title, detail;
    int duration, typeChoice;

    ui.displayMessage("\n1. Song\n2. Instrumental Work\nSelect the type of composition: ");
    typeChoice = ui.getChoice();

    if (typeChoice == 1) {
        ui.getCompositionDetails(title, duration, detail, true);
        collection.addComposition(new Song(title, duration, detail));
    }
    else if (typeChoice == 2) {
        ui.getCompositionDetails(title, duration, detail, false);
        collection.addComposition(new InstrumentalWork(title, duration, detail));
    }
    else {
        ui.displayMessage("Invalid choice. Enter 1 or 2.");
        goto tryAgain;
    }
}
void Menu::removeCompositionMenu() {
    int index = ui.displayCompositionListAndGetChoice(collection.getCompositions());
    if (index > 0 && static_cast<size_t>(index) <= collection.getCompositions().size()) {
        collection.removeComposition(index - 1);
    }
    else if (index != 0) {
        ui.displayMessage("Invalid index. No composition removed.");
    }
}

void Menu::showFavoriteCompositionsMenu() {
    ui.displayMessage("\n=== Choose Favorite Compositions ===\n");
    std::set<size_t> chosen;
    int choice;
    do {
        ui.displayCompositionList(collection.getCompositions(), chosen);
        choice = ui.getChoice();

        if (choice > 0 && static_cast<size_t>(choice) <= collection.getCompositions().size()) {
            if (chosen.count(choice - 1)) {
                chosen.erase(choice - 1);
            }
            else {
                chosen.insert(choice - 1);
            }
        }
        else if (choice != 0) {
            ui.displayMessage("Invalid choice. Please try again.");
        }
    } while (choice != 0);

    ui.displayFavoritesSummary(chosen, collection.getCompositions());
}
    std::cout << "\nTotal listening time for selected compositions: " << totalDuration << " seconds.\n";

void Menu::showAllCompositions() {
    ui.displayMessage("\n=== All Compositions ===\n");
    for (const auto& composition : collection.getCompositions()) {
        composition->show();
    }
    std::cout << "\n";
}