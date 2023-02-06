#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << _name + ": " + "This looks like another boring day." << std::endl;
};

Warlock::~Warlock()
{
    std::cout << _name + ": " + " My job here is done!" << std::endl;
    std::map<std::string, ASpell *>::iterator it;
    for (it = _my_map.begin(); it != _my_map.end(); it++)
    {
        if (it->second)
            delete it->second;
    }
    _my_map.clear();
};

Warlock::Warlock(Warlock const &obj)
{
    _name = obj._name;
    _title = obj._title;
};

Warlock &Warlock::operator=(const Warlock &other)
{
    this->_name = other._name;
    this->_title = other._title;
    return *this;
};

const std::string &Warlock::getName(void) const { return this->_name; };
const std::string &Warlock::getTitle(void) const { return this->_title; };
void Warlock::setTitle(const std::string &title) { _title = title; };

void Warlock::introduce(void) const
{
    std::cout << _name + ": I am " + _name + ", " + _title + "!" << std::endl;
};

void Warlock::learnSpell(ASpell *obj)
{
    if (obj)
        _my_map.insert(std::pair<std::string, ASpell *>(obj->getName(), obj->clone()));
}

void Warlock::forgetSpell(std::string spell_name)
{
    std::map<std::string, ASpell *>::iterator it;

    it = _my_map.find(spell_name);
    if (it != _my_map.end())
		delete it->second;
    _my_map.erase(spell_name);
}

void Warlock::launchSpell(std::string spell_name, ATarget const &target)
{
    ASpell *spell = _my_map[spell_name];
    if (spell)
        spell->launch(target);
}
