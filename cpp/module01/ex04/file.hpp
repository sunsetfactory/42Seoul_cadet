/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:51 by seokjyan          #+#    #+#             */
/*   Updated: 2024/04/05 17:42:00 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
#define FILE_HPP

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

class File
{
  private:
    std::ifstream ifs;
    std::ofstream ofs;
    std::string outfile;
    std::string contents;

  public:
    File(std::string filename);
    ~File();
    void setifs(std::string filename);
    void setofs(std::string filename);
    void setOutfile(std::string filename);
    void replace(std::string s1, std::string s2);
};

#endif
