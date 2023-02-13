#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell ("Fwoosh", "fwooshed") {}
Fwoosh::~Fwoosh() {}
Fwoosh *Fwoosh::clone() const {
    // Fwoosh *fwsh = new Fwoosh();
    return (new Fwoosh());
}