#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib> // for system
#include <ctime>   // for rand
#include <fstream>

class RobotomyRequestForm : public AForm
{
private:
  std::string _target;

  // unused private member functions but required by the subject
  RobotomyRequestForm();
  RobotomyRequestForm(RobotomyRequestForm const &src);
  RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

public:
  virtual ~RobotomyRequestForm();

  RobotomyRequestForm(std::string const target);

  void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &src);

#endif