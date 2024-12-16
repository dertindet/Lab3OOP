#include "Menu.h"
#include "TestCases.cpp"
#include <iostream>
#include <fstream>

int main() {
    TestCases tests;
    tests.runAllTests();
    std::cout << "All tests finished." << std::endl;
    Menu menu;
    menu.showMainMenu();
    return 0;
}
