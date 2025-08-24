/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:49:24 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/31 13:50:26 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

std::string trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if(start == std::string::npos || end == std::string::npos)
        return "";
    return (str.substr(start, end - start + 1));
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to your Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true) {
        std::cout << std::endl << "Enter a command: ";
        
        if (!std::getline(std::cin, command)) {
            std::cout << std::endl << "Goodbye!" << std::endl;
            break;
        }
        
        command = trim(command);
        
        if (command == "ADD") {
            phoneBook.add_contact();
        }
        else if (command == "SEARCH") {
            phoneBook.search_contact();
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (!command.empty()) {
            std::cout << "\033[31mInvalid command. Available commands: ADD, SEARCH, EXIT\033[0m" << std::endl;
        }
    }
    
    return 0;
}