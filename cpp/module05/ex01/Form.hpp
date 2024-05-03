#ifndef FROM_HPP
#define FROM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

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

    class FormException
    {
      public:
        virtual const char *what() const = 0;
    };

    class GradeTooHighException : public Form::FormException
    {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public Form::FormException
    {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif