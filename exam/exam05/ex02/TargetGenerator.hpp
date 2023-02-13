#ifndef TARGETGENERATOR_H
# define TARGETGENERATOR_H

# include <iostream>
# include <map>
# include "ATarget.hpp"

class ATarget;

class TargetGenerator
{
    private:
        std::map<std::string, ATarget *>  _my_target_book;

    public:
        TargetGenerator();
        ~TargetGenerator();

        void                learnTargetType(ATarget* target_type);
        void                forgetTargetType(std::string const &target_type);
        ATarget*            createTarget(std::string const &target_type);

};
# endif