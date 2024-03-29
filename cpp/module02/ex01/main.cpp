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

#include "Fixed.hpp"
#include <bitset>
#include <iostream>

int main(void)
{
    // float num = 1.1f;

    // std::cout << num << "의 2진수 표현: ";
    // std::cout << std::bitset<sizeof(int) * 8>(num) << std::endl;
    // std::bitset<sizeof(float) * 8> bits;
    // unsigned int* num_as_uint = reinterpret_cast<unsigned int*>(&num);
    // bits = *num_as_uint;
    // std::cout << num << "의 2진수 표현: " << bits << std::endl;
    // bits = bits << 8;
    // std::cout << num << "의 2진수 표현: " << bits << std::endl;
    // bits = bits >> 8;
    // std::cout << num << "의 2진수 표현: " << bits << std::endl;
  
    Fixed a;
    // Fixed const b(10);
    Fixed const c(42.42f);
    // Fixed const d(b);
    std::cout << "asig=============" << std::endl;
    a = Fixed(-1234.4321f);

    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toFloat() << " as float" << std::endl;
    // std::cout << "d is " << d.toFloat() << " as float" << std::endl;
    return 0;
}

// 라이트 시프팅은 msb가 그대로 복사된다
// 레프트 시프팅은 무조건 0으로 체워진다
