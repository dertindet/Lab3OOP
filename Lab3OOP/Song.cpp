#include "Song.h"
#include "iostream"
Song::Song(const std::string& title, int duration, const std::string& vocalist) : Composition(title, duration), vocalist(vocalist) {}

void Song::show() const {
    std::cout << "Title: " << title << ", Duration: " << duration << " sec, Vocalist: " << vocalist << std::endl;
}

std::string Song::getVocalist() const {
    return vocalist;
}