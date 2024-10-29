#ifndef MENU_H
#define MENU_H

#include "MusicCollection.h"
#include <string>

class Menu {
private:
    MusicCollection collection;

public:
    Menu();
    void showMainMenu();
    void addCompositionMenu();
    void showFavoriteCompositionsMenu();
    void removeCompositionMenu();
};

#endif