/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:14:20 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/07 00:24:10 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "ERROR: check your arguments" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
		if (input == "test") {
			{
				RPN rpn("8 9 * 9 - 9 - 9 - 4 - 1 +");
				std::cout << rpn.evaluate() << std::endl;
			}
			{
				RPN rpn("7 7 * 7 -");
				std::cout << rpn.evaluate() << std::endl;
			}
			{
				RPN rpn("1 2 * 2 / 2 * 2 4 - +");
				std::cout << rpn.evaluate() << std::endl;
			}
			try {
				RPN rpn("(1 + 1)"); // Invalid token
				std::cout << rpn.evaluate() << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			try {
				RPN rpn("1 2 3 +"); // Incomplete expression
				std::cout << rpn.evaluate() << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
			try {
				RPN rpn("1 0 /"); // Division by zero
				std::cout << rpn.evaluate() << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		} else {
			try {
				RPN rpn(input);
				std::cout << rpn.evaluate() << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
	return 0;
}
