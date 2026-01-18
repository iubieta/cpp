/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:05:38 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/18 14:15:54 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

// Constructors ===============================================================

Intern::Intern() 
{
	std::cout << YELLOW << "Intern constructor called" << RESET << std::endl;
}


Intern::Intern(const Intern& other) 
{
	(void)other;
	std::cout << YELLOW << "Intern Copy constructor called" << RESET << std::endl;
}

Intern::~Intern() {
	std::cout << YELLOW << "Intern Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Intern& Intern::operator=(const Intern& other) {
	std::cout << YELLOW << "Intern Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
	}
	return(*this);
}

// Functions ==================================================================

int		Intern::_getFormType(const std::string name) const
{
	std::string types[3] = {
		"Shrubbery Creation"
		,"Robotomy Request"
		,"Presidential Pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (types[i] == name) {
			return (i+1);
		}		
	}
	throw Intern::UnknownFormType();
}

AForm*	Intern::makeForm(const std::string name, const std::string target) const
{
	AForm *form;

	try	{
		int type = this->_getFormType(name);
		switch (type) {
			case 1:
				form = new ShrubberyCreationForm(target);
				break;
			case 2:
				form = new RobotomyRequestForm(target);
				break;
			case 3:
				form = new PresidentialPardonForm(target);
				break;
		};
		return (form);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
		return (NULL);
	}
}

