#ifndef SHRUUBBERYCREATIONFORM_HPP
#define SHRUUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:
    std::string _target;

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(std::string const target);

    void execute(Bureaucrat const &executor) const;
};

#endif