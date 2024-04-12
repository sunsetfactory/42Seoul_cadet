#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y)
{
}

Point::Point(Point const &src) : x(src.x), y(src.y)
{
}

Point &Point::operator=(Point const &src)
{
    if (this != &src)
    {
        const_cast<Fixed &>(this->x) = src.x;
        const_cast<Fixed &>(this->y) = src.y;
    }
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const x = point.getX();
    Fixed const y = point.getY();
    Fixed const x1 = a.getX();
    Fixed const y1 = a.getY();
    Fixed const x2 = b.getX();
    Fixed const y2 = b.getY();
    Fixed const x3 = c.getX();
    Fixed const y3 = c.getY();
    Fixed const a1 = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
    Fixed const a2 = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
    Fixed const a3 = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);

    return (a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0);
}
