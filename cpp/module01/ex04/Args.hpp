/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Args.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:56 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 16:39:45 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_HPP
#define ARGS_HPP

#include <cstdlib>
#include <cstring>
#include <iostream>

class Args
{
  private:
    std::string filename;
    std::string s1;
    std::string s2;

  public:
    Args(int ac, char *av[]);
    ~Args();
    std::string getFilename();
    std::string getS1();
    std::string getS2();
    bool ValidateArgs(char *av[]);
};

#endif