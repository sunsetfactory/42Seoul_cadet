/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:32:21 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/30 17:15:52 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
// #define cout std::cout
// #define endl std::endl

int main(void)
{
    Point a(8, 4);
    Point b(0, 4);
    Point c(6, 2);
    // Point a(10, 10);
    // Point b(6, 6);
    // Point c(12, 4);
    Point point(10.0f, 6.0f);

    std::cout << "point: " << point.getX() << ", " << point.getY() << std::endl;

    if (bsp(a, b, c, point))
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;

    return 0;
}
