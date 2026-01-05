/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 18:10:25 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include <iostream>
#include <ostream>

int main() {
	
	std::cout << "========== Constructors Test ==========" << std::endl;
	std::cout << "Default:" << std::endl;
	Bureaucrat def;
	std::cout << def;
	std::cout << std::endl;

	std::cout << "Name = Top, grade = 1:" << std::endl;
	Bureaucrat g1("Top", 1);
	std::cout << g1;
	std::cout << std::endl;

	std::cout << "Name = Mid, grade = 100:" << std::endl;
	Bureaucrat g100("Mid", 100);
	std::cout << g100;
	std::cout << std::endl;

	std::cout << "Name = Low, grade = 150:" << std::endl;
	Bureaucrat g150("Low", 150);
	std::cout << g150;
	std::cout << std::endl;

	std::cout << "Copy:" << std::endl;
	Bureaucrat copy(def);
	std::cout << copy;
	std::cout << std::endl;

	std::cout << "Grade 0:" << std::endl;
	try {
		Bureaucrat g0("Too High", 0);
		std::cout << g0;
	}
	catch ( std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Grade 200:" << std::endl;
	try {
		Bureaucrat g200("Low", 200);
		std::cout << g200;
	}
	catch ( std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "========== Upgrading Test ==========" << std::endl;
	
	std::cout << "Top: ";
	g1.upgrade();
	std::cout << g1;
	
	std::cout << "Mid: ";
	g100.upgrade();
	std::cout << g100;
	
	std::cout << "Low: ";
	g150.upgrade();
	std::cout << g150;
	
	std::cout << std::endl;
	std::cout << "========== Downgrading Test ==========" << std::endl;
	
	std::cout << "Top: ";
	g1.downgrade();
	std::cout << g1;

	std::cout << "Mid: ";
	g100.downgrade();
	std::cout << g100;

	std::cout << "Low (reset): ";
	g150.downgrade();
	std::cout << g150;

	std::cout << "Low: ";
	g150.downgrade();
	std::cout << g150;

	std::cout << std::endl;
	std::cout << "========== Destruction Test ==========" << std::endl;
}
