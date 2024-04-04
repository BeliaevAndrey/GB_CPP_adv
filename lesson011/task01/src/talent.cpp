#include "talent.h"
#include "animal.h"

void Talent::setName(std::string inName) { name = inName; }

std::string Talent::getName() { return name; }

// std::string Talent::report() {}


Dance::Dance() {
    setName("Dance");
}

std::string Dance::report() {
    return "dancing";
}


Swim::Swim() {
    setName("Swim");
}

std::string Swim::report() {
    return "swimming";
}


Sing::Sing() {
    setName("Sing");
}
 
std::string Sing::report() {
    return "singing";
}
 