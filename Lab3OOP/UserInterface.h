#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include <vector>
#include "Composition.h"
#include <set>
class UserInterface {
public:
    void displayMessage(const std::string& message);
    void displayMenu();
    void displayCompositionList(const std::vector<Composition*>& compositions, const std::set<size_t>& chosen);
    int displayCompositionListAndGetChoice(const std::vector<Composition*>& compositions);
    int getChoice();
    void getCompositionDetails(std::string& title, int& duration, std::string& detail, bool isSong);
    void displayFavoritesSummary(const std::set<size_t>& chosen, const std::vector<Composition*>& compositions);
};

#endif