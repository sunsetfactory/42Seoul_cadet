/* ************************************************************************** */
/*                                        */
/*                            :::      ::::::::   */
/*   contact.cpp                    :+:      :+:    :+:   */
/*                            +:+ +:+     +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+       */
/*   Created: 2024/03/07 19:11:34 by seokjyan      #+#    #+#         */
/*   Updated: 2024/03/11 13:39:29 by seokjyan     ###   ########.fr       */
/*                                        */
/* ************************************************************************** */

#include "contacts.hpp"

contacts::contacts()
{
}
contacts::~contacts()
{
}

void contacts::set_First_name(st Fame)
{
    if (cin.eof())
        exit(0);
    First_name = Fame;
}
void contacts::set_Last_name(st Same)
{
    Last_name = Same;
}
void contacts::set_Nick_name(st Name)
{
    Nick_name = Name;
}
void contacts::set_Phone_number(st phone)
{
    Phone_number = phone;
}
void contacts::set_Dsecret(st secret)
{
    Dsecret = secret;
}
st contacts::get_First_name()
{
    return (First_name);
}
st contacts::get_Last_name()
{
    return (Last_name);
}
st contacts::get_Nick_name()
{
    return (Nick_name);
}
st contacts::get_Phone_number()
{
    return (Phone_number);
}
st contacts::get_Dsecret()
{
    return (Dsecret);
}

// void    validateInput(st msg, st *str, int type) {}
void validateInput(st msg, st *str)
{
	
    while (1)
    {
        cout << msg;
        getline(cin, *str);
        if (cin.eof())
        {
            cout << "\nEOF encountered, exiting...\n";
            cin.clear();
            clearerr(stdin);
        }
        if ((*str).empty() == 0)
            break;
    }
}
