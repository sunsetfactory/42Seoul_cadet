/* ************************************************************************** */
/*                                        */
/*                            :::      ::::::::   */
/*   main.cpp                       :+:      :+:    :+:   */
/*                            +:+ +:+     +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+       */
/*   Created: 2024/03/07 20:37:16 by seokjyan      #+#    #+#         */
/*   Updated: 2024/03/11 13:34:40 by seokjyan     ###   ########.fr       */
/*                                        */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

#include <iostream>

int main(void)
{
    PhoneBook div;
    st command;
    int i = 0;

    while (1)
    {
        system("clear");
        header();
        validateInput("Enter command: ", &command);
        if (command == "EXIT" || command == "exit")
            break;
        else if (command == "ADD" || command == "add")
            i = add_contact(&div, i);
        else if (command == "SEARCH" || command == "search")
            search_contact(&div);
    }
}
