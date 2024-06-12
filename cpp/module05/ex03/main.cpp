#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Intern im_Intern;
    AForm *random_Form;
    Bureaucrat b("im_Bureaucrat", 1);

    random_Form = im_Intern.makeForm("robotomy request", "seokjyan");
    b.signForm(*random_Form);
    b.executeForm(*random_Form);

    random_Form = im_Intern.makeForm("presidential pardon", "seokjyan");
    b.signForm(*random_Form);
    b.executeForm(*random_Form);

    random_Form = im_Intern.makeForm("shrubbery creation", "seokjyan");
    b.signForm(*random_Form);
    b.executeForm(*random_Form);

    return 0;
}
