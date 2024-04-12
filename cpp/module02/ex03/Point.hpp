#include "Fixed.hpp"
#include <iostream>

class Point
{
  private:
    Fixed const x;
    Fixed const y;

  public:
    Point();
    Point(Point const &src);
    Point &operator=(Point const &rhs);
    ~Point();
    Point(Fixed const x, Fixed const y);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
