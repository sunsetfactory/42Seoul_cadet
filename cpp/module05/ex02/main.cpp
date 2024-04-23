#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("seokjyan", 1);
		b1.incrementGrade();
		std::cout << b1 << std::endl;

		ShrubberyCreationForm s1("s1");
		b1.signForm(s1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}