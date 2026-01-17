/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:33:29 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/17 18:09:30 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"
#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

// Constructors ===============================================================

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("robotomy request form", 72, 45, 0)
	, _target("target")
{
	std::cout << BLUE 
		<< "RobotomyRequestForm default constructor called" 
		<< RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("robotomy request form", 72, 45, 0)
	, _target(target)
{
	std::cout << BLUE 
		<< "RobotomyRequestForm constructor called" 
		<< RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
	, _target(other.getTarget())
{
	std::cout << BLUE 
		<< "RobotomyRequestForm Copy constructor called" 
		<< RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BLUE 
		<< "RobotomyRequestForm Destructor called" 
		<< RESET<< std::endl;
}

// Operators ==================================================================

RobotomyRequestForm& 
	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << BLUE 
		<< "RobotomyRequestForm Copy operator called" 
		<< RESET << std::endl;
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return(*this);
}

// Getters ====================================================================

std::string RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

// Private functions ===========================================================

void	RobotomyRequestForm::doAction() const
{
	std::cout 
		<< this->_target << " has been robotomized" << std::endl;
}

void RobotomyRequestForm::print(std::ostream& out) const
{
	AForm::print(out);
	out	<< ", target: " << this->_target;
}
