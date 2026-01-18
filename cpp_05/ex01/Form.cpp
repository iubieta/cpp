/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 17:07:51 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"
#include "Bureaucrat.h"
#include <iostream>

// Constructors ===============================================================

Form::Form() :
	_name("Default Form"), 
	_signGrade(150), 
	_execGrade(150),
	_signed(false)
{
	std::cout << BLUE << "Form default constructor called" << RESET << std::endl;
}

Form::Form(const std::string& n, const int sg, const int xg, const bool s) :
	_name(n),
	_signGrade(checkGrade(sg)),
	_execGrade(checkGrade(xg)),
	_signed(s)
{
	std::cout << BLUE << "Form constructor called" << RESET << std::endl;
}

Form::Form(const Form& other) :
	_name(other.getName()),
	_signGrade(other.getSignGrade()),
	_execGrade(other.getExecGrade()),
	_signed(other.getSigned())
{
	std::cout << BLUE << "Form Copy constructor called" << RESET << std::endl;
}

Form::~Form() {
	std::cout << BLUE << "Form Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

Form& Form::operator=(const Form& other) {
	std::cout << BLUE << "Form Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return(*this);
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os	<< obj.getName()
		<< ", sign grade " << obj.getSignGrade() 
		<< ", exec grade " << obj.getExecGrade() 
		<< ", signed ";
	if (obj.getSigned()) std::cout << "YES";
	else std::cout << "NO";
	std::cout <<  std::endl;
	return (os);
}

// Getters ====================================================================

std::string Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

int Form::getSigned() const {
	return _signed;
}

// Member functions ===========================================================

int Form::checkGrade(int g)
{
	if (g < 1) throw GradeTooHighException();
	if (g > 150) throw GradeTooLowException();
	return g;
}

void	Form::beSigned(Bureaucrat& bur)
{
	if (bur.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	if (this->getSigned() == true)
		throw FormIsAlreadySigned();
	this->_signed = true;
}
