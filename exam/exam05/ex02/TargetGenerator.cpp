#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
    // std::map<std::string, ATarget *>::iterator it;
    // for (it = _my_target_book.begin(); it != _my_target_book.end(); it++)
    // {
    //     if(it->second)
    //         delete it->second;
    // }
    // _my_target_book.clear();

    std::map<std::string, ATarget *>::iterator it_begin = this->_my_target_book.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->_my_target_book.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->_my_target_book.clear();
}

void TargetGenerator::learnTargetType(ATarget *target_type)
{
    if (target_type)
        _my_target_book.insert(std::pair<std::string, ATarget *>(target_type->getType(), target_type->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &target_type)
{
    // std::map<std::string, ATarget *>::iterator it;
    // it = _my_target_book.find(target_type);
    // if (it != _my_target_book.end())
    //     delete it->second;
    // _my_target_book.erase(target_type);
    _my_target_book.erase(target_type);

}

ATarget *TargetGenerator::createTarget(std::string const &target_type)
{
    std::map<std::string, ATarget *>::iterator it;
    it = _my_target_book.find(target_type);
    if (it != _my_target_book.end())
        return _my_target_book[target_type];
    return 0;
}