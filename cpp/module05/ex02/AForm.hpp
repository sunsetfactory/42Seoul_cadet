#ifndef FROM_HPP
#define FROM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm
{
  private:
    std::string const _name;
    bool _signed;
    int const _gradeToSign;
    int const _gradeToExecute;

  public:
    AForm();
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);
    ~AForm();

    AForm(std::string const name, int gradeToSign, int gradeToExecute);

    std::string const &getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const &bureaucrat);

    virtual void execute(Bureaucrat const &executor) const;

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

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif