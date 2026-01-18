/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:31:04 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/17 18:11:37 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"
#include "AForm.h"
#include "Bureaucrat.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

// Constructors ===============================================================

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("shrubbery creation form", 145, 137, 0)
	, _target("target")
{
	std::cout << BLUE 
		<< "ShrubberyCreationForm default constructor called" 
		<< RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("shrubbery creation form", 145, 137, 0)
	, _target(target)
{
	std::cout << BLUE 
		<< "ShrubberyCreationForm constructor called" 
		<< RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
	, _target(other.getTarget())
{
	std::cout << BLUE 
		<< "ShrubberyCreationForm Copy constructor called" 
		<< RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BLUE 
		<< "ShrubberyCreationForm Destructor called" 
		<< RESET<< std::endl;
}

// Operators ==================================================================

ShrubberyCreationForm& 
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << BLUE 
		<< "ShrubberyCreationForm Copy operator called" 
		<< RESET << std::endl;
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other.getTarget();
	}
	return(*this);
}


// Getters ====================================================================

std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

// Private functions ===========================================================

void ShrubberyCreationForm::print(std::ostream& out) const
{
	AForm::print(out);
	out	<< ", target: " << this->_target;
}

void	ShrubberyCreationForm::doAction() const
{
	std::ifstream	ascii_tree("ascii_tree.txt");
	std::ofstream	target_file;
	target_file.open((this->_target + ".txt").c_str(), std::ofstream::app);
	std::string		line;

	while (std::getline(ascii_tree, line)) {
		target_file << line << std::endl;
	}
	ascii_tree.close();
	target_file.close();
	std::cout 
		<< "A shrubbery has been created in " << this->_target << std::endl;
	return;
}

