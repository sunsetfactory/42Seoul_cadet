#include "ScalarConverter.hpp"

bool ScalarConverter::isInf(const std::string &str)
{
    return str == "-inf" || str == "+inf" || str == "inf";
}

bool ScalarConverter::isNan(const std::string &str)
{
    return str == "nan";
}

void ScalarConverter::convertInf(const std::string &str)
{
    if (str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        convertInt(str);
        convertFloat(str);
        convertDouble(str);
    }
    else if (str == "+inf" || str == "inf")
    {
        std::cout << "char: impossible" << std::endl;
        convertInt(str);
        convertFloat(str);
        convertDouble(str);
    }
}

void ScalarConverter::convertNan(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    convertFloat(str);
    convertDouble(str);
}

void ScalarConverter::convertScalar(const std::string &str)
{
    convertChar(str);
    convertInt(str);
    convertFloat(str);
    convertDouble(str);
}

void ScalarConverter::convert(const std::string &str)
{
    if (isInf(str))
    {
        convertInf(str);
    }
    else if (isNan(str))
    {
        convertNan(str);
    }
    else
    {
        convertScalar(str);
    }
}

void ScalarConverter::convertChar(const std::string &str)
{
    try
    {
        // double c = std::strtod(str.c_str(), NULL);
        double c = 0;
        if (c == 0)
        {
            c = static_cast<double>((str[0]));
        }
        if (!std::isprint(c) || str == "0")
        {
            std::cout << "char: impossible" << std::endl;
        }
        else if (std::isprint(c))
        {
            std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
    }
}

void ScalarConverter::convertInt(const std::string &str)
{
    try
    {
        double d = std::strtod(str.c_str(), NULL);
        if (d == 0 && str != "0")
        {
            d = static_cast<double>((str[0]));
        }
        int i = static_cast<int>(d);

        if (d < -2147483648 || d > 2147483647)
        {
            std::cout << "int: impossible" << std::endl;
        }
        else if (std::isdigit(str[0]))
            std::cout << "int: " << i << std::endl;
        else
        {
            std::cout << "int: " << i << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "exception" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::convertFloat(const std::string &str)
{
    try
    {
        double f = std::strtod(str.c_str(), NULL);
        if (f == 0 && str != "0")
        {
            f = static_cast<float>((str[0]));
        }
        // std::cout << "float: " << static_cast<float>(f) << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(16) << f << "f" << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(7) << f << "f" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string &str)
{
    try
    {
        double d = std::strtod(str.c_str(), NULL);
        if (d == 0 && str != "0")
        {
            d = static_cast<double>((str[0]));
        }
        std::cout << "double: " << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "double: impossible" << std::endl;
    }
}