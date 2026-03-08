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
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

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
		_vec.push_back(value);
		_ls.push_back(value);
	}
	if (in.fail() && !in.eof())
		throw std::runtime_error("ERROR: invalid input found");
	if (in.bad())
		throw std::runtime_error("ERROR: something went wrong during the parsing");
}

PmergeMe::PmergeMe(PmergeMe &other) {
	this->_input = other._input;
	this->_vec = other._vec;
	this->_ls = other._ls;
}

PmergeMe& PmergeMe::operator=(PmergeMe &other) {
	if (this != &other)
		this->_input = other._input;
	return *this;
}

// Public methods =============================================================

std::string PmergeMe::getInput() const {
	return _input;
}

std::vector<int> PmergeMe::sortVector() const {
	std::vector<int>	main, pend;
	return main;
}
