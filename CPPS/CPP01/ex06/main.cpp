/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:32:42 by mtahalla          #+#    #+#             */
/*   Updated: 2025/08/19 15:32:42 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int getLevelIndex(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == levels[i])
			return i;
	}
	return -1;
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}

	Harl harl;
	int levelIndex = getLevelIndex(argv[1]);

	switch (levelIndex) {
		case 0:
			harl.complain("DEBUG");
            
		case 1:
			harl.complain("INFO");
            
		case 2:
			harl.complain("WARNING");
            
		case 3:
			harl.complain("ERROR");
            break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return 0;
}
