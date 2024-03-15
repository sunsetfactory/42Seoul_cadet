/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:54:28 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/15 12:05:20 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <cstring>
# include <fstream>

class File
{
    private:
        std::ifstream ifs;
        std::ofstream ofs;
        std::string contents;
        std::string outfile;
        std::string s1;
        std::string s2;
        int s1_len;
        int s2_len;
    
    public:
        File();
        ~File();
        std::ifstream& getIfs();
        std::ofstream& getOfs();
        std::string getContents();
        std::string getOutfile();
        void    setS1(std::string s1);
        void    setS2(std::string s2);
        void    setS1Len(int s1_len);
        void    setS2Len(int s2_len);
        void	replace(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2);
};

#endif