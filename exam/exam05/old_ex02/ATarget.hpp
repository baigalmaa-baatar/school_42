#ifndef ATARGET_H
# define ATARGET_H

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
    std::string     _type;

public:
    ATarget();
    ATarget(std::string _type);
    ATarget(ATarget const & obj); //copy constructor
    ATarget &operator=(ATarget const &other); //operator

    virtual ~ATarget();

public:
    std::string const &getType(void) const;
    void    getHitBySpell(const ASpell &obj) const;
    virtual ATarget* clone() const = 0; //pure virtual abstract method
};

# endif