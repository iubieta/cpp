/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:44:30 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:41:27 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

// Constructors ===============================================================

Dog::Dog()
{
	std::cout << YELLOW << "Dog constructor called" << RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << YELLOW << "Dog Copy constructor called" << RESET << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << YELLOW << "Dog Destructor called" << RESET<< std::endl;
	delete this->_brain;
}

// Operators ==================================================================

Dog& Dog::operator=(const Dog& other) {
	std::cout << YELLOW << "Dog Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return(*this);
}

// Setters ====================================================================
void Dog::setIdea(int i, const std::string idea)
{
	this->_brain->setIdea(i,idea);
}

// Getters ====================================================================
std::string Dog::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}

// Member functions ===========================================================

void Dog::makeSound() const {
	std::cout << "Woof! Woof!"<< std::endl;
}
