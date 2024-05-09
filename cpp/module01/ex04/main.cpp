/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:12:22 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/15 17:00:54 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Args.hpp"
#include "File.hpp"

int main(int ac, char *av[])
{
    Args args(ac, av);
    File file(args.getFilename());
    file.replace(args.getS1(), args.getS2());
}
