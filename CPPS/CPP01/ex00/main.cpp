/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:29:43 by mtahalla          #+#    #+#             */
/*   Updated: 2025/08/19 15:29:43 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombie = newZombie("Samir");
	Zombie* zombie1 = newZombie("Ahmed");
	Zombie* zombie2 = newZombie("Mouad");

	zombie->announce();
	zombie1->announce();
	zombie2->announce();

	randomChump("Tahalla");
	randomChump("Karim");
	randomChump("Hid");
	randomChump("Fellah");

	delete zombie;
	delete zombie1;
	delete zombie2;

	return 0;
}
