/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:11:34 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/28 13:12:24 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>
#include <ostream>
#include <string>

// Constructors
ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	_name = "ClapTrap";
	_hitPts = 10;	
	_energyPts = 10;	
	_attackDmg = 0;
}

ClapTrap::ClapTrap(const std::string& name) {
	std::cout << "Name based constructor called" << std::endl;
	_name = name;
	_hitPts = 10;	
	_energyPts = 10;	
	_attackDmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

// Operators
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy operator called" << std::endl;
	this->_name = other.getName();
	this->_hitPts = other.getHitPts();
	this->_energyPts = other.getEnergyPts();
	this->_attackDmg = other.getAttackDmg();
	return(*this);
}

// Public members
std::string ClapTrap::getName() const {
	return (this->_name);
}

int ClapTrap::getHitPts() const {
	return (this->_hitPts);
}

int ClapTrap::getEnergyPts() const {
	return (this->_energyPts);
}

int ClapTrap::getAttackDmg() const {
	return (this->_attackDmg);
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPts < 1) {
		std::cout << "No energy points left" << std::endl;
		return;
	}
	std::cout << _name << " attacked " << target << ", causing "
		<< _attackDmg << " points of damage" << std::endl;
	--_energyPts;
}

void ClapTrap::takeDamage(const unsigned int amount) {
	std::cout << _name << " took " << amount << " of damage points" << std::endl;
	_hitPts = _hitPts - amount;
}

void ClapTrap::beReapaired(const unsigned int amount) {
	if (_energyPts < 1) {
		std::cout << "No energy points left" << std::endl;
		return;
	}
	std::cout << _name << " repaired itself, gaining " << amount << " hit points "
		<< std::endl;
	_hitPts = _hitPts + amount;
	--_energyPts;
}

void ClapTrap::status() const {
	std::cout << _name << " status: "<< std::endl;
	std::cout << "  Hit points: " << _hitPts << std::endl;
	std::cout << "  Energy points: " << _energyPts << std::endl;
	std::cout << "  Attack dmg: " << _attackDmg << std::endl;
	std::cout << std::endl;

}
