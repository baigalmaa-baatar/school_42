#include "Dummy.hpp"

Dummy::Dummy() : ATarget ("Target Practice Dummy") {}
Dummy::~Dummy() {}
ATarget *Dummy::clone() const {
    // Dummy *fwsh = new Dummy();
    return (new Dummy());
}