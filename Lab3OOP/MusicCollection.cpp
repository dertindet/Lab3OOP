#include "MusicCollection.h"
#include "Song.h"
#include "InstrumentalWork.h"
#include <iostream>
#include <fstream>
#include "UserInterface.h"

MusicCollection::MusicCollection() {}

const std::vector<Composition*>& MusicCollection::getCompositions() const {
    return compositions;
}

MusicCollection::~MusicCollection() {
    for (Composition* comp : compositions) {
        delete comp;
    }
}


void MusicCollection::addComposition(Composition* composition) {
    compositions.push_back(composition);
}

bool MusicCollection::removeComposition(size_t index) {
    if (index < compositions.size()) {
        delete compositions[index];
        compositions.erase(compositions.begin() + index);
        return true; 
    }
    return false; 
}
