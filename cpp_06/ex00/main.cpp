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
#include <cfloat>
#include <climits>
#include <iostream>
#include <string>

void test() {
	ScalarConverter::convert("\'a\'");
	ScalarConverter::convert("\'z\'");
	ScalarConverter::convert("\'0\'");
	ScalarConverter::convert("\'9\'");
	
	ScalarConverter::convert("0");
	ScalarConverter::convert("48");
	ScalarConverter::convert("9");
	ScalarConverter::convert("128");
	ScalarConverter::convert("-128");
	ScalarConverter::convert("-0");
	ScalarConverter::convert(std::to_string(INT_MIN));
	ScalarConverter::convert(std::to_string(INT_MAX));
	
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("48.0f");
	ScalarConverter::convert("9.0f");
	ScalarConverter::convert("128f");
	ScalarConverter::convert("-128f");
	ScalarConverter::convert("-0.0f");
	ScalarConverter::convert("-0.0000001f");
	ScalarConverter::convert(std::to_string(-FLT_MAX));
	ScalarConverter::convert(std::to_string(FLT_MAX));
	
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("48.0");
	ScalarConverter::convert("9.0");
	ScalarConverter::convert("128");
	ScalarConverter::convert("-128");
	ScalarConverter::convert("-0.0");
	ScalarConverter::convert("-0.0000001");
	ScalarConverter::convert(std::to_string(-DBL_MAX));
	ScalarConverter::convert(std::to_string(DBL_MAX));
}

int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "error: invalid number of arguments" << std::endl;
	if (std::string(argv[1]) == "test")
		test();
	else
		ScalarConverter::convert(argv[1]);
}
