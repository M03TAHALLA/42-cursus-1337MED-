/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:41:14 by mtahalla          #+#    #+#             */
/*   Updated: 2025/08/22 16:49:22 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string& line, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return line;

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        result.append(line, pos, found - pos);
        result.append(s2);                  
        pos = found + s1.length();
    }
    result.append(line, pos); 
    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "Error: cannot open file '" << filename << "'." << std::endl;
        return 1;
    }

    std::ofstream outfile((filename + ".replace"));
    if (!outfile)
    {
        std::cerr << "Error: cannot create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        outfile << replaceAll(line, s1, s2) << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
