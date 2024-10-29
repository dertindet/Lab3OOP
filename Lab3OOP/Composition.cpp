#include "Composition.h"

Composition::Composition(const std::string& title, int duration) : title(title), duration(duration) {}

std::string Composition::getTitle() const {
    return title;
}

int Composition::getDuration() const {
    return duration;
}