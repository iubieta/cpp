/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 17:07:51 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

// Constructors ===============================================================

Bureaucrat::Bureaucrat() 
{
	std::cout << YELLOW << "Bureaucrat constructor called" << RESET << std::endl;
	this->_name = "DefaultName";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
{
	std::cout << YELLOW << "Bureaucrat constructor called" << RESET << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_name = name;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << YELLOW << "Bureaucrat Copy constructor called" << RESET << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << YELLOW << "Bureaucrat Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << YELLOW << "Bureaucrat Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
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

void Bureaucrat::upgrade() {
	if (this->_grade == 1)
		throw GradeTooHighException();
	--this->_grade;
}

void Bureaucrat::downgrade() {
	if (this->_grade == 150)
		throw GradeTooLowException();
	++this->_grade;
}
