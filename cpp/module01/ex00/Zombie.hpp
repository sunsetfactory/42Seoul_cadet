/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:26:10 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 15:48:54 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
  private:
    std::string name;

  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
