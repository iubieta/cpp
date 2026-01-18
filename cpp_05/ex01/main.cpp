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
#include "Form.h"
#include <exception>
#include <iostream>
#include <ostream>

int main() {
	std::cout << "========== Constructors Test ==========" << std::endl;
	std::cout << "Default:" << std::endl;
	Form def;
	std::cout << def;
	std::cout << std::endl;

	std::cout << "Name = Salary check, sign grade = 150, exec grade = 150:" << std::endl;
	Form salaryCheck("Salary check", 150, 150, false);
	std::cout << salaryCheck;
	std::cout << std::endl;

	std::cout << "Name = Holiday, sign grade = 50, exec grade = 150:" << std::endl;
	Form holiday("Holiday form", 50, 150, false);
	std::cout << holiday;
	std::cout << std::endl;

	std::cout << "Name = Boss Order, sign grade = 1, exec grade = 150:" << std::endl;
	Form bossOrder("Boss Order", 1, 150, false);
	std::cout << bossOrder;
	std::cout << std::endl;

	std::cout << "Name = Salary revision, sign grade = 1, exec grade = 10:" << std::endl;
	Form salaryRev("Salary revision", 1, 10, false);
	std::cout << salaryRev;
	std::cout << std::endl;
	
	std::cout << "Salary Revision copy:" << std::endl;
	Form salaryRev2(salaryRev);
	std::cout << salaryRev2;
	std::cout << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat employee("Employee", 150);
	std::cout << std::endl;

	std::cout << "========== Sign Test ==========" << std::endl;
	std::cout << "Salary check: " << std::endl;
	employee.signForm(salaryCheck);
	std::cout << std::endl;
	
	std::cout << "Holiday form: " << std::endl;
	employee.signForm(holiday);
	std::cout << holiday;
	manager.signForm(holiday);
	std::cout << holiday;
	boss.signForm(holiday);
	std::cout << holiday;
	std::cout << std::endl;
	
	std::cout << "Salary Revision: " << std::endl;
	employee.signForm(salaryRev);
	std::cout << salaryRev;
	manager.signForm(salaryRev);
	std::cout << salaryRev;
	boss.signForm(salaryRev);
	std::cout << salaryRev;
	std::cout << std::endl;
	
	std::cout << "Boss order: " << std::endl;
	employee.signForm(bossOrder);
	std::cout << bossOrder;
	manager.signForm(bossOrder);
	std::cout << bossOrder;
	boss.signForm(bossOrder);
	std::cout << bossOrder;
	std::cout << std::endl;

	std::cout << "========== Exec Test ==========" << std::endl;
	std::cout << std::endl;
	
	std::cout << "========== Destruction Test ==========" << std::endl;
}
