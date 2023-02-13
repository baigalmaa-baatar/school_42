#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
    std::cout << _name + ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << _name + ": My job here is done!" << std::endl;
}

const std::string   &Warlock::getName() const { return _name;}
const std::string   &Warlock::getTitle() const { return _title;}
void                Warlock::setTitle(std::string const &title) { _title = title; }

void                Warlock::introduce() const {
    std::cout << _name + ": I am " + _name + ", " + _title + "!" << std::endl;
}

void                Warlock::learnSpell(ASpell* spell_name){
        _book.learnSpell(spell_name);
}

void                Warlock::forgetSpell(std::string spell_name){
    _book.forgetSpell(spell_name);
}

void                Warlock::launchSpell(std::string spell_name, ATarget const &target){
    ASpell *new_spell = _book.createSpell(spell_name);
    if (new_spell)
        new_spell->launch(target);
}