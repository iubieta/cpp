/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:11:34 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 17:03:15 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>
#include <ostream>
#include <string>

// Constructors ===============================================================

WrongAnimal::WrongAnimal() : 
	_type("unknown")
{
	std::cout << BLUE << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) :
	_type(type)
{
	std::cout << BLUE << "Type based constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BLUE << "Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << BLUE << "Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return(*this);
}

// Getters ====================================================================

std::string WrongAnimal::getType() const {
	return (this->_type);
}

// Member functions ===========================================================

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sounds!!"<< std::endl;
}
