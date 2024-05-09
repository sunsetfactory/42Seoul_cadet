/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:00:44 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 16:39:52 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() : _name("default")
{
    std::cout << "HumanB " << _name << " is created" << std::endl;
}

HumanB::HumanB(std::string name) : _name(name)
{
    std::cout << "HumanB " << _name << " is created" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB " << _name << " is destroyed" << std::endl;
}

void HumanB::attack()
{
    if (_weapon == NULL)
    {
        std::cout << _name << " has no weapon" << std::endl;
        return;
    }
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
