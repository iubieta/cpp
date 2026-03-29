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

#include "PmergeMe.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "ERROR: check your arguments" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
		if (input == "test") {
			// {
			// 	PmergeMe util(std::string("9 8 7 6 5 4 3 2 1"));
			// 	util.printSortedVector();
			// 	std::cout << std::endl;
			// }
			{
				PmergeMe util(std::string("9 5 2 6 4 7 8 3 1"));
				util.printSortedVector();
				std::cout << std::endl;
			}
		} else {
		}
	return 0;
}
