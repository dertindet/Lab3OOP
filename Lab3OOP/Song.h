#ifndef SONG_H
#define SONG_H

#include "Composition.h"
#include <string>

class Song : public Composition {
private:
    std::string vocalist;

public:
    Song(const std::string& title, int duration, const std::string& vocalist);


    std::string getVocalist() const;
};

#endif