#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>

class Serializer
{
  private:
    // unused private member functions, but required by the subject
    Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

  public:
    // public member functions
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t &raw);
};

#endif