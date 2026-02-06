
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/19 18:26:31 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cfloat>
#include <climits>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <sstream>
#include <string>

#include "colors.h"
#include "ScalarConverter.hpp"


// Constructors, destructors and operators are not implemented since this must
// be a non instantiable class 

// Private functions ===========================================================
bool	_isChar(std::string str) {
	if (str.length() != 3 && str.length() != 1)
		return false;
	if (str.length() == 3 && (str[0] != '\'' || str[2] != '\''))
		return false;
	if (str.length() == 1 && std::isdigit(str[0]))
		return false;
	return true;
}

double	_checkSpecialValues(std::string str) {
	if (str == "nan" || str == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (str == "inf" || str == "inff")
		return std::numeric_limits<double>::infinity();
	if (str == "+inf" || str == "+inff")
		return std::numeric_limits<double>::infinity();
	if (str == "-inf" || str == "-inff")
		return -std::numeric_limits<double>::infinity();
	return 0;
}

// Public Functions ============================================================

void	ScalarConverter::convert(std::string str) {
	std::stringstream	ss(str);
	double				aux;
	double				val;

	if (_isChar(str))
	{
		if (str.length() == 3)
			val = static_cast<double>(str[1]);
		else
			val = static_cast<double>(str[0]);
	}
	else if ((aux = _checkSpecialValues(str)) != 0)
	{
		val = aux;
	}
	else
	{
		ss >> aux;
		if (ss.fail())
		{
			std::cout << RED <<"conversion error:" << RESET << std::endl;
			return;
		}
		if 	(ss.peek() != EOF)
		{
			char suffix;
			ss >> suffix;
			if (suffix == 'f')
			{
				char extra;
				ss >> extra;
				if (!ss.fail())
				{
					std::cout << RED <<"conversion error:" << RESET << std::endl;
					return;
				}
			}
			else {
					std::cout << RED <<"conversion error:" << RESET << std::endl;
					return;
			}
		}
		val = aux;
	}
	
	std::string conversion = "impossible";
	if (val >= 0 && val < 256)
		conversion = "Non displayable";
	if (val > 31 && val < 127)
		conversion = static_cast<char>(val);
	std::cout << "char: " << conversion << std::endl;
	
	if (val < INT_MIN || val > INT_MAX || str == "nan" || str == "nanf")
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;

	if ((val < -FLT_MAX || val > FLT_MAX) && !(std::isinf(val) || std::isnan(val)))
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(2) 
			<< static_cast<float>(val) << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(2) 
		<< val << std::endl << std::endl;
}
