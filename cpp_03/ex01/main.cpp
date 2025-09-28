/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/28 14:20:43 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>
#include <ostream>

int main() {
	
	std::cout << "========== Default Constructor ==========" << std::endl;
	
	ScavTrap scav;
	scav.status();
	std::cout << std::endl;
	
	std::cout << "========== Named Constructor ==========" << std::endl;
	ScavTrap myscav("myScav");
	myscav.status();
	myscav.attack("enemie");
	std::cout << std::endl;
	
	std::cout << "========== Copy Constructor ==========" << std::endl;
	ScavTrap myscav_copy(myscav);
	myscav_copy.status();
	std::cout << std::endl;

	std::cout << "========== Energy Test ==========" << std::endl;
	int i = 0;
	while (i < 50) {
		std::cout << ++i << "  ";
		scav.attack("enemie");
	}
	scav.status();
	scav.attack("enemie");
	scav.beReapaired(5);
	std::cout << std::endl;

	std::cout << "========== Damage Test ==========" << std::endl;
	myscav.takeDamage(10);
	myscav.takeDamage(10);
	myscav.status();
	std::cout << std::endl;

	std::cout << "========== Repair Test ==========" << std::endl;
	myscav.beReapaired(10);
	myscav.status();
	std::cout << std::endl;
	
	// std::cout << "========== Part 2 ==========" << std::endl;
	
}
