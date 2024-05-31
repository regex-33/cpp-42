#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        void setType(std::string type)
        {
            this->_type = type;
        }
        virtual void makeSound() const;
        virtual std::string getType() const;
};

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain &copy);

        // assignment operator
        Brain &operator=(const Brain &copy);
        std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);
};

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        void makeSound() const;
        std::string getType() const;
        std::string getIdea(int i) const;
        void getIdeas() const;
        void setIdea(int i, std::string idea);
    private:
        Brain *brain;
};


class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        void makeSound() const;
        std::string getType() const;
        std::string getIdea(int i) const;
        void getIdeas() const;
        void setIdea(int i, std::string idea);
    private:
        Brain *brain;
};



class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
        WrongAnimal &operator=(const WrongAnimal &copy);
        void setType(std::string type)
        {
            this->_type = type;
        }
        virtual void makeSound() const;
        virtual std::string getType() const;
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
        void makeSound() const;
        std::string getType() const;
};
#endif