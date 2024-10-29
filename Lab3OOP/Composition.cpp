#include "Composition.h"
#include "iostream"

Composition::Composition(const std::string& title, int duration) : title(title), duration(duration) {}

std::string Composition::getTitle() const {
    return title;
}

int Composition::getDuration() const {
    return duration;
}

void Composition::show() const {
    std::cout << "Title: " << title << ", Duration: " << duration << " sec" << std::endl;
}