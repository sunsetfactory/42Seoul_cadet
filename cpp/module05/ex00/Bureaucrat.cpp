#include "Bureaucrat.hpp"

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
    if (this == &src)
        return *this;
    _grade = src._grade;
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

// throw 혹시 아시나요?
// 함수 뒤에 throw가 붙는 걸 아시나요?
// 우린 예외가 발생할 수 있는 객체의 형을 미리 지정해줄 수 있어요
// 그리고 이를 기반으로 예외처리를 만들어 놓을 수있는데
// 이게 거지같아서 없에버렸습니다 언제부터? 11~17년도 동안 차근 차근
// 하지만 잔재가 남아있죠