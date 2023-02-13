#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell *>::iterator it;
    for (it = _my_spell_book.begin(); it != _my_spell_book.end(); it++)
    {
        if(it->second)
            delete it->second;
    }
    _my_spell_book.clear();
}

void SpellBook::learnSpell(ASpell *spell_name)
{
    if (spell_name)
        _my_spell_book.insert(std::pair<std::string, ASpell *>(spell_name->getName(), spell_name->clone()));
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell *>::iterator it;
    it = _my_spell_book.find(spell_name);
    if (it != _my_spell_book.end())
        delete it->second;
    _my_spell_book.erase(spell_name);
}

ASpell *SpellBook::createSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell *>::iterator it;
    it = _my_spell_book.find(spell_name);
    if (it != _my_spell_book.end())
        return _my_spell_book[spell_name];
    return 0;
}