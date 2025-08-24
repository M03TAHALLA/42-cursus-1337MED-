/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:49:18 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/31 13:51:29 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

	#include <iostream>
	#include <string>
	#include <iomanip>
	class Contact
	{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();

	std::string get_first_name()const;
	std::string get_last_name()const;
	std::string get_nickname()const;
	std::string get_phone_number()const;
	std::string get_darkest_secret()const;

	void set_first_name(const std::string &first_name);
	void set_last_name(const std::string &last_name);
	void set_nickname(const std::string &nickname);
	void set_phone_number(const std::string &phone_number);
	void set_darkest_secret(const std::string &darkest_secret);


	void display_contact()const;
	void display_contact_line(int index);
	bool isEmpty()const;
	};
	
#endif