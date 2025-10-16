/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:56:29 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/10 18:14:55 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"

// Constructors ===============================================================

Brain::Brain()
{
	std::cout << MAGENTA << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << MAGENTA << "Brain Copy constructor called" << RESET << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << MAGENTA << "Brain Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Brain& Brain::operator=(const Brain& other) {
	std::cout << MAGENTA << "Brain Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return(*this);
}

// Setters ====================================================================

void Brain::setIdea(int i, std::string idea)
{
	this->_ideas[i] = idea;
}

// Getters ====================================================================

std::string Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}

// Member functions ===========================================================