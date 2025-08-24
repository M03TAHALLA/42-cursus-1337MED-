/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:31:50 by mtahalla          #+#    #+#             */
/*   Updated: 2025/08/19 15:31:50 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type)
{
	this->type = type;
}


Weapon::~Weapon()
{
}

std::string Weapon::getType()const
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}