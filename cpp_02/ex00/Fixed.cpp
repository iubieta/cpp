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

Fixed::Fixed() {
	_raw = 0;
	std::cout << "Default constructor called" << std::endl;
}

// Fixed::Fixed(const Fixed& other) {
// 	_raw = other._value;
// }

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &other) {
		_raw = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_raw = raw;
}


