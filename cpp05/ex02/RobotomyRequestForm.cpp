#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this != &rhs)
    {
        //Form::operator=(rhs); // Call the assignment operator of the base class
        this->_target = rhs._target;
    }
    return *this;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string const &RobotomyRequestForm::getTarget() const
{
    return this->_target;
}


const char *RobotomyRequestForm::RobotomyFailureException::what() const throw()
{
    return "Robotomy failed";
}


void RobotomyRequestForm::beSigned(Bureaucrat const &bureaucrat)
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

// bool RobotomyRequestForm::getSigned() const
// {
//     return _signed;
// }

// int RobotomyRequestForm::getGradeToSign() const
// {
//     return _gradeToSign;
// }

// int RobotomyRequestForm::getGradeToExecute() const
// {
//     return _gradeToExecute;
// }

// std::string const &RobotomyRequestForm::getName() const
// {
//     return _name;
// }
int RobotomyRequestForm::_random = 0;

    void RobotomyRequestForm::execute(Bureaucrat const &executor) const
    {
        if (!this->getSigned())
            throw Form::FormNotSignedException();
        if (executor.getGrade() > this->getGradeToExecute())
            throw Bureaucrat::GradeTooLowException();
        if (executor.getGrade() > this->getGradeToSign())
            throw Bureaucrat::GradeTooLowException();

        // printf
        RobotomyRequestForm::_random++;
        if (_random % 2)
        {
            // _random++;
            std::cout << "Robotomy failed" << std::endl;
            // throw RobotomyFailureException();
        }
        else
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
    }
