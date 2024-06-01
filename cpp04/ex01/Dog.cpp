#include "Animal.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cerr << "Exiting process now";
        exit(1);
    }
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}


Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this == &copy)
        return (*this);
    //delete this->brain;
    this->brain = new Brain(*copy.brain);
    for (int i = 0; i < 100; i++)
        this->brain->setIdea(i, copy.brain->getIdea(i));
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof Woof Woof Woof" << std::endl;
}

std::string Dog::getType() const
{
    return (this->_type);
}


std::string Dog::getIdea(int i) const
{
    return (this->brain->getIdea(i));
}

void Dog::setIdea(int i, std::string idea)
{
    if (i < 0 || i >= 100)
        return (std::cerr << "\033[31mError: Index out of bounds\033[0m" << std::endl, void());
    this->brain->setIdea(i, idea);
}

void Dog::getIdeas() const
{
    for (int i = 0; i < 100; i++)
        if (this->brain->getIdea(i) != "")
            std::cout << "Idea " << i << ": " << this->brain->getIdea(i) << std::endl; 
}
