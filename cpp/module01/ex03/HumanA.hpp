/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:37:24 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 16:21:09 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
  private:
    std::string _name;
    Weapon &_weapon;

  public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack();
    // void setWeapon(Weapon &weapon);
};

#endif