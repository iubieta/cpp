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
	_value = 0;
}

Fixed::Fixed(int i) {
	_value = i << _fractionalBits;
	// _value = i * std::pow(2, _fractionalBits);
}

Fixed::Fixed(float f) {
	_value = roundf(f * (1 << _fractionalBits));
	// _value = roundf(f * std::pow(2, _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

// Destructor ===================================================================

Fixed::~Fixed() {}

// Operators ====================================================================

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed tmp;
	tmp._value = this->_value + other._value;
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed tmp(this->toFloat() * other.toFloat());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed tmp;
	tmp._value = (this->_value * other._value) >> _fractionalBits;
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed tmp;
	tmp._value = (this->_value << _fractionalBits) / other._value;
	return (tmp);
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->_value < other._value);
}

bool Fixed::operator>(const Fixed& other) const {
	return (this->_value > other._value);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->_value <= other._value);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->_value >= other._value);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->_value == other._value);
}

Fixed& Fixed::operator++() {
	++this->_value;
	return (*this);
}

Fixed& Fixed::operator--() {
	--this->_value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	_value++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	_value--;
	return (tmp);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat(); 
	return (out);
}

// Member functions =============================================================

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const value) {
	_value = value;
}

int	Fixed::toInt(void) const {
	int i = _value >> _fractionalBits;
	return (i);
}

float Fixed::toFloat(void) const {
	float f = (float)_value / (1 << _fractionalBits);
	return (f);
}

Fixed& Fixed::min(Fixed& a, Fixed&b) {
	if (a < b)
		return(a);
	return(b);
}

Fixed& Fixed::max(Fixed& a, Fixed&b) {
	if (a < b)
		return(a);
	return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed&b) {
	if (a._value < b._value)
		return(a);
	return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed&b) {
	if (a._value > b._value)
		return(a);
	return(b);
}

