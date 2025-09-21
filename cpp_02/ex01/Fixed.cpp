/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:54:36 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/20 19:06:36 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <cmath>
#include <iostream>
#include <ostream>

// Constructors =================================================================

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(int i) {
	std::cout << "Int constructor called" << std::endl;
	_value = i << _fractionalBits;
	// _value = i * std::pow(2, _fractionalBits);
}

Fixed::Fixed(float f) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fractionalBits));
	// _value = roundf(f * std::pow(2, _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor ===================================================================

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Operators ====================================================================

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_value = other.getRawBits();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat(); 
	return (out);
}

// Member functions =============================================================

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const value) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = value;
}

int	Fixed::toInt(void) const {
	int i = _value >> _fractionalBits;
	return (i);
}

float	Fixed::toFloat(void) const {
	float f = (float)_value / (1 << _fractionalBits);
	return (f);
}

