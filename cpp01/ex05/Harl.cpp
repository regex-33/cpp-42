#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[DEBUG] ";
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO] ";
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING] ";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR] ";
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::map<std::string, void (Harl::*)(void)> complaints;
    complaints["DEBUG"] = &Harl::debug;
    complaints["INFO"] = &Harl::info;
    complaints["WARNING"] = &Harl::warning;
    complaints["ERROR"] = &Harl::error;
    if (complaints.find(level) != complaints.end())
        (this->*complaints[level])();
}

Harl::Harl()
{
    _complaints["DEBUG"] = &Harl::debug;
    _complaints["INFO"] = &Harl::info;
    _complaints["WARNING"] = &Harl::warning;
    _complaints["ERROR"] = &Harl::error;
}

Harl::~Harl()
{
    std::cout << "Goodbye!" << std::endl;
}