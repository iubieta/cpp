/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:47 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/17 18:14:10 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "Intern.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>
#include <ostream>

int main() {
	std::cout << GREEN 
		<< "========== Construction Test ===================" 
		<< RESET << std::endl;
	Bureaucrat				gardener("Gardener", 100);
	Bureaucrat				engineer("Engineer", 70);
	Bureaucrat				doc("Doctor", 40);
	Bureaucrat				major("Major", 5);
	Intern					intern;
	
	AForm *bushForm = intern.makeForm("Shrubbery Creation", "Major's house");
	AForm *robotomy = intern.makeForm("Robotomy Request", "Major's house");
	AForm *pardon = intern.makeForm("Presidential Pardon", "Doctor");
	
	AForm *random = intern.makeForm("non existant form", "Doctor");
	(void)random;

	std::cout << std::endl;
	std::cout << GREEN 
		<< "========== Sign Test ==========================="
		<< RESET << std::endl;
	gardener.signForm(*bushForm);
	doc.signForm(*robotomy);
	engineer.signForm(*robotomy);
	major.signForm(*pardon);

	std::cout << std::endl;
	std::cout << GREEN 
		<< "========== Exec Test ==========================="
		<< RESET << std::endl;
	gardener.executeForm(*bushForm);
	engineer.executeForm(*robotomy);
	doc.executeForm(*robotomy);
	major.executeForm(*pardon);

	std::cout << std::endl;
	std::cout << GREEN 
		<< "========== Destruction Test ===================="
		<< RESET << std::endl;
}
