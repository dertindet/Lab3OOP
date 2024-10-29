#ifndef MENU_H
#define MENU_H

#include "MusicCollection.h"
#include "UserInterface.h"
#include <string>
#include "FileHandler.h"

class Menu {
private:
    MusicCollection collection;
    UserInterface ui;
    FileHandler fileHandler;
    void addCompositionMenu();
    void showFavoriteCompositionsMenu();
    void removeCompositionMenu();
    void showAllCompositions();
public:
    Menu();
    void showMainMenu();
    
};

#endif