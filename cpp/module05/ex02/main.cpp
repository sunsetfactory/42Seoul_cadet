#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1("seokjyan", 1);
        std::cout << b1 << std::endl;

        PresidentialPardonForm p1("p1");
        RobotomyRequestForm r1("r1");
        ShrubberyCreationForm s1("s1");

        b1.signForm(p1);
        b1.signForm(r1);
        b1.signForm(s1);

        b1.executeForm(p1);
        b1.executeForm(r1);
        b1.executeForm(s1);

        Bureaucrat b2("", 150);
        std::cout << b2 << std::endl;
        PresidentialPardonForm p2("p2");
        // b1.signForm(p1);
        b2.signForm(p2);
    }
    catch (const AForm::AFormException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::BureaucratException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}
