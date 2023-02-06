#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
private:
    std::string _name;
    std::string _title;

    Warlock() {}
    Warlock(Warlock const &obj);              // copy constructor
    Warlock &operator=(const Warlock &other); // operator
    std::map<std::string, ASpell *> _my_map;

public:
    Warlock(std::string name, std::string title);
    ~Warlock();

    const std::string &getName(void) const;
    const std::string &getTitle(void) const;
    void setTitle(const std::string &title);

    void introduce() const;

    void learnSpell(ASpell *obj);
    void forgetSpell(std::string spell_name);
    void launchSpell(std::string spell_name, ATarget const &target);
};

#endif