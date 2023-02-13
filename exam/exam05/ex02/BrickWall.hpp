#ifndef BRICKWALL_H
# define BRICKWALL_H

# include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall();
        ~BrickWall();
        virtual ATarget *clone() const;
        // BrickWall* clone() const;
};

# endif
