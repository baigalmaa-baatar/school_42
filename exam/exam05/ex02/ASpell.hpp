#ifndef ASPELL_H
# define ASPELL_H

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
private:
    std::string     _name;
    std::string     _effects;

public:
    ASpell();
    ASpell(std::string name, std::string effects);
    ASpell(ASpell const & obj); //copy constructor
    ASpell &operator=(ASpell const &other); //operator

    virtual ~ASpell();

public:
    const   std::string & getName(void) const;
    const   std::string & getEffects(void) const;
    void    launch(ATarget const &obj) const;
    virtual ASpell* clone() const = 0; //pure abstract method
};

# endif