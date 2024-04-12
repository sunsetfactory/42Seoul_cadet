#include "Point.hpp"

Point::Point() : p_x(0), p_y(0)
{
}

Point::Point(Fixed const p_x, Fixed const p_y) : p_x(p_x), p_y(p_y)
{
}

Point::Point(Point const &src) : p_x(src.p_x), p_y(src.p_y)
{
}

Point &Point::operator=(Point const &src)
{
    if (this != &src)
    {
        const_cast<Fixed &>(this->p_x) = src.p_x;
        const_cast<Fixed &>(this->p_y) = src.p_y;
    }
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return this->p_x;
}

Fixed Point::getY() const
{
    return this->p_y;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const p_x = point.getX();
    Fixed const p_y = point.getY();
    Fixed const a_x = a.getX();
    Fixed const a_y = a.getY();
    Fixed const b_x = b.getX();
    Fixed const b_y = b.getY();
    Fixed const c_x = c.getX();
    Fixed const c_y = c.getY();
    Fixed const a1 = (p_x - a_x) * (b_y - a_y) - (b_x - a_x) * (p_y - a_y);
    std::cout << a1 << " = (" << p_x << " - " << a_x << ") * (" << b_y << " - " << a_y << ") - (" << b_x << " - " << a_x
              << ") * (" << p_y << " - " << a_y << ")" << std::endl;
    Fixed const a2 = (p_x - b_x) * (c_y - b_y) - (c_x - b_x) * (p_y - b_y);
    std::cout << a2 << " = (" << p_x << " - " << b_x << ") * (" << c_y << " - " << b_y << ") - (" << c_x << " - " << b_x
              << ") * (" << p_y << " - " << b_y << ")" << std::endl;
    Fixed const a3 = (p_x - c_x) * (a_y - c_y) - (a_x - c_x) * (p_y - c_y);
    std::cout << a3 << " = (" << p_x << " - " << c_x << ") * (" << a_y << " - " << c_y << ") - (" << a_x << " - " << c_x
              << ") * (" << p_y << " - " << c_y << ")" << std::endl;

    return (a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0);
}
