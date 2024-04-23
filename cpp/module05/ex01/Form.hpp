#ifndef FROM_HPP
#define FROM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
  private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;

  public:
    Form();
    Form(Form const &src);
    Form &operator=(Form const &src);
    ~Form();

    Form(std::string const name, int gradeToSign, int gradeToExecute);

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
};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif