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

#include "FragTrap.h"
#include <iostream>
#include <ostream>

int main() {
	
	std::cout << "========== Default Constructor ==========" << std::endl;
	
	FragTrap frag;
	frag.status();
	std::cout << std::endl;
	
	std::cout << "========== Named Constructor ==========" << std::endl;
	FragTrap myfrag("myFrag");
	myfrag.status();
	myfrag.attack("enemie");
	std::cout << std::endl;
	
	std::cout << "========== Copy Constructor ==========" << std::endl;
	FragTrap myfrag_copy(myfrag);
	myfrag_copy.status();
	std::cout << std::endl;

	std::cout << "========== Energy Test ==========" << std::endl;
	int i = 0;
	while (i < 100) {
		std::cout << ++i << "  ";
		frag.attack("enemie");
	}
	frag.status();
	frag.attack("enemie");
	frag.beReapaired(5);
	std::cout << std::endl;

	std::cout << "========== Damage Test ==========" << std::endl;
	myfrag.takeDamage(10);
	myfrag.takeDamage(10);
	myfrag.status();
	std::cout << std::endl;

	std::cout << "========== Repair Test ==========" << std::endl;
	myfrag.beReapaired(10);
	myfrag.status();
	std::cout << std::endl;
	
	std::cout << "========== Personal Test ==========" << std::endl;
	myfrag.highFivesGuys();
	std::cout << std::endl;
	
	
}
