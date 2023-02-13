#ifndef WARLOCK_H
# define WARLOCK_H

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "SpellBook.hpp"
# include "ATarget.hpp"

class ASpell;
class Atarget;

class Warlock 
{
    private:
        std::string                     _name;
        std::string                     _title;
        SpellBook                       _book;
        Warlock();
        Warlock(Warlock const &obj);
        Warlock &operator=(Warlock const &other);

    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const   &getName() const;
        std::string const   &getTitle() const;
        void                setTitle(std::string const &title);

        void                introduce() const;

        void                learnSpell(ASpell* spell_name);
        void                forgetSpell(std::string spell_name);
        void                launchSpell(std::string spell_name, ATarget const &target);

};
# endif