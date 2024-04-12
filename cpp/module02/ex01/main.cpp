/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:32:21 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/28 18:29:34 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"
int main(void)
{
    Fixed a;
    std::cout << std::endl;

    Fixed const b(10);
    std::cout << std::endl;

    Fixed const c(42.42f);
    std::cout << std::endl;

    Fixed const d(b);
    std::cout << std::endl;

    a = Fixed(1234.4321f);
    std::cout << std::endl;

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl << std::endl;

    std::cout << "a + b = " << a.toInt() + b.toInt() << std::endl;
    std::cout << "b + c + d = " << b.toInt() + c.toInt() + d.toInt() << std::endl;
    return 0;
}

// 라이트 시프팅은 msb가 그대로 복사된다
// 레프트 시프팅은 무조건 0으로 체워진다
