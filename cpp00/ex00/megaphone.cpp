/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:25:16 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/07 17:01:36 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "magaphone.hpp"

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc > 1)
    {
        i = 1;
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                // std::cout << (char)toupper(argv[i][j]);
                std::cout << static_cast<char>(toupper(argv[i][j]));
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return (0);
}


