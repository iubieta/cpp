/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:18:17 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/22 21:20:23 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colors.h"
#include <cfloat>
#include <climits>
#include <iostream>
#include <string>

void test() {
	std::cout << YELLOW << "===== CHARS ===============" << RESET << std::endl;
	ScalarConverter::convert("\'a\'");
	ScalarConverter::convert("\'z\'");
	ScalarConverter::convert("\'0\'");
	ScalarConverter::convert("\'9\'");
	
	std::cout << YELLOW << "===== INTS ===============" << RESET << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("48");
	ScalarConverter::convert("9");
	ScalarConverter::convert("128");
	ScalarConverter::convert("-128");
	ScalarConverter::convert("-0");
	ScalarConverter::convert(std::to_string(INT_MIN));
	ScalarConverter::convert(std::to_string(INT_MAX));
	
	std::cout << YELLOW << "===== FLOATS ===============" << RESET << std::endl;
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("48.0f");
	ScalarConverter::convert("9.0f");
	ScalarConverter::convert("128f");
	ScalarConverter::convert("-128f");
	ScalarConverter::convert("-0.0f");
	ScalarConverter::convert("-0.0000001f");
	ScalarConverter::convert(std::to_string(-FLT_MAX).append("f"));
	ScalarConverter::convert(std::to_string(FLT_MAX).append("f"));
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	
	std::cout << YELLOW << "===== DOUBLES ===============" << RESET << std::endl;
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("48.0");
	ScalarConverter::convert("9.0");
	ScalarConverter::convert("128");
	ScalarConverter::convert("-128");
	ScalarConverter::convert("-0.0");
	ScalarConverter::convert("-0.0000001");
	ScalarConverter::convert(std::to_string(-DBL_MAX));
	ScalarConverter::convert(std::to_string(DBL_MAX));
	ScalarConverter::convert("nan");
	ScalarConverter::convert("inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
}

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "error: invalid number of arguments" << std::endl;
		return 1;
	}
	if (std::string(argv[1]) == "test")
		test();
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
