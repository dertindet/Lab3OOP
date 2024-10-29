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

    std::string type;
    while (std::getline(file, type)) {
        std::string title;
        int duration;


        std::getline(file, title);
        file >> duration;
        file.ignore();  

        if (type == "Song") {
            std::string vocalist;
            std::getline(file, vocalist);
            compositions.push_back(new Song(title, duration, vocalist));
        }
        else if (type == "InstrumentalWork") {
            std::string composer;
            std::getline(file, composer);
            compositions.push_back(new InstrumentalWork(title, duration, composer));
        }
    }

    file.close();
    std::cout << "Data successfully loaded from file: " << filename << std::endl << std::endl;
}