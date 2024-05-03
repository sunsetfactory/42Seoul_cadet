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
    if (form.getSigned() == true)
        throw AForm::FormAlreadySignedException();
    if (this->getGrade() > form.getGradeToSign())
        std::cout << this->getName() << RED " couldn’t sign " RESET << form.getName() << YELLOW " because " RESET;
    else
        std::cout << this->getName() << GREEN " signed " RESET << form.getName() << std::endl;
    form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (form.getSigned() == false)
        throw AForm::FormNotSignedException();
    if (this->getGrade() > form.getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();
    else
    {
        form.execute(*this);
        std::cout << this->getName() << GREEN " executed " RESET << form.getName() << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return out;
}
