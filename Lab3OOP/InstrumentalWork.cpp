#include "InstrumentalWork.h"

InstrumentalWork::InstrumentalWork(const std::string& title, int duration, const std::string& composer) : Composition(title, duration), composer(composer) {}



std::string InstrumentalWork::getComposer() const {
    return composer;
}