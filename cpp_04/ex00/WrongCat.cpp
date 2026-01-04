/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:37:29 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

// Constructors ===============================================================

WrongCat::WrongCat()
{
	std::cout << YELLOW << "WrongCat constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) 
{
	std::cout << YELLOW << "WrongCat Copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongCat::~WrongCat() 
{
	std::cout << YELLOW << "WrongCat Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << YELLOW << "WrongCat Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return(*this);
}

// Getters ====================================================================

// Member functions ===========================================================

void WrongCat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
