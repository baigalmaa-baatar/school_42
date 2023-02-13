#ifndef SPELLBOOK_H
# define SPELLBOOK_H

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

class ASpell;
class Atarget;

class SpellBook 
{
    private:
        std::map<std::string, ASpell *>  _my_spell_book;

    public:
        SpellBook();
        ~SpellBook();

        void                learnSpell(ASpell* spell_name);
        void                forgetSpell(std::string const &spell_name);
        ASpell*             createSpell(std::string const &spell_name);

};
# endif