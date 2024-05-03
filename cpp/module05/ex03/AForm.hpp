#ifndef FROM_HPP
#define FROM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

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
    virtual ~AForm();

    AForm(std::string const name, int gradeToSign, int gradeToExecute);

    std::string const &getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class AFormException
    {
      public:
        virtual const char *what() const = 0;
    };

    class GradeTooHighException : public AForm::AFormException
    {
      public:
        virtual const char *what() const;
    };

    class GradeTooLowException : public AForm::AFormException
    {
      public:
        virtual const char *what() const;
    };

    class FormNotSignedException : public AForm::AFormException
    {
      public:
        virtual const char *what() const;
    };

    class FormAlreadySignedException : public AForm::AFormException
    {
      public:
        virtual const char *what() const;
    };
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif