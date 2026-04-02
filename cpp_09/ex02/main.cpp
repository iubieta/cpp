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
#include <iostream>
#include <pthread.h>
#include <string>

int main(int argc, char *argv[]) {
	std::string input(argv[1]);
		if (input == "test") {
			{
				PmergeMe Pm(std::string("9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm << std::endl;
			}
			{
				PmergeMe Pm(std::string("9 5 2 6 4 7 8 3 1"));
				Pm.sort();
				std::cout << Pm << std::endl;
			}
		} else {
			PmergeMe(argc, argv);
		}
	return 0;
}
