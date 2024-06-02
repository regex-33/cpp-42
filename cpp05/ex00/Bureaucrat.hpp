#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>
#include <string>
#include <exception>


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
};

//examples:

/*
#include <iostream>

class MyException {
public:
    void bar() const  {
        std::cout << "bar() might throw exceptions." << std::endl;
        throw "An error occurred.";
    }
};

int main() {
    MyException ex;
    try {
        ex.bar();
    }
    catch (const char* error) {
        std::cerr << "Caught exception: " << error << std::endl;
    }
    return 0;
}

vs

class MyException {
public:
    void bar() const throw()  {
        std::cout << "bar() might throw exceptions." << std::endl;
    }
};

int main() {
    MyException ex;
    try {
        ex.bar();
    }
    catch (const char* error) {
        std::cerr << "Caught exception: " << error << std::endl;
    }
    return 0;
}


*/


#endif