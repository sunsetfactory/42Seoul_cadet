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

PhoneBook::PhoneBook()
{
}
PhoneBook::~PhoneBook()
{
}

contacts PhoneBook::get_contact(int i)
{
    return (contact[i]);
}

void PhoneBook::contact_setf(st fn, int i)
{
    contact[i].set_First_name(fn);
}

void PhoneBook::contact_setl(st ln, int i)
{
    contact[i].set_Last_name(ln);
}

void PhoneBook::contact_setn(st nn, int i)
{
    contact[i].set_Nick_name(nn);
}

void PhoneBook::contact_setp(st pn, int i)
{
    contact[i].set_Phone_number(pn);
}

void PhoneBook::contact_setd(st ds, int i)
{
    contact[i].set_Dsecret(ds);
}
void header()
{
    cout << "\033[1;31m"
            "   ___    _ "
            "\033[1;33m"
            "__   _    "
            "\033[1;32m"
            "_  __   _"
            "\033[1;34m"
            "__  "
            "\033[1;36m"
            "   ___    _ "
            "\033[1;35m"
            "   _    _   "
         << endl;
    cout << "\033[1;31m"
            "  / o |  ///"
            "\033[1;33m"
            " / ,' \\  "
            "\033[1;32m"
            "/ |/ /  /"
            "\033[1;34m"
            " _/ "
            "\033[1;36m"
            "   / o.) ,' "
            "\033[1;35m"
            "\\ ,' \\  / //7"
         << endl;
    cout << "\033[1;31m"
            " / _,'  / ` "
            "\033[1;33m"
            "/ / o | / "
            "\033[1;32m"
            "|| /  / _"
            "\033[1;34m"
            "/   "
            "\033[1;36m"
            " / o \\ / o "
            "\033[1;35m"
            "|/ o | /  ,' "
         << endl;
    cout << "\033[1;31m"
            "/_/    /_n_/"
            "\033[1;33m"
            "  |_,' /_/"
            "\033[1;32m"
            "|_/  /___"
            "\033[1;34m"
            "/   "
            "\033[1;36m"
            "/___,' |_,' "
            "\033[1;35m"
            "|_,' /_/\\  "
         << endl;
    cout << "\033[0m"; // Reset color
}

int add_contact(PhoneBook *div, int i)
{
    st fn, ln, nn, pn, ds;
    system("clear");
    header();
    if (validateInput("Enter first name: ", &fn) == false)
        return (i);
    if (validateInput("Enter last name: ", &ln) == false)
        return (i);
    if (validateInput("Enter nick name: ", &nn) == false)
        return (i);
    if (validateInput("Enter phone number: ", &pn) == false)
        return (i);
    if (validateInput("Enter darkest secret: ", &ds) == false)
        return (i);
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

void search_contact(PhoneBook *div)
{
    cout << "|     Index|First Name| Last Name|  Nickname|" << endl;
    for (int i = 0; i < 8; i++)
    {
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
    if (validateInput("Enter the index number 1 ~ 8: ", &index) == false)
        return;
    std::stringstream id(index);
    int idx;
    id >> idx;
    idx -= 1;
    if (idx >= 0 && idx < 8)
    {
        system("clear");
        header();
        cout << "First Name";
        cout.width(10);
        cout << " : " << div->get_contact(idx).get_First_name() << endl;
        cout << "Last Name";
        cout.width(11);
        cout << " : " << div->get_contact(idx).get_Last_name() << endl;
        cout << "Nick name";
        cout.width(11);
        cout << " : " << div->get_contact(idx).get_Nick_name() << endl;
        cout << "Phone Number";
        cout.width(8);
        cout << " : " << div->get_contact(idx).get_Phone_number() << endl;
        cout << "Darkest Secret";
        cout.width(6);
        cout << " : " << div->get_contact(idx).get_Dsecret() << endl;
    }
    else
    {
        cout << "Invalid index!" << endl;
    }
    while (1)
    {
        st cmd;
        if (validateInput("\n\033[1mPRESS ENTER TO CONTINUE...\033[0m", &cmd, NO_NEED) == false)
            return;
        if (cmd.empty())
            break;
    }
}
