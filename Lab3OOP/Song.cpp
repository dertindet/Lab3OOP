#include "Song.h"
#include "iostream"
#include <sstream>
Song::Song(const std::string& title, int duration, const std::string& vocalist) : Composition(title, duration), vocalist(vocalist) {}

std::string Song::show() const {
    std::ostringstream oss;
    oss << "Title: " << title << ", Duration: " << duration << " sec, Vocalist: " << vocalist;
    return oss.str();
}

std::string Song::getVocalist() const {
    return vocalist;
}