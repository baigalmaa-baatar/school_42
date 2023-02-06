#ifndef WARLOCK_H
# define WARLOCK_H

# include <iostream>

class Warlock
{
private:
    std::string _name;
    std::string _title;

public:
    Warlock();
    Warlock(std::string name, std::string title);
    Warlock(Warlock const & obj); //copy constructor
    Warlock &operator=(const Warlock &other); //operator

    ~Warlock();

public:
    const   std::string & getName(void) const;
    const   std::string & getTitle(void) const;
    void                setTitle(const std::string & title);

    void introduce() const;
};

# endif