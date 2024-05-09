/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:23:54 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 15:49:09 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie is born" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " : is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
