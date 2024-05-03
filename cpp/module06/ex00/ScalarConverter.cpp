#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>

class ScalarConverter
{
  public:
    static void convert(const std::string &literal)
    {
        // char charValue = convertToChar(literal);
        float floatValue = convertToFloat(literal);
        double doubleValue = convertToDouble(literal);

        // std::cout << "char: ";
        // if (std::isprint(charValue))
        // {
        //     std::cout << "'" << charValue << "'" << std::endl;
        // }
        // else
        // {
        //     std::cout << "Non displayable" << std::endl;
        // }

        std::cout << "float: ";
        if (floatValue == std::numeric_limits<float>::infinity() ||
            floatValue == -std::numeric_limits<float>::infinity())
        {
            std::cout << (floatValue > 0 ? "+" : "-") << "inff" << std::endl;
        }
        else if (std::isnan(floatValue))
        {
            std::cout << "nanf" << std::endl;
        }
        else
        {
            std::cout << floatValue << "f" << std::endl;
        }

        std::cout << "double: ";
        if (doubleValue == std::numeric_limits<double>::infinity() ||
            doubleValue == -std::numeric_limits<double>::infinity())
        {
            std::cout << (doubleValue > 0 ? "+" : "-") << "inf" << std::endl;
        }
        else if (std::isnan(doubleValue))
        {
            std::cout << "nan" << std::endl;
        }
        else
        {
            std::cout << doubleValue << std::endl;
        }
        int intValue = convertToInt(literal);
        std::cout << "int: ";
        if (intValue == std::numeric_limits<int>::min() || intValue == std::numeric_limits<int>::max())
        {
            std::cout << "impossible" << std::endl;
        }
        else
        {
            std::cout << intValue << std::endl;
        }
    }

  private:
    // static char convertToChar(const std::string &literal)
    // {
    //     if (literal.length() == 1)
    //     {
    //         return literal[0];
    //     }
    //     else
    //     {
    //         throw std::invalid_argument("Invalid char literal");
    //     }
    // }

    static int convertToInt(const std::string &literal)
    {
        try
        {
            return std::stoi(literal);
        }
        catch (const std::exception &e)
        {
            throw std::invalid_argument("Invalid int literal");
        }
    }

    static float convertToFloat(const std::string &literal)
    {
        try
        {
            return std::stof(literal);
        }
        catch (const std::exception &e)
        {
            throw std::invalid_argument("Invalid float literal");
        }
    }

    static double convertToDouble(const std::string &literal)
    {
        try
        {
            return std::stod(literal);
        }
        catch (const std::exception &e)
        {
            throw std::invalid_argument("Invalid double literal");
        }
    }
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];
    // try
    // {
    std::cout << "literal: " << literal << std::endl;
    // ScalarConverter::convert(literal);
    ScalarConverter::convert(literal);
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     return 1;
    // }

    return 0;
}