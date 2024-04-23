#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    if (this != &src)
    {
        this->_target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::string filename = this->_target;
    filename.append("_shrubbery");
    std::ofstream file(filename.c_str());
    if (file.fail())
    {
        std::cout << "sorry, can't open " << filename << std::endl;
    }
    else
    {
        file << executor.getName() << std::endl;
        file << "      /\\      " << std::endl;
        file << "     /\\*\\     " << std::endl;
        file << "    /\\O\\*\\    " << std::endl;
        file << "   /*/\\/\\/\\   " << std::endl;
        file << "  /\\O\\/\\*\\/\\  " << std::endl;
        file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << std::endl;
        file.close();
    }
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &src)
{
    out << "ShrubberyCreationForm " << src.getName() << " is ";
    if (src.getSigned() == true)
        out << "signed\n";
    if (src.getSigned() == false)
        out << "not signed\n";
    out << "required grade " << src.getGradeToSign() << " to sign and grade " << src.getGradeToExecute()
        << " to execute";
    return out;
}
