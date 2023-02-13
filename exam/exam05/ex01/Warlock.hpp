#ifndef WWARLOCK_H
# define WWARLOCK_H

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

class ASpell;
class Atarget;

class Warlock 
{
    private:
        std::string                     _name;
        std::string                     _title;
        std::map<std::string, ASpell *>  _my_map;
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