#include "Animal.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cerr << "Exiting process now";
        //exit(1);
    }
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    // delete this->brain;
    this->brain = new Brain(*copy.brain);
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, copy.brain->getIdea(i));
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meeeoow Meeeoow Meeeoow Meeeoow Meeeoow" << std::endl;
}

std::string Cat::getType() const
{
	delete this->brain;
    return (this->_type);
}

std::string Cat::getIdea(int i) const
{
    return (this->brain->getIdea(i));
}

void Cat::setIdea(int i, std::string idea)
{
    if (i < 0 || i >= 100)
        return;
    this->brain->setIdea(i, idea);
}

void Cat::getIdeas() const
{
    for (int i = 0; i < 100; i++)
        if (this->brain->getIdea(i) != "")
            std::cout << "Idea " << i << ": " << this->brain->getIdea(i) << std::endl; 
}
