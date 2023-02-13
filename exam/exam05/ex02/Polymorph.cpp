#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell ("Polymorph", "turned into a critter") {}
Polymorph::~Polymorph() {}
ASpell *Polymorph::clone() const {
    // Polymorph *fwsh = new Polymorph();
    return (new Polymorph());
}