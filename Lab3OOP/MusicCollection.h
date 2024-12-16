#ifndef MUSICCOLLECTION_H
#define MUSICCOLLECTION_H

#include "Composition.h"
#include <vector>
#include <string>

class MusicCollection {
private:
    std::vector<Composition*> compositions;

public:
    MusicCollection();
    ~MusicCollection();

    void addComposition(Composition* composition);
    const std::vector<Composition*>& getCompositions() const;
    bool removeComposition(size_t index);
};

#endif