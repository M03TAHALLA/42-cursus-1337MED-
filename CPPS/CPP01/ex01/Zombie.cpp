/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:30:28 by mtahalla          #+#    #+#             */
/*   Updated: 2025/08/19 15:30:28 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(const std::string& name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << ": Mssaaa7ni" << std::endl;
}

void Zombie::setname(const std::string& name)
{
	this->name = name;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
