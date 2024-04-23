#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
  private:
    std::string const _name;
    int _grade;

  public:
    Bureaucrat();
    Bureaucrat(Bureaucrat const &bureaucrat);
    Bureaucrat &operator=(Bureaucrat const &bureaucrat);
    ~Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif