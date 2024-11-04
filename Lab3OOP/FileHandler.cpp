#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include "Song.h"
#include "InstrumentalWork.h"

void FileHandler::saveToFile(const MusicCollection& collection, const std::string& filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return;
    }

    for (const Composition* comp : collection.getCompositions()) {
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

void FileHandler::loadFromFile(MusicCollection& collection, const std::string& filename) {
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
            collection.addComposition(new Song(title, duration, vocalist));
        }
        else if (type == "InstrumentalWork") {
            std::string composer;
            std::getline(file, composer);
            collection.addComposition(new InstrumentalWork(title, duration, composer));
        }
    }

    file.close();
    std::cout << "Data successfully loaded from file: " << filename << std::endl << std::endl;
}
