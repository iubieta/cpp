
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/19 18:26:31 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cfloat>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <numeric>

#include "colors.h"

#include "ScalarConverter.hpp"

// Constructors ===============================================================

// ScalarConverter::ScalarConverter() 
// {
// 	std::cout << YELLOW << "ScalarConverter constructor called" << RESET << std::endl;
// }
//
// ScalarConverter::ScalarConverter(const ScalarConverter& other) 
// {
// 	std::cout << YELLOW << "ScalarConverter Copy constructor called" << RESET << std::endl;
// }
//
// ScalarConverter::~ScalarConverter() {
// 	std::cout << YELLOW << "ScalarConverter Destructor called" << RESET<< std::endl;
// }
//
// Private Function ============================================================

enum Flags {
	CHAR = 1 << 1,
	PRINTABLE = 1 << 2,
	INTEGER = 1 << 3,
	FLOAT = 1 << 4,
	DOUBLE = 1 << 5,
};


bool	_isOneChar(const std::string str) {
	if (str[1])
		return false;
	return true;
}

bool	_isPrintableChar(const std::string str) {
	if (str[0] < 32 || str[0] > 126)
		return false;
	return true;
}

bool	_isInteger(const std::string str) {
	long	n = std::stol(str);

	if (n < INT32_MIN || n > INT32_MAX)
		return false;
	return true;
}

bool	_isFloat(const std::string str) {
	double	f = std::stof(str);

	if (f < FLT_MIN || f > FLT_MAX)
		return false;
	return true;
}

bool	_isDouble(const std::string str) {
	long double d = std::stold(str);

	if (d < DBL_MIN || d > DBL_MAX)
		return false;
	return true;
}

uint8_t	_getPrintMask(const std::string str) {

	uint8_t	print_flag = 0;

	if (_isOneChar(str))
		print_flag |= CHAR;
	if (_isPrintableChar(str))
		print_flag = print_flag | PRINTABLE;
	if (_isInteger(str))
		print_flag = print_flag | INTEGER;
	if (_isFloat(str))
		print_flag = print_flag | FLOAT;
	if (_isDouble(str))
		print_flag = print_flag | DOUBLE;
	return print_flag;
}


void	ScalarConverter::convert(std::string str) {
	uint8_t	print_mask = _getPrintMask(str);

	long double s = stold(str);

	if (print_mask & CHAR)
		if (print_mask & PRINTABLE)
			std::cout << "char: " << static_cast<char>(s) << std::endl;
		else 
			std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: imposible" << std::endl;

	if (print_mask & INTEGER)
		std::cout << "int: " << static_cast<int>(s) << std::endl;
	else
		std::cout << "int: imposible" << std::endl;

	if (print_mask & FLOAT)
		std::cout << "float: " << static_cast<float>(s) << std::endl;
	else
		std::cout << "float: imposible" << std::endl;
	
	if (print_mask & DOUBLE)
		std::cout << "double: " << static_cast<double>(s) << std::endl;
	else
		std::cout << "double: imposible" << std::endl;

}
