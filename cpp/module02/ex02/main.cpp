/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:32:21 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/17 21:44:13 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#define cout std::cout

int main( void ) {
  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << Fixed::max( a, b ) << endl;
  cout << a + b << endl;
  cout << a - b << endl;
  cout << a * b << endl;
  cout << a / b << endl;
  
  cout << "a++, a: ";
  cout.width(10);  cout << a++ << ", ";  cout.width(10);  cout << a << endl;
  cout << "++a, a: ";
  cout.width(10);  cout << ++a << ", ";  cout.width(10);  cout << a << endl;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  Fixed c(2);
  Fixed d(2);
  Fixed e(3);

  if (c < d)
    cout << d << endl;
  
  return 0;
}
