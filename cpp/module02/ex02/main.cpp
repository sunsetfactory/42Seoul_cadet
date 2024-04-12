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

    std::cout << "/*================test2================*/" << std::endl;
    Fixed c(42.42f);
    Fixed d(21.21f);
    std::cout << Fixed::max(c, d) << std::endl << std::endl;

    std::cout << "/*================test3================*/" << std::endl;
    Fixed const e(42.42f);
    Fixed const f(21.21f);
    std::cout << Fixed::min(e, f) << std::endl << std::endl;
    return 0;
}
