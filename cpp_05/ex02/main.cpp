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
	
	ShrubberyCreationForm	bushForm("Major's house");
	RobotomyRequestForm		robotomy("Gardener");
	PresidentialPardonForm	pardon("Doctor");

	RobotomyRequestForm		robotomy2;
	robotomy2 = robotomy;
	std::cout << robotomy2;


	std::cout << std::endl;
	std::cout << GREEN 
		<< "========== Sign Test ==========================="
		<< RESET << std::endl;
	gardener.signForm(bushForm);
	engineer.signForm(robotomy);
	major.signForm(pardon);



	std::cout << std::endl;
	std::cout << GREEN 
		<< "========== Exec Test ==========================="
		<< RESET << std::endl;
	gardener.executeForm(bushForm);
	engineer.executeForm(robotomy);
	doc.executeForm(robotomy);
	major.executeForm(pardon);



	std::cout << std::endl;
	std::cout << GREEN 
		<< "========== Destruction Test ===================="
		<< RESET << std::endl;
}
