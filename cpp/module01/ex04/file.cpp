/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:54 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 17:48:21 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string filename)
{
    setifs(filename);
    setOutfile(filename);
    setofs(outfile);
}
File::~File()
{
}

void File::setifs(std::string filename)
{
    ifs.open(filename.c_str());
    if (ifs.fail())
    {
        std::cout << "sorry, can't open " << filename << std::endl;
        exit(1);
    }
}

void File::setofs(std::string filename)
{
    ofs.open(filename.c_str());
    if (ofs.fail())
    {
        std::cout << "sorry, can't open " << filename << std::endl;
        exit(1);
    }
}

void File::setOutfile(std::string filename)
{
    outfile = filename;
    outfile.append(".replace");
}

void File::replace(std::string s1, std::string s2)
{
    std::string line;
    size_t pos;

    while (std::getline(ifs, line))
    {
        while ((pos = line.find(s1)) != std::string::npos)
            line.replace(pos, s1.length(), s2);
        ofs << line << std::endl;
    }
}
