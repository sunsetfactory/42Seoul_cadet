#include "AForm.hpp"

// AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
// {
// }

// AForm::AForm(AForm const &src)
//     : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
// {
// }

// AForm &AForm::operator=(AForm const &src)
// {
//     if (this != &src)
//     {
//         _signed = src._signed;
//     }
//     return *this;
// }

AForm::~AForm()
{
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

std::string const &AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (_signed == true)
        throw AForm::FormAlreadySignedException();
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    _signed = true;
    return;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return (RED "Grade is too high" RESET);
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return (RED "Grade is too low" RESET);
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return (RED "Form is not signed" RESET);
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
    return (RED "Form is already signed" RESET);
}

std::ostream &operator<<(std::ostream &out, AForm const &src)
{
    out << "Form " << src.getName() << " is ";
    if (src.getSigned() == true)
        out << GREEN "signed" RESET;
    if (src.getSigned() == false)
        out << RED "not signed" RESET;
    out << " and requires grade " << src.getGradeToSign() << " to sign and grade " << src.getGradeToExecute()
        << " to execute";
    return out;
}
