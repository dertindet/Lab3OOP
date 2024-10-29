#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include "MusicCollection.h"

class FileHandler {
public:
    void saveToFile(const MusicCollection& collection, const std::string& filename) const;
    void loadFromFile(MusicCollection& collection, const std::string& filename);
};

#endif 
