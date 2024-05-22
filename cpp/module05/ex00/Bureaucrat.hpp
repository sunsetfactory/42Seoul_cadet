#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Bureaucrat
{
private:
  std::string const _name;
  int _grade;

  // unused
  Bureaucrat();
  Bureaucrat(Bureaucrat const &src);
  Bureaucrat &operator=(Bureaucrat const &src);

public:
  ~Bureaucrat();

  Bureaucrat(std::string const name, int grade);

  std::string const &getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class BureaucratException : public std::exception
  {
    // public:
    //   virtual const char *what() const = 0;
  };

  class GradeTooHighException : public Bureaucrat::BureaucratException
  {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public Bureaucrat::BureaucratException
  {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);

#endif