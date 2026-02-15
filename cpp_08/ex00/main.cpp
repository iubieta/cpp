/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:14:46 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/15 18:31:38 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <typeinfo>
#include <vector>
#include "../colors.h"

#define SIZE 16

template<typename T>
typename T::iterator easyfind(T& container, int value) {
	return std::find(container.begin(), container.end(), value);
}

template <typename T>
void	test_easyfind(T& container) {
	std::cout << YELLOW << "Testing with: " << typeid(container).name() << "\n" << RESET;
	std::cout << "container = [";
	for (size_t i = 0; i < SIZE; ++i) {
		container.push_back(i);
		std::cout << container.back();
		if (i < SIZE - 1) {
			std::cout << ", ";
		} else {
			std::cout << "]\n";
		}
	}
	int value = 10;
	typename T::iterator it = easyfind(container, value);
	if (it != container.end()) {
		std::cout << GREEN << "Value " << value << " Found" << "\n" << RESET ;
	} else {
		std::cout << RED << "Value " << value << " Not Found" << "\n" << RESET ;
	}
	value = 25;
	it = easyfind(container, value);
	if (it != container.end()) {
		std::cout << GREEN << "Value " << value << " Found" << "\n" << RESET ;
	} else {
		std::cout << RED << "Value " << value << " Not Found" << "\n" << RESET ;
	}

}

int main() {
	std::cout << BLUE << "\n=== VECTOR ===\n" << RESET;
	std::vector<int> vec;
	test_easyfind(vec);

	std::cout << BLUE << "\n=== LIST ===\n" << RESET;
	std::list<int> ls;
	test_easyfind(ls);
	
	std::cout << BLUE << "\n=== DEQUE ===\n" << RESET;
	std::deque<int> dq;
	test_easyfind(dq);
}
