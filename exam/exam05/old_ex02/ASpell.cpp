#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(ASpell const &obj)
{
    _name = obj._name;
    _effects = obj._effects;
}

ASpell &ASpell::operator=(const ASpell &other)
{
    this->_name = other._name;
    this->_effects = other._effects;
    return *this;
}

const std::string &ASpell::getName(void) const { return _name; }
const std::string &ASpell::getEffects(void) const { return _effects; }

void ASpell::launch(const ATarget &obj) const {
    obj.getHitBySpell((*this));
}
