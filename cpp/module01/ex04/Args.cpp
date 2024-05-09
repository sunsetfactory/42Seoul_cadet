/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Args.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:59 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 16:39:46 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Args.hpp"

Args::Args(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "argc is not 4" << std::endl;
        exit(1);
    }
    else
    {
        if (ValidateArgs(av) == false)
            exit(1);
        filename = av[1];
        s1 = av[2];
        s2 = av[3];
    }
}

Args::~Args()
{
}

std::string Args::getFilename()
{
    return (filename);
}
std::string Args::getS1()
{
    return (s1);
}
std::string Args::getS2()
{
    return (s2);
}

bool Args::ValidateArgs(char *av[])
{
    std::string filename;
    std::string s1;
    std::string s2;

    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    if (filename.length() == 0 || s1.length() == 0 || s2.length() == 0)
    {
        std::cout << "argv length is 0" << std::endl;
        return (false);
    }
    return (true);
}
