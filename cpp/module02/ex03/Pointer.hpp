#include "Fixed.hpp"
#include <iostream>

class Pointer
{
  private:
    const Fixed x;
    const Fixed y;

  public:
    Pointer();
    Pointer(int n);
    Pointer(Pointer const &src);
    ~Pointer();

    Pointer &operator=(Pointer const &rhs);

    int getN() const;
    void setN(int n);
};