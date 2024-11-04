#ifndef COMPOSITION_H
#define COMPOSITION_H

#include <string>

class Composition {
protected:
    std::string title;
    int duration; 

public:
    Composition(const std::string& title, int duration);
    virtual ~Composition() = default;
    virtual void show() const;
    std::string getTitle() const;
    int getDuration() const;
};

#endif