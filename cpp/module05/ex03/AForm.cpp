#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
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

AForm::AForm(AForm const &src)
    : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

AForm &AForm::operator=(AForm const &src)
{
    if (this != &src)
    {
        _signed = src._signed;
    }
    return *this;
}

AForm::~AForm()
{
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
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    _signed = true;
    return;
}

const char *AForm::GradeTooHighException::what() const
{
    return ("\033[3;33mGrade is too high\033[0m");
}

const char *AForm::GradeTooLowException::what() const
{
    return ("\033[3;33mGrade is too low\033[0m");
}

const char *AForm::FormNotSignedException::what() const
{
    return ("\033[3;33mForm is not signed\033[0m");
}

const char *AForm::FormAlreadySignedException::what() const
{
    return ("\033[3;33mForm is already signed\033[0m");
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
