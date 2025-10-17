/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:33:40 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

// Constructors ===============================================================

Cat::Cat()
{
	std::cout << YELLOW << "Cat constructor called" << RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << YELLOW << "Cat Copy constructor called" << RESET << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << YELLOW << "Cat Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Cat& Cat::operator=(const Cat& other) {
	std::cout << YELLOW << "Cat Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return(*this);
}

// Getters ====================================================================

// Member functions ===========================================================

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
