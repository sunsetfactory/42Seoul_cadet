#include "RobotomyRequestForm.hpp"

// RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
// {
// }

// RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
// {
//     *this = src;
// }

// RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
// {
//     if (this != &src)
//     {
//         _target = src._target;
//     }
//     return *this;
// }

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
    if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    std::cout << bureaucrat.getGrade() << " drilling noises *" << std::endl;
    system("sleep 1");
    srand(time(NULL));
    if (rand() % 2)
        std::cout << _target << GREEN " *** successfully" RESET << std::endl;
    else
        std::cout << _target << RED " *** failed" RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &src)
{
    out << "RobotomyRequestForm " << src.getName() << " is ";
    if (src.getSigned() == true)
        out << "signed\n";
    if (src.getSigned() == false)
        out << "not signed\n";
    out << "required grade " << src.getGradeToSign() << " to sign and grade " << src.getGradeToExecute()
        << " to execute";
    return out;
}
