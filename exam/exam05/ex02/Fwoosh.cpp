#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell ("Fwoosh", "fwooshed") {}
Fwoosh::~Fwoosh() {}
ASpell *Fwoosh::clone() const {
    // Fwoosh *fwsh = new Fwoosh();
    return (new Fwoosh());
}