/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:52:23 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/15 18:33:13 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../colors.h"
#include "Span.hpp"
#include <exception>
#include <iostream>
#include <iterator>

int main() {

	std::cout << BLUE << "\n=== CONSTRUCTOR TEST ===\n" << RESET;
	Span def_sp;
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print();

	std::cout << BLUE << "\n=== COPY TEST ===\n" << RESET;
	Span cp = Span(sp);
	cp.print();

	std::cout << BLUE << "\n=== ADD RANGE TEST ===\n" << RESET;
	std::vector<int> vec = std::vector<int>();
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(-17);
	vec.push_back(9);
	vec.push_back(11);
	Span sp2(5);
	sp2.addRange(vec.begin(), vec.end());
	sp.print();

	std::cout << BLUE << "\n=== ADD TOO LARGE RANGE TEST ===\n" << RESET;
	try {
		def_sp.addRange(vec.begin(), vec.end());
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "\n";

	std::cout << BLUE << "\n=== SIZE LIMIT TEST ===\n" << RESET;
	try {
		sp.addNumber(10);
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "\n";

	std::cout << BLUE << "\n=== SPAN TEST ===\n" << RESET;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "\n";
	
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	
	std::cout << BLUE << "\n=== LARGE SPAN TEST ===\n" << RESET;
	Span huge_sp(10000);
	for (size_t i = 0; i < 10000; ++i) {
		huge_sp.addNumber(i);
	}
	std::cout << "Shortest span: " << huge_sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << huge_sp.longestSpan() << std::endl;
	
	std::cout << BLUE << "\n=== EMPTY SPAN TEST ===\n" << RESET;
	Span empty_sp;
	empty_sp.print();
	try {
		empty_sp.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "\n";
	try {
		empty_sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "\n";
	std::cout << "\n";
	
	empty_sp.addNumber(5);
	empty_sp.print();
	try {
		empty_sp.shortestSpan();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "\n";
	try {
		empty_sp.longestSpan();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
	std::cout << "\n";
}
