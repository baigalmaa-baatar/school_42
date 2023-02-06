#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}
Fwoosh::~Fwoosh() {}
Fwoosh *Fwoosh::clone() const {
    Fwoosh *fwoosh = new Fwoosh();
    return fwoosh;
}