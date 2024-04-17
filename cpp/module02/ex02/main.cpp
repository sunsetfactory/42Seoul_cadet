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

#include "Fixed.hpp"
// #define cout std::cout
// #define endl std::endl

int main(void)
{
    std::cout << "/*================test1================*/" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << std::endl;

    std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl << std::endl;

    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << a << std::endl << std::endl;

    std::cout << Fixed::max(a, b) << std::endl << std::endl;

    std::cout << std::endl << "/*================test2================*/" << std::endl;
    Fixed c(42.42f);
    Fixed d(21.21f);
    std::cout << Fixed::max(c, d) << std::endl;

    std::cout << std::endl << "/*================test3================*/" << std::endl;
    Fixed const e(42.42f);
    Fixed const f(21.21f);
    std::cout << Fixed::min(e, f) << std::endl;

    std::cout << std::endl << "/*================test4================*/" << std::endl << std::endl;
    Fixed g(42.42f);
    Fixed h(21.21f);
    if (g > h)
        std::cout << "g is greater than h" << std::endl;
    else
        std::cout << "g is less than or equal to h" << std::endl;

    std::cout << std::endl << "/*================test5================*/" << std::endl << std::endl;
    Fixed i(42.42f);
    Fixed j(42.42f);

    if (i == j)
        std::cout << "i is equal to j" << std::endl;
    else
        std::cout << "i is not equal to j" << std::endl;

    std::cout << std::endl << "/*================test6================*/" << std::endl << std::endl;

    Fixed k(42.42f);
    Fixed l(10.10f);
    std::cout << k + l << std::endl;
    std::cout << k - l << std::endl;
    std::cout << k * l << std::endl;
    std::cout << k / l << std::endl;

    std::cout << std::endl << "/*===========destructor call===========*/" << std::endl << std::endl;

    return 0;
}
