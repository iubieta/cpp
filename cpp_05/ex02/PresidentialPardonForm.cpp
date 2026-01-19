/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/19 18:28:46 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"
#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

// Constructors ===============================================================

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", 25, 5, 0)
	, _target("target")
{
	std::cout << BLUE 
		<< "PresidentialPardonForm default constructor called" 
		<< RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("Presidential Pardon Form", 25, 5, 0)
	, _target(target)
{
	std::cout << BLUE 
		<< "PresidentialPardonForm constructor called" 
		<< RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
	, _target(other.getTarget())
{
	std::cout << BLUE 
		<< "PresidentialPardonForm Copy constructor called" 
		<< RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BLUE 
		<< "PresidentialPardonForm Destructor called" 
		<< RESET<< std::endl;
}

// Operators ==================================================================

PresidentialPardonForm& 
	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << BLUE 
		<< "PresidentialPardonForm Copy operator called" 
		<< RESET << std::endl;
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return(*this);
}


// Getters ====================================================================

std::string PresidentialPardonForm::getTarget() const {
	return (this->_target);
}

// Private functions ===========================================================

void	PresidentialPardonForm::_doAction() const
{
	std::cout 
		<< this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::print(std::ostream& out) const
{
	AForm::print(out);
	out	<< ", target: " << this->_target;
}
