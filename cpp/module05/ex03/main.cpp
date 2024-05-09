#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Intern intern;
    Bureaucrat bureaucrat("bureaucrat", 1);

    AForm *form1 = intern.makeForm("shrubbery creation", "seokjyan");
    AForm *form2 = intern.makeForm("robotomy request", "seok");
    AForm *form3 = intern.makeForm("presidential pardon", "jyan");

    bureaucrat.signForm(*form1);
    bureaucrat.executeForm(*form1);
    bureaucrat.signForm(*form2);
    bureaucrat.executeForm(*form2);
    bureaucrat.signForm(*form3);
    bureaucrat.executeForm(*form3);

    delete form1;
    delete form2;
    delete form3;

    return 0;
}
