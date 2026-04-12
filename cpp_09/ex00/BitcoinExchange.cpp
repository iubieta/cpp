/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:03:30 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/01 17:26:24 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// CHANONICAL FORM =============================================================

// CONSTRUCTORS
BtcExch::BtcExch() {};
BtcExch::BtcExch(const std::string &input_file) {
	loadCsv(input_file);
};
BtcExch::BtcExch(const BtcExch &other) : _hist_data(other._hist_data) {};

// COPY OPERATOR
BtcExch& BtcExch::operator=(const BtcExch &other) {
	if (this != &other)
		this->_hist_data = other._hist_data;
	return *this;
};

// DESTRUCTOR
BtcExch::~BtcExch() {};

// PUBLIC FUNCTIONS =========================================================

void	BtcExch::calc_price(const std::string &date, float n) const {
	const_floatmapiterator_t it = _hist_data.lower_bound(date);
	if (it == _hist_data.end())
		throw std::runtime_error("Date not found in database");
	std::cout << it->first << " => " << n
		<< " = " << it->second * n
		<< std::endl;
}

// PRIVATE FUNCTIONS =========================================================

void	BtcExch::loadCsv(const std::string &input_file) {
	std::ifstream	input(input_file.c_str(), std::ifstream::in);
	if (!input.is_open())
		throw std::runtime_error("Error: couldnt open the file");
	std::string		line;
	floatpair_t		pair;
	
	std::getline(input, line);
	while (std::getline(input,line)) {
		try {
			trim(line);
			if (line.empty()) continue;
			pair = parseCsvLine(line);
			this->_hist_data.insert(pair);
		} catch (std::exception &e)  {
			std::cout << e.what() << std::endl;
		}
	}
}
	
BtcExch::floatpair_t BtcExch::parseCsvLine(const std::string &line) {
	std::string		key;
	std::string		value_str;
	float			value;
	
	size_t	index = line.find_first_of(',');
	if (index == std::string::npos)
		throw std::runtime_error("Error: Invalid line format");
	key = line.substr(0, index);
	value_str = line.substr(index + 1);
	std::istringstream	val_ss(value_str);
	val_ss >> value;
	if (val_ss.fail() || !val_ss.eof())
		throw std::runtime_error("Invalid value: " + value_str);
	return floatpair_t(key, value);
}
