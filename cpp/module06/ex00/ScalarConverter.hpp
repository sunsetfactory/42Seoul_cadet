#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>  // std::isprint
#include <iomanip> // std::setprecision
#include <iostream>
#include <limits> // std::numeric_limits

class ScalarConverter
{
  private:
    // unused private member functions
    ScalarConverter();
    ScalarConverter(const ScalarConverter &obj);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &obj);

    static void convertChar(const std::string &str);
    static void convertInt(const std::string &str);
    static void convertFloat(const std::string &str);
    static void convertDouble(const std::string &str);

  public:
    static void convert(const std::string &str);
};

#endif // SCALARCONVERTER_HPP