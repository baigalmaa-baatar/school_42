#ifndef TARGETGENERATOR_H
#define TARGETGENERATOR_H

#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
    private:
        std::map<std::string, ATarget *> _my_targets;
        TargetGenerator(TargetGenerator const &obj);
        TargetGenerator &operator=(TargetGenerator const &obj);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* target);
        void forgetTargetType(std::string const &target_type);
        ATarget* createTarget(std::string const &target_type);
};

#endif