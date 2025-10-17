/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:11:34 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:13:13 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>
#include <ostream>
#include <string>

// Constructors ===============================================================

Animal::Animal() : 
	_type("unknown")
{
	std::cout << BLUE << "Animal constructor called" << RESET << std::endl;
}

//Animal::Animal(const std::string& type) :
//	_type(type)
//{
//	std::cout << BLUE << "Type based constructor called" << RESET << std::endl;
//}

Animal::Animal(const Animal& other) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << BLUE << "Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Animal& Animal::operator=(const Animal& other) {
	std::cout << BLUE << "Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return(*this);
}

// Getters ====================================================================

std::string Animal::getType() const {
	return (this->_type);
}

// Member functions ===========================================================

void Animal::makeSound() const {
	std::cout << "Animal sounds!!"<< std::endl;
}
