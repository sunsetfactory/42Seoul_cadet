#include "Bureaucrat.hpp"
#include "Form.hpp"

void test4()
{
    std::cout << "==========Form test 4==========" << std::endl;
    try
    {
        Form form("서류4", 1, 1);
        Bureaucrat bureaucrat("seokjyan", 2);

        bureaucrat.incrementGrade();
        bureaucrat.signForm(form);
        bureaucrat.signForm(form);
        bureaucrat.incrementGrade();
        bureaucrat.signForm(form);
        bureaucrat.incrementGrade();
    }
    catch (const Form::FormException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::BureaucratException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}

void test3()
{
    std::cout << "==========Form test 3==========" << std::endl;
    try
    {
        Form form("서류3", 1, 1);
        Bureaucrat bureaucrat("seokjyan", 2);

        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const Form::FormException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::BureaucratException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}

void test2()
{
    std::cout << "==========Form test 2==========" << std::endl;
    try
    {
        Form form("서류2", 1, 1);
        Bureaucrat bureaucrat("seokjyan", 1);

        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (const Form::FormException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::BureaucratException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}

void test1()
{
    std::cout << "==========Form test 1==========" << std::endl;
    try
    {
        Form form("서류1", 1, 1);
        std::cout << form << std::endl;
    }
    catch (const Form::FormException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    catch (const Bureaucrat::BureaucratException &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}