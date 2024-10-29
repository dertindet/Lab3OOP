#include "MusicCollection.h"
#include "Song.h"
#include "InstrumentalWork.h"
#include <iostream>
#include <fstream>

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

void MusicCollection::removeComposition(size_t index) {
    if (index < compositions.size()) {
        delete compositions[index]; 
        compositions.erase(compositions.begin() + index); 
        std::cout << "Composition removed successfully.\n\n";
    }
    else {
        std::cout << "Invalid index. No composition removed.\n";
    }
}



void MusicCollection::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return;
    }

    for (const Composition* comp : compositions) {
        if (const Song* song = dynamic_cast<const Song*>(comp)) {
            file << "Song\n";
            file << song->getTitle() << '\n';
            file << song->getDuration() << '\n';
            file << song->getVocalist() << '\n';  
        }
        else if (const InstrumentalWork* instrWork = dynamic_cast<const InstrumentalWork*>(comp)) {
            file << "InstrumentalWork\n";
            file << instrWork->getTitle() << '\n';
            file << instrWork->getDuration() << '\n';
            file << instrWork->getComposer() << '\n';  
        }
    }

    file.close();
    std::cout << "Compositions successfully saved to file: " << filename << std::endl;
}


void MusicCollection::loadCollectionFromFile(const std::string& filename) { 
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file for reading: " << filename << std::endl;
        return;
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