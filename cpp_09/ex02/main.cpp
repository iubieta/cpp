/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:14:20 by iubieta-          #+#    #+#             */
/*   Updated: 2026/04/01 22:38:52 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.h"
#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <pthread.h>
#include <string>
#include <vector>

void	isVecOk(std::vector<int> expected, std::vector<int> result) {
	std::cout << "Vector result: ";
	if (result == expected)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << RED << "KO" << RESET << std::endl;
}

void	isListOk(std::vector<int> expected, std::vector<int> result) {
	std::cout << "List result: ";
	if (result == expected)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << RED << "KO" << RESET << std::endl;
}

int main(int argc, char *argv[]) {
	if (argc == 2) {
		if (!argv[1][0]) {
			std::cout << "ERROR: Empty input" << std::endl;
			return 1;
		}
		std::string input(argv[1]);
		try {
			PmergeMe Pm(input);
			Pm.sort();
			std::cout << Pm;
		} catch (std::exception &e) {
			std::cout << e.what();
		}
	} else {
		try {
			PmergeMe Pm(argc, argv);
			Pm.sort();
			std::cout << Pm;
		} catch (std::exception &e) {
			std::cout << e.what();
		}
	}
	return 0;
}
