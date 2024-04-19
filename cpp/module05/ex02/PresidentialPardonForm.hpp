#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
    std::string _target;

  public:
    PresidentialPardonForm();
    PresidentialPardonForm(PresidentialPardonForm const &src);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
    ~PresidentialPardonForm();

    PresidentialPardonForm(std::string const target);

    void execute(Bureaucrat const &executor) const;
};

#endif