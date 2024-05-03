#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
  private:
    std::string const _name;
    int _grade;

  public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &src);
    Bureaucrat &operator=(Bureaucrat const &src);
    ~Bureaucrat();

    Bureaucrat(std::string const name, int grade);

    std::string const &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form);

    class BureaucratException
    {
      public:
        virtual const char *what() const = 0;
    };

    class GradeTooHighException : public Bureaucrat::BureaucratException
    {
      public:
        virtual const char *what() const;
    };

    class GradeTooLowException : public Bureaucrat::BureaucratException
    {
      public:
        virtual const char *what() const;
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);

#endif