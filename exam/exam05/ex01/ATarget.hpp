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
        ATarget(std::string const &type);
        virtual ~ATarget();
        ATarget(ATarget const &obj);
        ATarget &operator=(ATarget const &other);

        std::string const  &getType() const;
        void                getHitBySpell(ASpell const &target) const ;
        virtual ATarget*    clone() const = 0; //pure virtual method
};

# endif
