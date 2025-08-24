/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 07:25:03 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/31 16:11:54 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for(int i = 1; i < argc ; i++)
	{
		std::string str = argv[i];
		for(size_t j = 0; j < str.length(); j++)
		{
			std::cout << static_cast<char>(toupper(str[j]));
		}
	}
	std::cout << std::endl;
	return 0;
}