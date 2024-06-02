#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
    public:
        Form();
        ~Form();
        Form(std::string const &name, int gradeToSign, int gradeToExecute);
        Form(int gradeToSign, int gradeToExecute);
        Form(Form const &src);
        Form &operator=(Form const &rhs);
        std::string const &getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(Bureaucrat const &bureaucrat);

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

        //std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

};


class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
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


std::ostream& operator<<(std::ostream& os,  Form* obj);
std::ostream& operator<<(std::ostream& os,  Bureaucrat* obj);

#endif