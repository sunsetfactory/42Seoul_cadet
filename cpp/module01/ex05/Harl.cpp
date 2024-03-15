/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:07:21 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/15 20:35:06 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){ return; }
Harl::~Harl(){ return; }

void Harl::debug(void) { std::cout << "I hate it." << std::endl; }
void Harl::info(void) { std::cout << "I hate it so much." << std::endl; }
void Harl::warning(void) { std::cout << "I absolutely hate it." << std::endl; }
void Harl::error(void) { std::cout << "I really hate it." << std::endl; }

void Harl::complain( std::string level )
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level) 
		   	(this->*f[i])();
    }
    return;
}
