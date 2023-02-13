#ifndef DUMMY_H
# define DUMMY_H

# include <iostream>
# include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        virtual ~Dummy();
        Dummy* clone() const;
};

# endif
