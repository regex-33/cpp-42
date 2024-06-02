#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150), _random(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) :  _name(name), _random(0)
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
    std::cout << "Bureaucrat " << _name << " is created, with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade), _random(0) 
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _random(0)
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
    std::cout << "Bureaucrat Deconstructor for " << _name << " called" << std::endl; 
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

void Bureaucrat::signForm(Form &form)
{
    // printf("form.getGradeToSign() = %d\n", form.getGradeToSign());
    // printf("_grade = %d\n", _grade);
    if (form.getGradeToSign() < _grade)
        throw GradeTooLowException();
    form.beSigned(*this);
}



std::ostream& operator<<(std::ostream& os,  Form* obj)
{

    os << "\nForm " << obj->getName() << "\n\tsign-grade: " << obj->getGradeToSign() 
       << "\n\texec-grade: " << obj->getGradeToExecute() << "\n\tis signed: " 
       << (obj->getSigned() ? "Yes\n" : "No\n");
    return os;
}

std::ostream& operator<<(std::ostream& os,  Bureaucrat* obj)
{
    os << "\nBureaucrat " << obj->getName() << "\n\tgrade: " << obj->getGrade();
    return os;
}



void Bureaucrat::executeForm(Form const &form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    }
    catch (Form::FormNotSignedException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::setRandom(int random)
{
    this->_random = random;
}

int Bureaucrat::getRandom() const
{
    return this->_random; 
}