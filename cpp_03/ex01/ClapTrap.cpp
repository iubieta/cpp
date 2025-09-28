/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:11:34 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/28 14:25:24 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>
#include <ostream>
#include <string>

// Constructors ===============================================================

ClapTrap::ClapTrap() : 
	_name("ClapTrap"), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << BLUE << "Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
	_name(name), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << BLUE << "Name based constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, int hp, int energy, int dmg) :
	_name(name), _hitPts(hp), _energyPts(energy), _attackDmg(dmg)
{
	std::cout << BLUE << "Full constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << BLUE << "Destructor called" << RESET<< std::endl;
}

// Operators ==================================================================

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << BLUE << "Copy operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPts = other.getHitPts();
		this->_energyPts = other.getEnergyPts();
		this->_attackDmg = other.getAttackDmg();
	}
	return(*this);
}

// Getters ====================================================================

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

// Member functions ===========================================================

void ClapTrap::attack(const std::string& target) {
	if (_energyPts < 1) {
		std::cout << RED << "No energy points left" << RESET << std::endl;
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
		std::cout << RED << "No energy points left" << RESET << std::endl;
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
}
