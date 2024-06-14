#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>  // std::isprint
#include <iomanip> // std::setprecision
#include <iostream>
#include <cstdlib> // std::strtod

class ScalarConverter
{
private:
  // unused private member functions, but required by the subject
  ScalarConverter();
  ScalarConverter(const ScalarConverter &obj);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &obj);

  // private member functions
  static void convertChar(const std::string &str);
  static void convertInt(const std::string &str);
  static void convertFloat(const std::string &str);
  static void convertDouble(const std::string &str);
  static void convertScalar(const std::string &str);

  // extra private member functions
  static void convertInf(const std::string &str);
  static void convertNan(const std::string &str);
  static bool isInf(const std::string &str);
  static bool isNan(const std::string &str);

public:
  // only static member functions
  static void convert(const std::string &str);
};

#endif