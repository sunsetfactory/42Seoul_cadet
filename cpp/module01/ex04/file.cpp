/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:56:10 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/15 12:05:46 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.hpp"

File::File()
{
    std::string outfile;
    std::string s1;
    std::string s2;
}

File::~File()
{
    ifs.close();
    ofs.close();
}

std::ifstream& File::getIfs()
{
    return ifs;
}

std::ofstream& File::getOfs()
{
    return ofs;
}

std::string File::getContents()
{
    return (contents);
}

std::string File::getOutfile()
{
    return (outfile);
}

void    File::setS1(std::string s1)
{
    this->s1 = s1;
}

void    File::setS2(std::string s2)
{
    this->s2 = s2;
}

void    File::setS1Len(int s1_len)
{
    this->s1_len = s1_len;
}

void    File::setS2Len(int s2_len)
{
    this->s2_len = s2_len;
}

void	File::replace(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
    while (true)
    {
        std::getline(ifs, contents);
        
        size_t pos = 0;
        while (true)
        {
            pos = contents.find(s1, pos);
            if (pos == std::string::npos)
            {
                break ;
            }
            contents.erase(pos, s1_len);
            contents.insert(pos, s2);
            // contents.replace(pos, s1_len, s2);
            pos += s2_len;
        }
        ofs << contents;
        if (ifs.eof())
            break ;
    }
    ifs.close();
    ofs.close();
}
