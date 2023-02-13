#include "ATarget.hpp"

ATarget::ATarget(std::string const &type) : _type(type) {}

ATarget::~ATarget(){}

ATarget::ATarget(ATarget const &obj){
    _type = obj.getType();
}

ATarget &ATarget::operator=(ATarget const &other){
    _type = other.getType();
    return *this;
}

std::string const   &ATarget::getType() const { return _type; }
void                ATarget::getHitBySpell(ASpell const &target) const {
    std::cout << _type + " has been " + target.getEffects() + "!" << std::endl;
}