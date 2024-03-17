/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:32:21 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/17 21:53:26 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#define cout std::cout
#define endl std::endl

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

  if (c < e)
    cout << "e" << endl;
  else
    cout << "c" << endl;

  if (c == d)
    cout << "equal" << endl;
  else
    cout << "diff" << endl;

  if (c != e)
    cout << "diff" << endl;
  else
    cout << "equal" << endl;
  return 0;
}
