#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include "Song.h"
#include "InstrumentalWork.h"
#include "AppException.cpp"
void FileHandler::saveToFile(const MusicCollection& collection, const std::string& filename) const {
    try {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw FileException("Could not open file for writing: " + filename);
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
    }
    catch (const FileException& e) {
        ui.displayError(e.what()); 
    }
    catch (const std::exception& e) {
        ui.displayError(std::string("Unexpected error: ") + e.what());
    }
}

void FileHandler::loadFromFile(MusicCollection& collection, const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw FileException("Could not open file for reading: " + filename);
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
    }
    catch (const FileException& e) {
        ui.displayError(e.what());
    }
    catch (const std::exception& e) {
        ui.displayError(std::string("Unexpected error while loading file: ") + e.what());
    }

}
