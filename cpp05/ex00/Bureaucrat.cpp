#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        _grade = grade;
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
        _grade = 1;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
        _grade = 150;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade)
{
    try {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        _grade = grade;
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
        _grade = 1;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
        _grade = 150;
    }
    std::cout << "Constructor called" << std::endl;

}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        _grade = rhs._grade;
    }
    return *this;
}


std::string const &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (_grade - 1 < 1)
            throw GradeTooHighException();
        _grade--;
    }
    catch (GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (_grade + 1 > 150)
            throw GradeTooLowException();
        _grade++;
    }
    catch (GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low";
}