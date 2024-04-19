#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

    bool signForm(int grade, std::string formName) const;

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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);

#endif