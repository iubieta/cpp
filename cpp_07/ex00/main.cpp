/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:37:01 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/08 13:46:32 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main() {
	int		a_int = 1;
	int		b_int = 5;

	char	a_char = 'a';
	char	b_char = 'z';

	std::cout << "min of int: " << min(a_int,b_int) << std::endl;
	std::cout << "min of char: " << min(a_char,b_char) << std::endl;
	std::cout << std::endl;
	std::cout << "max of int: " << max(a_int,b_int) << std::endl;
	std::cout << "max of char: " << max(a_char,b_char) << std::endl;
	std::cout << std::endl;

	std::cout << "int a: " << a_int << std::endl;
	std::cout << "int b: " << b_int << std::endl;
	std::cout << std::endl;

	std::cout << "swap..." << std::endl;
	swap(a_int, b_int);
	std::cout << std::endl;

	std::cout << "int a: " << a_int << std::endl;
	std::cout << "int b: " << b_int << std::endl;
	std::cout << std::endl;

	std::cout << "char a: " << a_char << std::endl;
	std::cout << "char b: " << b_char << std::endl;
	std::cout << std::endl;

	std::cout << "swap..." << std::endl;
	swap(a_char, b_char);
	std::cout << std::endl;

	std::cout << "char a: " << a_char << std::endl;
	std::cout << "char b: " << b_char << std::endl;
	std::cout << std::endl;
}
