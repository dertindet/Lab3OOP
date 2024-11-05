#include "Menu.h"
#include "Song.h"
#include "InstrumentalWork.h"
#include <iostream>
#include <iomanip>
#include <set>
#include "FileHandler.h"
#include "AppException.cpp"

Menu::Menu() {
    fileHandler.loadFromFile(collection, "favorites.txt");
}

void Menu::showMainMenu() {
    int choice;
    while (true) {
        ui.displayMenu();
        choice = ui.getChoice();


        if (choice == -1) {
            continue;
        }

        try {
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
                return;  
            default:
                throw InvalidChoiceException(); 
            }
        }
        catch (const InvalidChoiceException& e) {
            ui.exceptionMessage(e);  
        }
    }
}


void Menu::addCompositionMenu() {
tryAgain:
    std::string title, detail;
    int duration, typeChoice;

    ui.displayMessage("\n1. Song\n2. Instrumental Work\nSelect the type of composition: ");
    typeChoice = ui.getChoice();
    if (typeChoice == -1) {
        goto tryAgain;
        }
    try {
        if (typeChoice == 1) {
            ui.getCompositionDetails(title, duration, detail, true);
            collection.addComposition(new Song(title, duration, detail));
        }
        else if (typeChoice == 2) {
            ui.getCompositionDetails(title, duration, detail, false);
            collection.addComposition(new InstrumentalWork(title, duration, detail));
        }
        else {
            throw InvalidChoiceException();
        }
    }
    catch (const InvalidChoiceException& e) {
        ui.exceptionMessage(e);
        goto tryAgain;
    }
}
void Menu::removeCompositionMenu() {
tryAgain1:
    try {
        int index = ui.displayCompositionListAndGetChoice(collection.getCompositions());
        if (index == 0) {
            return;  
        }
        if (index > 0 && index <= collection.getCompositions().size()) {
            collection.removeComposition(index - 1);  
        }
        else {
            throw IndexOutOfBoundsException();  
        }
    }
    catch (const IndexOutOfBoundsException& e) {
        ui.exceptionMessage(e);
        goto tryAgain1;
    }
}

void Menu::showFavoriteCompositionsMenu() {
    ui.displayMessage("\n=== Choose Favorite Compositions ===\n");
    std::set<size_t> chosen;
    int choice;
    do {
        try {
            ui.displayCompositionList(collection.getCompositions(), chosen);
            choice = ui.getChoice();
            if (choice == -1) {
                continue;
            }


            if (choice > 0 && static_cast<size_t>(choice) <= collection.getCompositions().size()) {
                if (chosen.count(choice - 1)) {
                    chosen.erase(choice - 1);
                }
                else {
                    chosen.insert(choice - 1);
                }
            }
            else if (choice != 0) {
                throw InvalidChoiceException();
            }
        }
        catch (const InvalidChoiceException& e) {
            ui.exceptionMessage(e);
        }
            
    } while (choice != 0);

    ui.displayFavoritesSummary(chosen, collection.getCompositions());
}

void Menu::showAllCompositions() {
    ui.displayMessage("\n=== All Compositions ===\n");
    for (const auto& composition : collection.getCompositions()) {
        ui.displayMessage(composition->show());
    }
    std::cout << "\n";
}