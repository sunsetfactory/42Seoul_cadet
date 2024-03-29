/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:45:19 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/29 14:40:14 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string strORI = "HI THIS IS BRAIN";
    std::string *stringPTR = &strORI;
    std::string &stringREF = strORI;

    std::cout << "Address in memory of the string: " << &strORI << std::endl;
    std::cout << "Address in memory of the stringPTR: " << &stringPTR << std::endl;
    std::cout << "Address in memory of the stringREF: " << &stringREF << std::endl;

    std::cout << "StringORI: " << strORI << std::endl;
    std::cout << "StringPTR: " << stringPTR << std::endl;
    std::cout << "StringREF: " << stringREF << std::endl;
    return (0);
}
