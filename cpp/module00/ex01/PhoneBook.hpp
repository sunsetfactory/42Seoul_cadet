/* ************************************************************************** */
/*                                        */
/*                            :::      ::::::::   */
/*   PhoneBook.hpp                      :+:      :+:    :+:   */
/*                            +:+ +:+     +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+       */
/*   Created: 2024/03/07 20:02:37 by seokjyan      #+#    #+#         */
/*   Updated: 2024/03/11 10:56:40 by seokjyan     ###   ########.fr       */
/*                                        */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP

#include "contacts.hpp"

class PhoneBook {
	private : 
    contacts contact[8];

	public : 
    PhoneBook();
    ~PhoneBook();
    contacts	get_contact(int i);
    void    contact_setf(st fn, int i);
    void    contact_setl(st ln, int i);
    void    contact_setn(st nn, int i);
    void    contact_setp(st pn, int i);
    void    contact_setd(st ds, int i);
};

int 	add_contact(PhoneBook *div, int i);
void	search_contact(PhoneBook *div);

#endif
