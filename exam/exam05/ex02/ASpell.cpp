#include "ASpell.hpp"
# include "ATarget.hpp"

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects) {}

ASpell::~ASpell(){}

ASpell::ASpell(ASpell const &obj){
    _name = obj.getName();
    _effects = obj.getEffects();
}

ASpell &ASpell::operator=(ASpell const &other){
    _name = other.getName();
    _effects = other.getEffects();
    return *this;
}

std::string const   &ASpell::getName() const { return _name; }
std::string const  &ASpell::getEffects() const { return _effects; }
void                ASpell::launch(ATarget const &target) const {
    target.getHitBySpell((*this));
}
