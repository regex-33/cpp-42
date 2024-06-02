#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form " << _name << " is created" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    try
    {
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw Form::GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw Form::GradeTooLowException();
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Form Constracter callled for " << _name << " with grade to sign " << _gradeToSign << " and grade to execute " << _gradeToExecute << std::endl; 
}


Form::Form(int gradeToSign, int gradeToExecute) : _name("default"), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    // try
    // {
    std::cout << "Form Constracter callled for " << _name << " with grade to sign " << _gradeToSign << " and grade to execute " << _gradeToExecute << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    // }
    // catch (Form::GradeTooHighException &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // catch (Form::GradeTooLowException &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
}


Form::~Form()
{
    std::cout << "Form Destructor called for " << _name << std::endl; 
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

std::string const &Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    try
    {
        // printf("grade of bureaucrat %d\n", bureaucrat.getGrade());
        // printf("grade to sign %d\n", _gradeToSign);
        if (bureaucrat.getGrade() > _gradeToSign)
            throw Form::GradeTooLowException();
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    if (_signed == true)
        return (std::cout << bureaucrat.getName() << " cannot sign " << _name << " because it is already signed" << std::endl, void());
    _signed = true;
    std::cout << bureaucrat.getName() << " is signing " << _name << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

// std::ostream &operator<<(std::ostream &out, Form const &form)
// {
//     out << "Form " << form.getName() << " is " << (form.getSigned() ? "" : "not ") << "signed" << std::endl;
//     out << "Grade to sign: " << form.getGradeToSign() << std::endl;
//     out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
//     return out;
// }





// Form.cpp
