/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/28 13:11:29 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>
#include <ostream>

int main() {
	
	std::cout << "========== Part 1 ==========" << std::endl;

	ClapTrap ct;

	ct.status();
	ct.attack("enemy 1");
	ct.status();
	ct.attack("enemy 1");
	ct.status();
	ct.takeDamage(2);
	ct.status();
	ct.takeDamage(2);
	ct.status();
	ct.beReapaired(3);
	ct.status();
	ct.attack("enemy 1");
	ct.attack("enemy 1");
	ct.attack("enemy 1");
	ct.attack("enemy 1");
	ct.attack("enemy 1");
	ct.attack("enemy 1");
	ct.attack("enemy 1");
	ct.status();
	ct.attack("enemy 1");
	ct.status();
	ct.beReapaired(3);
	ct.status();
	
	std::cout << "========== Part 2 ==========" << std::endl;
	
	ClapTrap ct_2("myClapTrap");

	ct_2.status();
	ct_2.attack("enemy 1");
	ct_2.status();
	ct_2.takeDamage(2);
	ct_2.status();
	ct_2.beReapaired(3);
	ct_2.status();
}
