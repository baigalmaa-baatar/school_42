#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}
Polymorph::~Polymorph() {}
Polymorph *Polymorph::clone() const {
    Polymorph *poly = new Polymorph();
    return poly;
}