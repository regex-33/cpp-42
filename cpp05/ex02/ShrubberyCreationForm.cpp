#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if (this != &rhs)
    {
        //Form::operator=(rhs); // Call the assignment operator of the base class
        this->_target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string const &ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
    return "File could not be opened";
}

void ShrubberyCreationForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    if (this->getSigned())
    {
        std::cout << this->getName() <<" is already signed" << std::endl;
        return;
    }
    setSigned(true);
    std::cout << this->getName() << " was signed by " << bureaucrat.getName() << std::endl;

    // _signed = true;
}



void ShrubberyCreationForm::execute(Bureaucrat const &executor) const 
{
    if (!this->getSigned())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    if (executor.getGrade() > this->getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    // if (this->_target.empty())
        // throw ShrubberyCreationForm::FileNotOpenException();
    std::ofstream file(this->_target + "_shrubbery");
    if (!file.is_open())
        throw ShrubberyCreationForm::FileNotOpenException();
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
    file.close();
}

// std::string const &ShrubberyCreationForm::getName() const
// {
//     return _name;
// }

// bool ShrubberyCreationForm::getSigned() const
// {
//     return _signed;
// }

// int ShrubberyCreationForm::getGradeToSign() const
// {
//     return _gradeToSign;
// }

// int ShrubberyCreationForm::getGradeToExecute() const
// {
//     return _gradeToExecute;
// }

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &obj)
{
    os << obj.getName() << " is ";
    if (!obj.getSigned())
        os << "not ";
    os << "signed, it requires a grade " << obj.getGradeToSign() << " to sign and a grade " << obj.getGradeToExecute() << " to execute.";
    return os;
}
void ShrubberyCreationForm::setTarget(std::string const &target)
{
    this->_target = target;
}

