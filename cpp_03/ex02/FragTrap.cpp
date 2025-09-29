/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:29:14 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/28 14:42:17 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>
#include <string>

// Constructors ===============================================================

FragTrap::FragTrap() : ClapTrap("Frag", 100, 100, 30) {
	std::cout << MAGENTA << "Frag trap default constructor called" << RESET 
		<< std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30) {
	std::cout << MAGENTA << "Frag trap name based constructor called" << RESET 
		<< std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	std::cout << MAGENTA << "Frag trap copy constructor called" << RESET 
		<< std::endl;
	*this = other;
}

FragTrap::~FragTrap(){
	std::cout << MAGENTA << "Frag trap destructor called" << RESET 
		<< std::endl;
}

// Operators ==================================================================

// Getters ====================================================================

// Setters ====================================================================

// Member functions ===========================================================

void	FragTrap::highFivesGuys() const {
	std::cout << getName() << ": Give me five!!" << std::endl;
}
