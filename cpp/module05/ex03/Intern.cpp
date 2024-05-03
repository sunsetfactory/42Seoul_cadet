#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    // Empty Body
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs; // unused
    return *this;
}

Intern::~Intern()
{
    // Empty Body
}

static AForm *newShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *newRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm *newPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    const int formNum = 3;
    std::string formTypes[formNum] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*f[formNum])(std::string) = {newShrubberyCreationForm, newRobotomyRequestForm, newPresidentialPardonForm};
    for (int i = 0; i < formNum; i++)
    {
        if (formTypes[i] == formName)
        {
            return f[i](target);
        }
    }
    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const
{
    return "Form not found";
}
