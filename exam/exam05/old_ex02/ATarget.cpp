#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string type) : _type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(ATarget const &obj)
{
    _type = obj._type;
}

ATarget &ATarget::operator=(ATarget const &other)
{
    this->_type = other._type;
    return *this;
}

void    ATarget::getHitBySpell(const ASpell &obj) const 
{
    std::cout << _type + " has been " + obj.getEffects() + "!" << std::endl;
}

std::string const &ATarget::getType(void) const { return _type; }
