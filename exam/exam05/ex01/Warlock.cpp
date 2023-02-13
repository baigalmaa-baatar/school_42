#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title) {
    std::cout << _name + ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << _name + ": My job here is done!" << std::endl;
    std::map<std::string, ASpell *>::iterator it;
    for (it = _my_map.begin(); it != _my_map.end(); it++)
        delete it->second;
    _my_map.clear();
}

Warlock::Warlock(Warlock const &obj){
    _name = obj.getName();
    _title = obj.getTitle();
}

Warlock &Warlock::operator=(Warlock const &other){
    _name = other.getName();
    _title = other.getTitle();
    return *this;
}

const std::string   &Warlock::getName() const { return _name;}
const std::string   &Warlock::getTitle() const { return _title;}
void                Warlock::setTitle(std::string const &title) { _title = title; }

void                Warlock::introduce() const {
    std::cout << _name + ": I am " + _name + ", " + _title + "!" << std::endl;
}

void                Warlock::learnSpell(ASpell* spell_name){
    if (spell_name)
        _my_map.insert(std::pair<std::string, ASpell *>(spell_name->getName(), spell_name->clone()));
}

void                Warlock::forgetSpell(std::string spell_name){
    std::map<std::string, ASpell *>::iterator it;
    it = _my_map.find(spell_name);
    if (it != _my_map.end())
        delete it->second;
    _my_map.erase(spell_name);
}

void                Warlock::launchSpell(std::string spell_name, ATarget const &target){
    std::map<std::string, ASpell *>::iterator it;
    it = _my_map.find(spell_name);
    if (it != _my_map.end())
        it->second->launch(target);
}