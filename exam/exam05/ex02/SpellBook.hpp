#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <map>
#include "ASpell.hpp"

class SpellBook
{
    private:
        std::map<std::string, ASpell *> _spell_book;

    public:
        SpellBook();
        SpellBook(SpellBook const &obj);
        SpellBook &operator=(SpellBook const &obj);
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &obj);
        ASpell* createSpell(std::string const &obj);
};

#endif