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

// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
//     Fixed const x = point.getX();
//     Fixed const y = point.getY();
//     Fixed const a_x = a.getX();
//     Fixed const a_y = a.getY();
//     Fixed const b_x = b.getX();
//     Fixed const b_y = b.getY();
//     Fixed const c_x = c.getX();
//     Fixed const c_y = c.getY();
//     Fixed const a1 = (x - a_x) * (b_y - a_y) - (b_x - a_x) * (y - a_y);
//     Fixed const a2 = (x - b_x) * (c_y - b_y) - (c_x - b_x) * (y - b_y);
//     Fixed const a3 = (x - c_x) * (a_y - c_y) - (a_x - c_x) * (y - c_y);

//     return (a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0);
// }

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed const x = point.getX();
    Fixed const y = point.getY();
    Fixed const a_x = a.getX();
    Fixed const a_y = a.getY();
    Fixed const b_x = b.getX();
    Fixed const b_y = b.getY();
    Fixed const c_x = c.getX();
    Fixed const c_y = c.getY();

    Fixed const a1 = (x - a_x) * (b_y - a_y) - (b_x - a_x) * (y - a_y);
    std::cout << "a1 calculation: " << a1 << std::endl;

    Fixed const a2 = (x - b_x) * (c_y - b_y) - (c_x - b_x) * (y - b_y);
    std::cout << "a2 calculation: " << a2 << std::endl;

    Fixed const a3 = (x - c_x) * (a_y - c_y) - (a_x - c_x) * (y - c_y);
    std::cout << "a3 calculation: " << a3 << std::endl;

    return (a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0);
}