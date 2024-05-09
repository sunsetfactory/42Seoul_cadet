/* ************************************************************************** */
/*                                        */
/*                            :::      ::::::::   */
/*   contacts.hpp                       :+:      :+:    :+:   */
/*                            +:+ +:+     +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+       */
/*   Created: 2024/03/07 19:26:09 by seokjyan      #+#    #+#         */
/*   Updated: 2024/03/11 13:39:29 by seokjyan     ###   ########.fr       */
/*                                        */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

#define st std::string
#define cout std::cout
#define cin std::cin
#define endl std::endl
#define getline std::getline

enum IType
{
    NEED = 0,
    NO_NEED = 1
};

class contacts
{
  private:
    st First_name;
    st Last_name;
    st Nick_name;
    st Phone_number;
    st Dsecret;

  public:
    contacts();
    ~contacts();
    st get_First_name();
    st get_Last_name();
    st get_Nick_name();
    st get_Phone_number();
    st get_Dsecret();

    void set_First_name(st Fame);
    void set_Last_name(st Same);
    void set_Nick_name(st Name);
    void set_Phone_number(st phone);
    void set_Dsecret(st secret);
};

bool validateInput(st msg, st *str = NULL, int type = NEED);

#endif