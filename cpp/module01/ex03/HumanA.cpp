/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:55:28 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 16:39:54 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << "HumanA " << _name << " is created" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << _name << " is destroyed" << std::endl;
}

void HumanA::attack()
{
    std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}

// void HumanA::setWeapon(Weapon &weapon)
// {
//     _weapon = weapon;
// }
