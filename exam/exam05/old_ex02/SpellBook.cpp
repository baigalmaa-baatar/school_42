#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator it;

    for (it = _spell_book.begin(); it != _spell_book.end(); it++)
    {
        if (it->second)
            delete it->second;
    }
    _spell_book.clear();
}

void SpellBook::learnSpell(ASpell *new_spell)
{
    if (new_spell)
        _spell_book.insert(std::pair<std::string, ASpell *>(new_spell->getName(), new_spell->clone()));
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell *>::iterator it;

    it = _spell_book.find(spell_name);
    if (it != _spell_book.end())
        delete it->second;
    _spell_book.erase(spell_name);
}

ASpell* SpellBook::createSpell(std::string const &spell_name){
    std::map<std::string, ASpell *>::iterator it;
    it = _spell_book.find(spell_name);
    if (it != _spell_book.end())
        return _spell_book[spell_name];
    return 0;
}
