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
    void saveToFile(const std::string& filename) const;
    void loadCollectionFromFile(const std::string& filename);
    const std::vector<Composition*>& getCompositions() const;
    void removeComposition(size_t index);
};

#endif