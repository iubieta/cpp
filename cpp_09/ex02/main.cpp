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
#include <cmath>
#include <iostream>
#include <pthread.h>
#include <string>
#include <vector>

void	isTestOk(std::vector<int> expected, std::vector<int> result) {
	if (result == expected)
		std::cout << GREEN << "OK" << RESET << std::endl;
	else
		std::cout << RED << "KO" << RESET << std::endl;
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {
	std::string input(argv[1]);
		if (input == "test") {
			std::cout << BLUE << "=== BASIC TESTS ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("1"));
				Pm.sort();
				std::cout << Pm;
				int arr[1] = {1};
				std::vector<int> expected(arr, arr + 1);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[2] = {1, 2};
				std::vector<int> expected(arr, arr + 2);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[3] = {1, 2, 3};
				std::vector<int> expected(arr, arr + 3);
				isTestOk(expected, Pm.getSortedVec());
			}
			std::cout << BLUE << "=== WHOLE PAIRS ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("4 3 2 1"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[4] = {1, 2, 3, 4};
				std::vector<int> expected(arr, arr + 4);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
				std::vector<int> expected(arr, arr + 8);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
				std::vector<int> expected(arr, arr + 16);
				isTestOk(expected, Pm.getSortedVec());
			}
			std::cout << BLUE << "=== STRAGGLER TESTS ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[5] = {1, 2, 3, 4, 5};
				std::vector<int> expected(arr, arr + 5);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[7] = {1, 2, 3, 4, 5, 6, 7};
				std::vector<int> expected(arr, arr + 7);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				std::vector<int> expected(arr, arr + 9);
				isTestOk(expected, Pm.getSortedVec());
			}
			std::cout << BLUE << "=== ORDERED TEST ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("1 2 3 4 5 6 7 8"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
				std::vector<int> expected(arr, arr + 8);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("1 2 3 4 5 6 7 8 9"));
				Pm.sort();
				std::cout << Pm;
				
				int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				std::vector<int> expected(arr, arr + 9);
				isTestOk(expected, Pm.getSortedVec());
			}
			std::cout << BLUE << "=== NOT 2 POWER TEST ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[6] = {1, 2, 3, 4, 5, 6};
				std::vector<int> expected(arr, arr + 6);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("10 9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				std::vector<int> expected(arr, arr + 10);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("11 10 9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
				std::vector<int> expected(arr, arr + 11);
				isTestOk(expected, Pm.getSortedVec());
			}
			std::cout << BLUE << "=== RANDOM 2 POWER TEST ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("3 4 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[4] = {1, 2, 3, 4};
				std::vector<int> expected(arr, arr + 4);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("8 7 6 3 4 5 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
				std::vector<int> expected(arr, arr + 8);
				isTestOk(expected, Pm.getSortedVec());
			}
			{
				PmergeMe Pm(std::string("16 10 1 2 3 12 11 7 15 13 9 5 6 14 8 4"));
				Pm.sort();
				std::cout << Pm;

				int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
				std::vector<int> expected(arr, arr + 11);
				isTestOk(expected, Pm.getSortedVec());
			}
		} else {
			PmergeMe(argc, argv);
		}
	return 0;
}
