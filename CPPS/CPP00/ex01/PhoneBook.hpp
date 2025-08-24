/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:49:51 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/31 20:54:13 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H
	#include "Contact.hpp"
	#include <iostream>
	#include <string>
	#include <iomanip>
	class PhoneBook
	{
		private :
			Contact contact[8];
			int index;
			int totalContact;
		public:
			PhoneBook();
			~PhoneBook();

			void add_contact();
			void search_contact();
			void display_all_contact();

		private:
			std::string get_input(const std::string &prompt)const;
			bool is_valid_index(std::string &input , int &index);
	};
#endif