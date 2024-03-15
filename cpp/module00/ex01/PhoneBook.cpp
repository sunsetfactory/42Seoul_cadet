/* ************************************************************************** */
/*                                        */
/*                            :::      ::::::::   */
/*   PhoneBook.cpp                      :+:      :+:    :+:   */
/*                            +:+ +:+     +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>      +#+  +:+       +#+    */
/*                        +#+#+#+#+#+   +#+       */
/*   Created: 2024/03/06 21:48:04 by seokjyan      #+#    #+#         */
/*   Updated: 2024/03/11 13:50:30 by seokjyan     ###   ########.fr       */
/*                                        */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

contacts	PhoneBook::get_contact(int i) {
    return (contact[i]);
}

void    PhoneBook::contact_setf(st fn, int i) {
    contact[i].set_First_name(fn);
}

void    PhoneBook::contact_setl(st ln, int i) {
    contact[i].set_Last_name(ln);
}
    
void    PhoneBook::contact_setn(st nn, int i) {
    contact[i].set_Nick_name(nn);
}

void    PhoneBook::contact_setp(st pn, int i) {
    contact[i].set_Phone_number(pn);
}

void    PhoneBook::contact_setd(st ds, int i) {
    contact[i].set_Dsecret(ds);
}

int add_contact(PhoneBook *div, int i) {
    st fn, ln, nn, pn, ds;

    // validateInput("Enter first name: ", &fn, FN);
    // validateInput("Enter last name: ", &ln, LN);
    // validateInput("Enter nick name: ", &nn, NN);
    // validateInput("Enter phone number: ", &pn, PN);
    // validateInput("Enter darkest secret: ", &ds, DS);
    validateInput("Enter first name: ", &fn);
    validateInput("Enter last name: ", &ln);
    validateInput("Enter nick name: ", &nn);
    validateInput("Enter phone number: ", &pn);
    validateInput("Enter darkest secret: ", &ds);
    div->contact_setf(fn, i);
    div->contact_setl(ln, i);
    div->contact_setn(nn, i);
    div->contact_setp(pn, i);
    div->contact_setd(ds, i);
    if (i >= 7)
        i = 0;
    else
        i++;
    return (i);
}

void search_contact(PhoneBook *div) {
    cout << "|     Index|First Name| Last Name|  Nickname|" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "|";
        cout.width(10);
        cout << i + 1 << "|";
        cout.width(10);
        cout << div->get_contact(i).get_First_name().substr(0, 10) << "|";
        cout.width(10);
        cout << div->get_contact(i).get_Last_name().substr(0, 10) << "|";
        cout.width(10);
        cout << div->get_contact(i).get_Nick_name().substr(0, 10) << "|" << endl;
    }

    std::string index;
    // validateInput("Enter the index of the contact you want to see: ", &index, INDEX);
    validateInput("Enter the index of the contact you want to see: ", &index);
    std::stringstream id(index);
    int idx;
    id >> idx;
    if (idx == 0) {
        cout << "Invalid index!" << endl;
        return;
    }
    idx -= 1;
    if (idx >= 0 && idx < 8) {
        cout << "First Name: " << div->get_contact(idx).get_First_name() << endl;
        cout << "Last Name: " << div->get_contact(idx).get_Last_name() << endl;
        cout << "Nick name: " << div->get_contact(idx).get_Nick_name() << endl;
        cout << "Phone Number: " << div->get_contact(idx).get_Phone_number() << endl;
        cout << "Darkest Secret: " << div->get_contact(idx).get_Dsecret() << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}
