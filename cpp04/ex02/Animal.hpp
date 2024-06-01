#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cerrno>


// class Animal
// {
//     protected:
//         std::string _type;
//     public:
//         Animal();
//         virtual ~Animal();
//         Animal(const Animal &copy);
//         Animal &operator=(const Animal &copy);
//         void setType(std::string type)
//         {
//             this->_type = type;
//         }
//         virtual void makeSound() const;
//         virtual std::string getType() const;
// };
/* 
GitHub Copilot: Yes, the `Animal` class you've provided is an abstract base class. In C++, a class is considered abstract if it has at least one pure virtual function. In your class, both `makeSound()` and `getType()` are pure virtual functions (denoted by `= 0`), making `Animal` an abstract base class. 

This means you cannot create instances of `Animal`, but you can create instances of classes derived from `Animal` that implement these pure virtual functions.
*/

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


class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        void setType(std::string type);
        virtual void makeSound() const = 0;
        virtual std::string getType() const = 0;
};


class Dog : virtual public Animal 
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


class Cat : virtual public Animal
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