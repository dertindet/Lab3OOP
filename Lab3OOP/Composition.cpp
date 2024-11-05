#include "Composition.h"
#include "iostream"
#include <sstream>

Composition::Composition(const std::string& title, int duration) : title(title), duration(duration) {}

std::string Composition::getTitle() const {
    return title;
}

int Composition::getDuration() const {
    return duration;
}

std::string  Composition::show() const {
    std::ostringstream oss;
    oss << "Title: " << title << ", Duration: " << duration << " sec" << std::endl;
    return oss.str();
}