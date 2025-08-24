/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:31:17 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/31 13:51:48 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}
	
Contact::~Contact()
{
}

void Contact::set_first_name(const std::string &first_n)
{
	first_name = first_n;
}

void Contact::set_last_name(const std::string &last_n)
{
	last_name = last_n;
}

void Contact::set_nickname(const std::string &nick_n)
{
	nickname = nick_n;
}

void Contact::set_phone_number(const std::string &phone)
{
	phone_number = phone;
}

void Contact::set_darkest_secret(const std::string &secret)
{
	darkest_secret = secret;
}

std::string Contact::get_first_name()const
{
	return first_name;
}

std::string Contact::get_last_name()const
{
	return last_name;
}

std::string Contact::get_nickname()const
{
	return nickname;
}

std::string Contact::get_phone_number()const
{
	return phone_number;
}

std::string Contact::get_darkest_secret()const
{
	return darkest_secret;
}

void Contact::display_contact()const
{
	std::cout << "First Name : " << get_first_name() << std::endl;
	std::cout << "Last Name : " << get_last_name() << std::endl;
	std::cout << "Nick Name : " << get_nickname() << std::endl;
	std::cout << "Phone Number : " << get_phone_number() << std::endl;
	std::cout << "Darkest Secret : " << get_darkest_secret() << std::endl;
}

static std::string truncate_string(std::string &str)
{
	if(str.length() > 10)
	{
		return str.substr(0,9) + ".";
	}
	return str;
}

bool Contact::isEmpty()const
{
	return (first_name.empty() && last_name.empty() && nickname.empty() && phone_number.empty() && darkest_secret.empty());
}

void Contact::display_contact_line(int index)
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << truncate_string(first_name);
	std::cout << "|" << std::setw(10) << truncate_string(last_name);
	std::cout << "|" << std::setw(10) << truncate_string(nickname);
	std::cout << "|" << std::endl;
}