/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/13 19:36:23 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"

// Constructors ===============================================================

Cat::Cat() : Animal("Cat")
{
	std::cout << YELLOW << "Cat constructor called" << RESET << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << YELLOW << "Cat Copy constructor called" << RESET << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat() {
	std::cout << YELLOW << "Cat Destructor called" << RESET<< std::endl;
	delete this->_brain;
}

// Operators ==================================================================

Cat& Cat::operator=(const Cat& other) {
	std::cout << YELLOW << "Cat Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return(*this);
}

// Setters ====================================================================
void Cat::setIdea(int i, const std::string idea)
{
	this->_brain->setIdea(i,idea);
}

// Getters ====================================================================
std::string Cat::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}

// Member functions ===========================================================

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
