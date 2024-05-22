#include "Form.hpp"

// Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
// {
// }

// Form::Form(Form const &src)
//     : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
// {
// }

// Form &Form::operator=(Form const &src)
// {
//     if (this != &src)
//     {
//         _signed = src._signed;
//     }
//     return *this;
// }

Form::~Form()
{
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

std::string const &Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (_signed == true)
        throw Form::FormAlreadySignedException();
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    _signed = true;
    return;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return ("Form is already signed");
}

std::ostream &operator<<(std::ostream &out, Form const &src)
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
