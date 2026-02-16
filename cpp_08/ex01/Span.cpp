/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:16:34 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/15 23:05:36 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "../colors.h"

Span::Span() : _capacity(2), _data(std::vector<int>()) {
	std::cout << YELLOW 
		<< "Default constructor:\n"
		<< "  capacity:" << _capacity << "\n"
		<< "  data size:" << _data.size() << "\n"
		<< "\n" << RESET;
}

Span::Span(unsigned int n) : _capacity(n), _data(std::vector<int>()) {
	std::cout << YELLOW 
		<< "Parameter constructor:\n"
		<< "  capacity:" << _capacity << "\n"
		<< "  data size:" << _data.size() << "\n"
		<< "\n" << RESET;
}

Span::Span(const Span& other) {
	*this = other;
	std::cout << YELLOW 
		<< "Copy constructor:\n"
		<< "  capacity:" << _capacity << "\n"
		<< "  data size:" << _data.size() << "\n"
		<< "\n" << RESET;
}

Span& Span::operator=(const Span& other){
	if (this != &other) {
		this->_capacity = other._capacity;
		this->_data = other._data;
	}
	return *this;
}

Span::~Span() {};

void Span::addNumber(int n) {
	if (this->_data.size() >= this->_capacity)
		throw FullException();
	this->_data.push_back(n);
}

void Span::print() const {
	std::cout << "content: [";
	for (size_t i = 0; i < _data.size(); ++i) {
		std::cout << _data[i];
		if (i < _data.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]\n";
}

int Span::shortestSpan() const{
	if (this->_data.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = this->_data;
	std::sort(sorted.begin(), sorted.end());
	int shortest = INT_MAX;
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		int span = sorted [i+1] - sorted[i];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int Span::longestSpan() const{
	if (this->_data.size() < 2)
		throw NoSpanException();
	return (*std::max_element(this->_data.begin(), this->_data.end())
			- *std::min_element(this->_data.begin(), this->_data.end()));
}
