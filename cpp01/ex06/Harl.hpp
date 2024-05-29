#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>



class Harl 
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        std::map<std::string, void (Harl::*)(void)> _complaints;
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif