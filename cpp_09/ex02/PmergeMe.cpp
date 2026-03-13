/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:29:22 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/09 00:10:52 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Class Construction =========================================================

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::string &input) : _input(input) {
	std::istringstream in(input);
	int	value;
	while (in >> value) {
		if (value < 0) {
			std::ostringstream oss;
			oss << "ERROR: negative integer found => " << value;
			throw std::runtime_error(oss.str());
		}
		_inputVector.push_back(value);
		_inputList.push_back(value);
	}
	if (in.fail() && !in.eof())
		throw std::runtime_error("ERROR: invalid input found");
	if (in.bad())
		throw std::runtime_error("ERROR: something went wrong during the parsing");
	std::vector<int> auxVector = _inputVector;
	_sortedVector = vectorFordJohnson(auxVector, 1);
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	this->_input = other._input;
	this->_inputVector = other._inputVector;
	this->_inputList = other._inputList;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_input = other._input;
		this->_inputVector = other._inputVector;
		this->_inputList = other._inputList;
	}
	return *this;
}

PmergeMe::~PmergeMe() {};

// Public methods =============================================================

std::string PmergeMe::getInput() const {
	return _input;
}

std::vector<int> PmergeMe::getInputVector() const {
	return _inputVector;
}

std::list<int> PmergeMe::getInputList() const {
	return _inputList;
}

std::vector<int> PmergeMe::getSortedVector() const {
	return _sortedVector;
}

std::list<int> PmergeMe::getSortedList() const {
	return _sortedList;
}

void PmergeMe::printSortedVector() const {
	for (const_vecIntIt it = _sortedVector.begin(); it != _sortedVector.end(); ++it) {
		if (it == _sortedVector.begin())
			std::cout << " [ ";
		std::cout << *it;
		if (it != _sortedVector.end() - 1)
			std::cout  << " , ";
	}
	std::cout << " ] ";
}

// Ford Johnson algorithm =====================================================
//
std::vector<int> PmergeMe::vectorFordJohnson(std::vector<int> &inVector, diff_t groupSize) {
	
	//1. Pairing and comparing
	for (vecIntIt i = inVector.begin(); inVector.end() - i >= groupSize * 2; i+=groupSize * 2) {
		if (*(i + groupSize - 1) > *(i + groupSize * 2 - 1))
			std::swap_ranges(i, i + groupSize, i + groupSize);
	}

	//2. Recursion
	if (inVector.end() - inVector.begin() > groupSize * 2)
		inVector = vectorFordJohnson(inVector, groupSize * 2);
	
	//3. Insercion
	std::vector<int> sortVector = jacobsthalInsertion(inVector, groupSize);
	return sortVector;
}

std::vector<int> jacobsthalInsertion(std::vector<int> &inVector, diff_t groupSize) {
	diff_t pairSize = groupSize * 2;
	size_t groupNumber = inVector.size() / pairSize;
	if (groupNumber == 0)
		return inVector;
	std::vector<int> mains;
	std::vector<int> pends;
	for (size_t i = 0; i < groupNumber; ++i) {
		vecIntIt pos = mains.begin() + i * pairSize;
		vecIntIt main = inVector.begin() + (i + 1) * groupSize;
		vecIntIt pend = inVector.begin() + i * groupSize;
		mains.insert(pos, main, main + groupSize);
		pends.insert(pos, pend, pend + groupSize);
	}

	std::vector<size_t> positions;
	for (size_t i = 0; i < groupNumber; ++i) {
		positions.push_back(i);
	}

	mains.insert(mains.begin(), pends.begin(), pends.begin() + groupSize);
	for (size_t i = 0; i < groupNumber; ++i) {
		positions[i] = positions[i] + 1;
	}
}

// void PmergeMe::insertGroup(std::vector<int> &dest, std::vector<int> &origin, size_t i, diff_t size) {
// 	vecIntIt pos = dest.begin() + i * size;
// 	vecIntIt start = origin.begin() + (i + 1) * size / 2;
// 	vecIntIt end = origin.begin() + (i + 1) * size / 2 + size / 2;
// 	dest.insert(pos, start, end);
// }

size_t jacobsthal(size_t i) {
	static std::vector<size_t>	cache(2, 1);
	while (cache.size() < i)
		cache.push_back(cache.back() + 2 * cache[cache.size() - 2]);
	return cache[i];
}
