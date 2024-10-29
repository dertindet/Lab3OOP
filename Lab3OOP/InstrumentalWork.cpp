#include "InstrumentalWork.h"
#include <iostream>

InstrumentalWork::InstrumentalWork(const std::string& title, int duration, const std::string& composer) : Composition(title, duration), composer(composer) {}

void InstrumentalWork::show() const {
    std::cout << "Title: " << title << ", Duration: " << duration << " sec, Composer: " << composer << std::endl;
}

std::string InstrumentalWork::getComposer() const {
    return composer;
}