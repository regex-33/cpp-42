#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    if (this != &rhs)
    {
        //Form::operator=(rhs); // Call the assignment operator of the base class
        this->_target = rhs._target;
    }
    return *this;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}



void PresidentialPardonForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
    {
        throw Bureaucrat::GradeTooLowException(); 
    }
    if (this->getSigned())
    {
        std::cout << this->getName() <<" is already signed" << std::endl;
        return;
    }
    setSigned(true);
    std::cout << this->getName() << " was signed by " << bureaucrat.getName() << std::endl; 
    //_signed = true;
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
    if (!this->getSigned())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    if (executor.getGrade() > this->getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

// std::string const &PresidentialPardonForm::getName() const
// {
//     return _name;
// }

// bool PresidentialPardonForm::getSigned() const
// {
//     return _signed;
// }

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *b)
{
    // printf("i am here\n");
    // std::cout << "i am here\n" << std::endl;
    out << "Form: " << b->getName() << std::endl;
    out << "Target: " << b->getTarget() << std::endl;
    out << "Signed: " << b->getSigned() << std::endl;
    out << "Grade to sign: " << b->getGradeToSign() << std::endl;
    out << "Grade to execute: " << b->getGradeToExecute() << std::endl;
    return out;
}


void PresidentialPardonForm::setTarget(std::string const &target)
{
    this->_target = target;
}

std::string const &PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

// int PresidentialPardonForm::getGradeToSign() const
// {
//     return _gradeToSign;
// }

// int PresidentialPardonForm::getGradeToExecute() const
// {
//     return _gradeToExecute;
// }





