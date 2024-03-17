/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:32:21 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/17 21:39:10 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  std::cout << a + b << std::endl;
  std::cout << a - b << std::endl;
  std::cout << a * b << std::endl;
  std::cout << a / b << std::endl;
  
  std::cout << "a++, a: ";
  std::cout.width(10);  std::cout << a++ << ", ";  std::cout.width(10);  std::cout << a << std::endl;
  std::cout << "++a, a: ";
  std::cout.width(10);  std::cout << ++a << ", ";
  std::cout.width(10);  std::cout << a << std::endl;

  return 0;
}
