#include "UserInterface.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "Song.h"
void UserInterface::displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}

void UserInterface::displayMenu() {
    std::cout << "\n1. Add composition\n";
    std::cout << "2. Show favorite compositions\n";
    std::cout << "3. Remove composition\n";
    std::cout << "4. Show all compositions\n";
    std::cout << "5. Exit\n";
    std::cout << "Select an option: ";
}

int UserInterface::displayCompositionListAndGetChoice(const std::vector<Composition*>& compositions) {
    int choice;
tryAgain:
    for (size_t i = 0; i < compositions.size(); ++i) {
        std::cout << std::setw(2) << i + 1 << ". "
            << compositions[i]->getTitle()
            << " (" << compositions[i]->getDuration() << " sec)\n";
    }
    std::cout << "Enter the index of the composition to remove (0 to cancel): ";
    while (true) {
        std::cin >> choice;

        
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "Error: Invalid input. Please enter a valid number." << std::endl << std::endl;
            goto tryAgain;
        }
        else {
            break;  
        }
    }
    return choice;
}

int UserInterface::getChoice() {
    int choice;
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        displayError("Invalid input. Please enter a valid number.");
        return -1;  
    }
    return choice;
}
void UserInterface::displayCompositionList(const std::vector<Composition*>& compositions, const std::set<size_t>& chosen) {
    for (size_t i = 0; i < compositions.size(); ++i) {
        std::cout << std::setw(2) << i + 1 << ". ";
        if (chosen.count(i)) {
            std::cout << "* "; 
        }
        std::cout << compositions[i]->getTitle()
            << " (" << compositions[i]->getDuration() << " sec)\n";
    }
}

void UserInterface::displayFavoritesSummary(const std::set<size_t>& chosen, const std::vector<Composition*>& compositions) {
    int totalDuration = 0;
    for (auto index : chosen) {
        totalDuration += compositions[index]->getDuration();
    }
    std::cout << "\nTotal listening time for selected compositions: " << totalDuration << " seconds.\n";

    for (auto index : chosen) {
        if (const Song* song = dynamic_cast<const Song*>(compositions[index])) {
            std::cout << "Vocalist: " << song->getVocalist() << "\n";
        }
    }
    std::cout << std::endl;
}
void UserInterface::getCompositionDetails(std::string& title, int& duration, std::string& detail, bool isSong) {
    std::cout << "Enter name: ";
    std::cin >> title;


    while (true) {
        std::cout << "Enter duration (in seconds): ";
        std::cin >> duration;  
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "Invalid input. Please enter a number for the duration." << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    if (isSong) {
        std::cout << "Enter the name of the vocalist: ";
    }
    else {
        std::cout << "Enter the name of the composer: ";
    }
    std::getline(std::cin, detail);  
}

void UserInterface::displayError(const std::string& errorMessage)  const {
    std::cerr << "Error: " << errorMessage << std::endl;
}
void UserInterface::exceptionMessage(const std::exception& e) {
    std::cerr << e.what() << std::endl;  
}