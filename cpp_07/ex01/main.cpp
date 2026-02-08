/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:32:58 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/08 17:27:26 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

#include "../colors.h"

template <typename T> void print(const T &a) {
	std::cout << a << " ";
}

template <typename T>
void showAddress(const T& a) {
	std::cout << &a << " ";
}

template <typename T>
void showSize(const T& a) {
	std::cout << sizeof(a) << " ";
}

template <typename T>
void duplicate(T& a) {
	a = a + a;
}

template <typename T>
void reset(T& a) {
	a = T();
}

int main() {
	int			intarr[5] = {1, 2, 3, 4, 5};
	char		chararr[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string	strarr[5] = {"hello", "world", "templates", "are", "cool"};

    std::cout << YELLOW << "===== INT ARRAY ==========" << RESET <<std::endl;
	std::cout << "print: ";
	iter(intarr, 5, print<int>);
	std::cout << std::endl;
	std::cout << "address: ";
	iter(intarr, 5, showAddress<int>);
	std::cout << std::endl;
	std::cout << "size: ";
	iter(intarr, 5, showSize<int>);
	std::cout << std::endl;
	std::cout << "dup: ";
	iter(intarr, 5, duplicate<int>);
	iter(intarr, 5, print<int>);
	std::cout << std::endl;
	std::cout << "reset: ";
	iter(intarr, 5, reset<int>);
	iter(intarr, 5, print<int>);
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << "===== CHAR ARRAY ==========" << RESET <<std::endl;
	std::cout << "print: ";
	iter(chararr, 5, print<char>);
	std::cout << std::endl;
	std::cout << "address: ";
	iter(chararr, 5, showAddress<char>);
	std::cout << std::endl;
	std::cout << "size: ";
	iter(chararr, 5, showSize<char>);
	std::cout << std::endl;
	std::cout << "dup: ";
	iter(chararr, 5, duplicate<char>);
	iter(chararr, 5, print<char>);
	std::cout << std::endl;
	std::cout << "reset: ";
	iter(chararr, 5, reset<char>);
	iter(chararr, 5, print<char>);
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << "===== STRING ARRAY ==========" << RESET <<std::endl;
	std::cout << "print: ";
	iter(strarr, 5, print<std::string>);
	std::cout << std::endl;
	std::cout << "address: ";
	iter(strarr, 5, showAddress<std::string>);
	std::cout << std::endl;
	std::cout << "size: ";
	iter(strarr, 5, showSize<std::string>);
	std::cout << std::endl;
	std::cout << "dup: ";
	iter(strarr, 5, duplicate<std::string>);
	iter(strarr, 5, print<std::string>);
	std::cout << std::endl;
	std::cout << "reset: ";
	iter(strarr, 5, reset<std::string>);
	iter(strarr, 5, print<std::string>);
	std::cout << std::endl;
}
