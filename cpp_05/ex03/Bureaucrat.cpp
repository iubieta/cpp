/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/19 18:26:31 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ostream>
#include "Bureaucrat.h"
#include "AForm.h"

// Constructors ===============================================================

Bureaucrat::Bureaucrat() 
	: _name("Default Bureaucrat")
	, _grade(150)
{
	std::cout << YELLOW << "Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
	, _grade(_checkGrade(grade))
{
	std::cout << YELLOW << "Bureaucrat constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
	: _name(other.getName())
	, _grade(other.getGrade())
{
	std::cout << YELLOW << "Bureaucrat Copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << YELLOW << "Bureaucrat Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << YELLOW << "Bureaucrat Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return(*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (os);
}

// Getters ====================================================================

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

// Member functions ===========================================================

int	Bureaucrat::_checkGrade(int grade)
{
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	return grade;
}

void Bureaucrat::upgrade() {
	int grade = this->_grade - 1;
	try {
		this->_grade = _checkGrade(grade);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::downgrade() {
	int grade = this->_grade + 1;
	try {
		this->_grade = _checkGrade(grade);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout 
			<< RED
			<< this->_name << " couldn't sign " << form.getName()
			<< " because " << e.what() 
			<< RESET << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try {
		form.execute(*this);
		std::cout << this->_name 
			<< " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << this->_name 
			<< " couldn't execute " << form.getName()
			<< ": " << RED << e.what() << RESET
			<< std::endl;
	}
}
