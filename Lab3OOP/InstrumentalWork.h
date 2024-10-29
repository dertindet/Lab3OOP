#ifndef INSTRUMENTALWORK_H
#define INSTRUMENTALWORK_H

#include "Composition.h"

class InstrumentalWork : public Composition {
private:
    std::string composer;
public:
    InstrumentalWork(const std::string& title, int duration, const std::string& composer);


    std::string getComposer() const;
};

#endif