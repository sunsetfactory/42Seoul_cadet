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

#include <iostream>
#include <string>
#include <sstream>
#define st std::string
#define cout std::cout
#define cin std::cin
#define endl std::endl
#define getline std::getline

enum vType {
    FN = 0,
    LN,
    NN,
    PN,
    DS,
    INDEX
};

class contacts {
	private :
    st First_name;
    st Last_name;
    st Nick_name;
    st Phone_number;
    st Dsecret;

	public :
    contacts();
    ~contacts();
    st	get_First_name();
    st	get_Last_name();
    st	get_Nick_name();
    st	get_Phone_number();
    st	get_Dsecret();

    void	set_First_name(st Fame);
    void	set_Last_name(st Same);
    void	set_Nick_name(st Name);
    void	set_Phone_number(st phone);
    void	set_Dsecret(st secret);
};

// void	validateInput(st msg, st *str, int type);
void	validateInput(st msg, st *str);

#endif