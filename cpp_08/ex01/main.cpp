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
#include <iostream>

int main() {
	std::cout << BLUE << "\n=== BASIC TEST ===\n" << RESET;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	
	std::cout << BLUE << "\n=== ADD RANGE TEST ===\n" << RESET;
	std::vector<int> vec = std::vector<int>();
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);
	Span sp2 = Span(5);
	sp2.addRange(vec.begin(), vec.end());
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	return 0;
}
