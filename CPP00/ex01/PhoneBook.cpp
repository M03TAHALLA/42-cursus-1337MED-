/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:49:39 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/31 13:54:57 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	totalContact = 0;
}

PhoneBook::~PhoneBook()
{

}

std::string PhoneBook::get_input(const std::string &prompt)const
{
	std::string input;
	while(true)
	{
		std::cout << prompt;
		if(!getline(std::cin,input))
		{
			std::cout << std::endl;
			exit(0);
		}
		size_t start = input.find_first_not_of(" \t\n\r");
		if(start == std::string::npos)
		{
			std::cout << "\033[31mInvalid Empty Field , try again !\033[0m" << std::endl;
			continue;
		}
		size_t end = input.find_last_not_of(" \t\n\r");
		input = input.substr(start,end - start + 1);
		if(!input.empty())
		{
			break;
		}
		std::cout << "\033[31mInvalid Empty Field , try again !\033[0m" << std::endl;
	}
	return input;
}

void PhoneBook::add_contact()
{
	Contact newcontact;

	std::cout << "Add new Contact : " << std::endl;
	newcontact.set_first_name(get_input("First Name : "));
	newcontact.set_last_name(get_input("Last Name : "));
	newcontact.set_nickname(get_input("Nick Name : "));
	newcontact.set_phone_number(get_input("Phone Number : "));
	newcontact.set_darkest_secret(get_input("Darkest Secret : "));

	contact[index] = newcontact;
	index = (index + 1) % 8;

	if (totalContact < 8)
	{
		totalContact++;
	}

	std::cout << "\033[32mContact Added with Success\033[0m" << std::endl;
}

void PhoneBook::display_all_contact()
{
	if (totalContact == 0)
	{
		std::cout << "\033[31mNon Contact Available !\033[0m" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10)
			  << "First Name" << "|" << std::setw(10)
			  << "Last Name" << "|" << std::setw(10)
			  << "Nick Name" << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < totalContact; i++)
	{
		contact[i].display_contact_line(i + 1);
	}
	std::cout << std::endl;
}

bool PhoneBook::is_valid_index(std::string &input, int &index)
{
	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		return false;
	}

	index = input[0] - '0' - 1;
	return (index >= 0 && index < totalContact);
}

void PhoneBook::search_contact()
{
	if (totalContact == 0)
	{
		std::cout << "\033[31mNon Contact Available !\033[0m" << std::endl;
		return;
	}

	display_all_contact();

	std::string input;
	int index;

	while (true)
	{
		std::cout << "Enter the index of the contact to display: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return;
		}

		if (is_valid_index(input, index))
		{
			std::cout << std::endl;
			contact[index].display_contact();
			std::cout << std::endl;
			break;
		}
		else
		{
			std::cout << "\033[31mInvalid index. Please enter a valid index (1-"
					  << totalContact << ").\033[0m" << std::endl;
		}
	}
}