/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:44:30 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 14:47:26 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

// Constructors ===============================================================

Dog::Dog() : Animal("Dog")
{
	std::cout << YELLOW << "Dog constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << YELLOW << "Dog Copy constructor called" << RESET << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << YELLOW << "Dog Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Dog& Dog::operator=(const Dog& other) {
	std::cout << YELLOW << "Dog Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return(*this);
}

// Getters ====================================================================

// Member functions ===========================================================

void Dog::makeSound() const {
	std::cout << "Woof! Woof!"<< std::endl;
}
