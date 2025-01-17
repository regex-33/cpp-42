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

Harl::~Harl() {
    std::cout << "Goodbye!" << std::endl;
}

Harl::Harl() {
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

    functions[0] = &Harl::debug;
    functions[1] = &Harl::info;
    functions[2] = &Harl::warning;
    functions[3] = &Harl::error;
}

int Harl::getIndex(std::string level) {
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

void Harl::complain(std::string level)
{
    int index = getIndex(level);
    if (index != -1)
        (this->*functions[index])();
    else
        std::cout << "Unknown complaint level: " << level << std::endl;
}

