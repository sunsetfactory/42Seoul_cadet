#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        _grade = src._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const AForm::AFormException &e)
    {
        std::cerr << _name << " couldn`t signed " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << GREEN " executed " RESET << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << this->getName() << " couldn`t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return RED "Grade is too high" RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return RED "Grade is too low" RESET;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return out;
}
