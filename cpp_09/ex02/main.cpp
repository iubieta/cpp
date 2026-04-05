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
		std::string input(argv[1]);
		if (input == "test1" || input == "test") {
			std::cout << BLUE << "=== BASIC TESTS ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("1"));
				Pm.sort();
				std::cout << Pm;
				int arr[1] = {1};
				std::vector<int> expected(arr, arr + 1);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[2] = {1, 2};
				std::vector<int> expected(arr, arr + 2);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[3] = {1, 2, 3};
				std::vector<int> expected(arr, arr + 3);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
		}
		if (input == "test2" || input == "test") {
			std::cout << BLUE << "=== WHOLE PAIRS ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[4] = {1, 2, 3, 4};
				std::vector<int> expected(arr, arr + 4);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
				std::vector<int> expected(arr, arr + 8);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
				std::vector<int> expected(arr, arr + 16);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
				std::vector<int> expected(arr, arr + 32);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
		}
		if (input == "test3" || input == "test") {
			std::cout << BLUE << "=== STRAGGLER TESTS ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[5] = {1, 2, 3, 4, 5};
				std::vector<int> expected(arr, arr + 5);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[7] = {1, 2, 3, 4, 5, 6, 7};
				std::vector<int> expected(arr, arr + 7);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				std::vector<int> expected(arr, arr + 9);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
		}
		if (input == "test4" || input == "test") {
			std::cout << BLUE << "=== ORDERED TEST ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("1 2 3 4 5 6 7 8"));
				Pm.sort();
				std::cout << Pm;

				int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
				std::vector<int> expected(arr, arr + 8);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("1 2 3 4 5 6 7 8 9"));
				Pm.sort();
				std::cout << Pm;

				int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
				std::vector<int> expected(arr, arr + 9);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
		}
		if (input == "test5" || input == "test") {
			std::cout << BLUE << "=== NOT 2 POWER TEST ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[6] = {1, 2, 3, 4, 5, 6};
				std::vector<int> expected(arr, arr + 6);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("10 9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				std::vector<int> expected(arr, arr + 10);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("11 10 9 8 7 6 5 4 3 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
				std::vector<int> expected(arr, arr + 11);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
		}
		if (input == "test6" || input == "test") {
			std::cout << BLUE << "=== RANDOM 2 POWER TEST ==========\n" << RESET ;
			{
				PmergeMe Pm(std::string("3 4 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[4] = {1, 2, 3, 4};
				std::vector<int> expected(arr, arr + 4);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("8 7 6 3 4 5 2 1"));
				Pm.sort();
				std::cout << Pm;

				int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
				std::vector<int> expected(arr, arr + 8);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
			{
				PmergeMe Pm(std::string("16 10 1 2 3 12 11 7 15 13 9 5 6 14 8 4"));
				Pm.sort();
				std::cout << Pm;

				int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
				std::vector<int> expected(arr, arr + 16);
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			}
		} else {
			try {
				PmergeMe Pm(input);
				Pm.sort();
				std::cout << Pm;
				
				std::vector<int> expected(Pm.getInput());
				std::sort(expected.begin(), expected.end());
				isVecOk(expected, Pm.getSortedVec());
				isListOk(expected, Pm.getSortedList());
				std::cout << std::endl;
			} catch (std::exception &e) {
				std::cout << e.what();
			}
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
