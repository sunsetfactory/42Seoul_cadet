#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Bureaucrat", 2);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
    }
    catch (Bureaucrat::BureaucratException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}