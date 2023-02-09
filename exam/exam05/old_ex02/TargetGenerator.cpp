#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
    std::map<std::string, ATarget *>::iterator it;

    for (it = _my_targets.begin(); it != _my_targets.end(); it++)
    {
        if (it->second)
            delete it->second;
    }
    _my_targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *new_target)
{
    if (new_target)
        _my_targets.insert(std::pair<std::string, ATarget *>(new_target->getType(), new_target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &target_type)
{
    std::map<std::string, ATarget *>::iterator it;

    it = _my_targets.find(target_type);
    if (it != _my_targets.end())
        delete it->second;
    _my_targets.erase(target_type);
}

ATarget *TargetGenerator::createTarget(std::string const &target_type)
{
    std::map<std::string, ATarget *>::iterator it;

    it = _my_targets.find(target_type);
    if (it != _my_targets.end())
        return _my_targets[target_type];

    return NULL;
}
