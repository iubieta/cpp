/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:29:14 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/10 19:13:56 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>
#include <string>

// Constructors ===============================================================

ScavTrap::ScavTrap() : ClapTrap("Scav", 100, 50, 20) {
	std::cout << YELLOW << "Scav trap default constructor called" << RESET 
		<< std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20) {
	std::cout << YELLOW << "Scav trap name based constructor called" << RESET 
		<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	std::cout << YELLOW << "Scav trap copy constructor called" << RESET 
		<< std::endl;
	*this = other;
}

ScavTrap::~ScavTrap(){
	std::cout << YELLOW << "Scav trap destructor called" << RESET 
		<< std::endl;
}

// Operators ==================================================================
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << YELLOW << "Scav trap copy operator called" << RESET
		<< std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Getters ====================================================================

// Setters ====================================================================

// Member functions ===========================================================
void	ScavTrap::attack(std::string target) {
	if (_energyPts < 1) {
		std::cout << RED << "No energy points left" << RESET << std::endl;
		return;
	}
	std::cout << YELLOW << _name << " attacked " << target << ", causing "
		<< _attackDmg << " points of damage" << RESET << std::endl;
	--_energyPts;
}

void	ScavTrap::guardGate() const {
	std::cout << getName() << " is now gatekeeping" << std::endl;
}
