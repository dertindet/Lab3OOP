#include "Song.h"

Song::Song(const std::string& title, int duration, const std::string& vocalist) : Composition(title, duration), vocalist(vocalist) {}



std::string Song::getVocalist() const {
    return vocalist;
}