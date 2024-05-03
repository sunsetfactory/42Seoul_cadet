#ifndef SHRUUBBERYCREATIONFORM_HPP
#define SHRUUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream> // for ofstream

class ShrubberyCreationForm : public AForm
{
  private:
    std::string _target;
    // unused
    ShrubberyCreationForm();
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

  public:
    virtual ~ShrubberyCreationForm();

    ShrubberyCreationForm(std::string const target);

    void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &src);

#endif