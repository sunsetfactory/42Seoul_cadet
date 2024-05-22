#include "ShrubberyCreationForm.hpp"

// ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
// {
// }

// ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
// {
//     *this = src;
// }

// ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
// {
//     if (this != &src)
//     {
//         this->_target = src._target;
//     }
//     return *this;
// }

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
    if (bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    std::string filename = this->_target;
    filename.append("_shrubbery");
    std::ofstream file(filename.c_str());
    if (file.fail())
    {
        std::cerr << "Error: failed to open file" << std::endl;
    }
    else
    {
        {
            file << "                                /\\\n";
            file << "                           /\\  //\\\\\n";
            file << "                    /\\    //\\\\///\\\\\\          /\\\n";
            file << "                   //\\\\  ///\\////\\\\\\\\  /\\  //\\\\\n";
            file << "          /\\      /   /  ^ \\/^ ^/^  ^  ^ \\/^ \\/  ^ \\\n";
            file << "         / ^\\    /\\  / ^   /  ^/ ^ ^ ^   ^\\ ^/  ^^  \\\n";
            file << "        /^   \\  / ^\\/ ^ ^   ^ / ^  ^    ^  \\/ ^   ^  \\       *\n";
            file << "       /  ^ ^ \\/^  ^\\ ^ ^ ^   ^  ^   ^   ____  ^   ^  \\     /|\\\n";
            file << "      / ^^  ^ ^ ^\\ ^  _\\___________________|  |_____^ ^  \\ /||o\\\n";
            file << "     / ^ ^  ^ \\ ^  _\\___________________|  |_____^ ^  \\   /||o||\\\n";
            file << "    / ^^  ^ ^ ^\\  /______________________________\\ ^ ^ \\ /|o|||||\\\n";
            file << "   /  ^  ^^ ^ ^  /________________________________\\  ^  /|||||o|||\\\n";
            file << "  /^ ^  ^ ^^  ^    ||___|___||||||||||||___|__|||      /||o||||||||\\       \n";
            file << " / ^   ^   ^    ^  ||___|___||||||||||||___|__|||          | |           \n";
            file << "/ ^ ^ ^  ^  ^  ^   ||||||||||||||||||||||||||||||oooooooooo| |ooooooo  \n";
            file << "oooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n";
        }
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
