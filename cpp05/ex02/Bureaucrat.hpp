#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form;
class ShrubberyCreationForm;
class RobotomyRequestForm;

class Form
{
    private:
        std::string  _name;
        bool _signed;
        int  _gradeToSign;
        int  _gradeToExecute;
    public:
        Form();
        virtual ~Form();
        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        Form &operator=(Form const &rhs);
        virtual void beSigned(Bureaucrat const &bureaucrat) = 0;
        virtual void execute(Bureaucrat const &executor) const = 0;

        //  getters

        std::string const &getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // setters

        void setName(std::string const &_name);
        void setSigned(bool _signed);
        void setGradeToSign(int _gradeToSign);
        void setGradeToExecute(int _gradeToExecute);


        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        //std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

};


class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
        int _random;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat &operator=(Bureaucrat const &rhs);
        std::string const &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        void executeForm(Form const &form);

        void setRandom(int random);
        int getRandom() const;
        /*We define a custom exception class MyException, which inherits from std::exception. We override the what() method to provide a custom error message.*/

        class GradeTooHighException : public std::exception
        {
            /* const char* what() const throw(): This line defines a member function named what(), which returns a pointer to a constant character string (const char*). This function is marked as const, which means it doesn't modify any member variables of the class. The throw() specifier indicates that this function does not throw any exceptions (this was a feature of older C++ versions; in modern C++, this specifier is optional).*/
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
        
        //std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
        
};


class ShrubberyCreationForm : virtual public Form
{
    private:
        std::string  _target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
        // std::string const &getName() const;
        // bool getSigned() const;
        // int getGradeToSign() const;
        // int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;
        void setTarget(std::string const &target);

        class FileNotOpenException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};


class RobotomyRequestForm : virtual public Form
{
    private:
        std::string  _target;
        static int _random;
    public:
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        // std::string const &getName() const;
        // bool getSigned() const;
        // int getGradeToSign() const;
        // int getGradeToExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;//const;
        void setTarget(std::string const &target);

        class RobotomyFailureException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};


class PresidentialPardonForm : virtual public Form
{
    private:
        std::string  _target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        // std::string const &getName() const;
        // bool getSigned() const;
        // int getGradeToSign() const;
        // int getGradeToExecute() const;

        void beSigned(Bureaucrat const &bureaucrat);
        std::string const &getTarget() const;
        void execute(Bureaucrat const &executor) const;
        void setTarget(std::string const &target);
};

std::ostream& operator<<(std::ostream& os,  Form* obj);
std::ostream& operator<<(std::ostream& os,  Bureaucrat* obj);

#endif