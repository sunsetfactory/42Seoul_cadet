/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:08:12 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/14 16:38:46 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << "Weapon " << _type << " is created" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon " << _type << " is destroyed" << std::endl;
}

std::string Weapon::getType()
{
    return _type;
}

void Weapon::setType(std::string type)
{
    _type = type;
}
