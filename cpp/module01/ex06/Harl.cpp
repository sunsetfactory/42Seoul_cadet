/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:07:21 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/15 20:38:22 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    INVALID
};


Harl::Harl(){ return; }
Harl::~Harl(){ return; }

void Harl::debug(void) { std::cout << "I hate it." << std::endl; }
void Harl::info(void) { std::cout << "I hate it so much." << std::endl; }
void Harl::warning(void) { std::cout << "I absolutely hate it." << std::endl; }
void Harl::error(void) { std::cout << "I really hate it." << std::endl; }

void Harl::complain( std::string level )
{
    Level logLevel;
    if (level == "debug")
        logLevel = DEBUG;
    else if (level == "info")
        logLevel = INFO;
    else if (level == "warning")
        logLevel = WARNING;
    else if (level == "error")
        logLevel = ERROR;
    else
        logLevel = INVALID;
    switch (logLevel)
    {
        case DEBUG:
            debug();
            break;
        case INFO:
            info();
            break;
        case WARNING:
            warning();
            break;
        case ERROR:
            error();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
            break;
    }
    return;
}