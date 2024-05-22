#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
  // unused private member functions but required by the subject
  Intern(const Intern &ref);
  Intern &operator=(const Intern &ref);

public:
  Intern();
  ~Intern();

  AForm *makeForm(std::string formName, std::string target);

  class FormNotFoundException
  {
    const char *what() const;
  };
};

#endif