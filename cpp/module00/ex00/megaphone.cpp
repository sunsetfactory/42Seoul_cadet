/* ************************************************************************** */
/*                                        */
/*                            :::      ::::::::   */
/*   megaphone.cpp                      :+:      :+:    :+:   */
/*                            +:+ +:+     +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+       */
/*   Created: 2024/03/06 20:25:16 by seokjyan      #+#    #+#         */
/*   Updated: 2024/03/08 17:05:32 by seokjyan     ###   ########.fr       */
/*                                        */
/* ************************************************************************** */

#include <iostream>

#define cout std::cout
#define endl std::endl

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
                cout << static_cast<char>(toupper(argv[i][j]));
                j++;
            }
            i++;
        }
        cout << endl;
    }
    else
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    }
    return (0);
}
