/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:12:06 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/19 18:30:32 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
#include "Bureaucrat.h"
#include <iostream>

// Constructors ===============================================================

AForm::AForm() :
	_name("Default AForm"), 
	_signGrade(150), 
	_execGrade(150),
	_signed(false)
{
	std::cout << BLUE << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string& n, const int sg, const int xg, const bool s) :
	_name(n),
	_signGrade(_checkGrade(sg, 1, 150)),
	_execGrade(_checkGrade(xg, 1, 150)),
	_signed(s)
{
	std::cout << BLUE << "AForm constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& other) :
	_name(other.getName()),
	_signGrade(other.getSignGrade()),
	_execGrade(other.getExecGrade()),
	_signed(other.getSigned())
{
	std::cout << BLUE << "AForm Copy constructor called" << RESET << std::endl;
}

AForm::~AForm() {
	std::cout << BLUE << "AForm Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

AForm& AForm::operator=(const AForm& other) {
	std::cout << BLUE << "AForm Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return(*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	obj.print(os);
	std::cout <<  std::endl;
	return (os);
}

// Getters ====================================================================

std::string AForm::getName() const {
	return _name;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

int AForm::getSigned() const {
	return _signed;
}

// Public functions ===========================================================

int AForm::_checkGrade(int g, int max, int min) const
{
	if (g < max) throw GradeTooHighException();
	if (g > min) throw GradeTooLowException();
	return g;
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	if (this->getSigned() == true)
		throw FormIsAlreadySigned();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!this->_signed)
		throw AForm::NotSignedForm();
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	this->_doAction();
	return;
}

void AForm::print(std::ostream& out) const
{
	out	<< this->_name
		<< ", sign grade " << this->_signGrade
		<< ", exec grade " << this->_execGrade
		<< ", signed ";
	if (this->_signed) std::cout << "YES";
	else std::cout << "NO";
}
