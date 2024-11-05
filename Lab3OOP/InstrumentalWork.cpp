#include "InstrumentalWork.h"
#include <iostream>
#include <sstream>

InstrumentalWork::InstrumentalWork(const std::string& title, int duration, const std::string& composer) : Composition(title, duration), composer(composer) {}

std::string InstrumentalWork::show() const {
    std::ostringstream oss;
    oss << "Title: " << title << ", Duration: " << duration << " sec, Composer: " << composer;
    return oss.str();
}

std::string InstrumentalWork::getComposer() const {
    return composer;
}