#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>


class Harl {
public:
    Harl();
    ~Harl();
    void complain(std::string level);

private:
    void debug();
    void info();
    void warning();
    void error();
    
    /* Function pointer array*/
    void (Harl::*functions[4])();
    std::string levels[4];

    int getIndex(std::string level);
};


#endif