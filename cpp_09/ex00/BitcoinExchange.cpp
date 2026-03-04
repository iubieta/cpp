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
BtcExch::BtcExch(std::string input_file) {
	loadCsv(input_file);
};
BtcExch::BtcExch(BtcExch &other) : _hist_data(other._hist_data) {};

// COPY OPERATOR
BtcExch& BtcExch::operator=(BtcExch &other) {
	if (this != &other)
		this->_hist_data = other._hist_data;
	return *this;
};

// DESTRUCTOR
BtcExch::~BtcExch() {};

// PRIVATE FUNCTIONS =========================================================

std::string	BtcExch::trim(std::string str) {
	size_t start = str.find_first_not_of(' ');
	size_t end = str.find_first_not_of(start, ' ');
	return str.substr(start, end);
}

void	BtcExch::loadCsv(std::string input_file) {
	std::ifstream	input(input_file.c_str(), std::ifstream::in);
	std::string		line;
	floatpair_t		pair;
	
	std::getline(input, line);
	while (std::getline(input,line)) {
		try {
			pair = parseCsvLine(line);
			this->_hist_data.insert(pair);
		} catch (std::runtime_error &e)  {
			std::cout << e.what();
		}
	}
}
	
BtcExch::floatpair_t BtcExch::parseCsvLine(std::string &line) {
	std::string		key;
	std::string		value_str;
	float			value;
	
	line = trim(line);
	
	size_t	index = line.find_first_of(',');
	key = line.substr(0, index);
	value_str = line.substr(index + 1);
	std::istringstream	val_ss(value_str);
	val_ss >> value;
	if (val_ss.fail() || !val_ss.eof())
		throw std::runtime_error("Invalid value: " + value_str);
	return floatpair_t(key, value);
}

void	BtcExch::printDateValue(std::string date) {
	std::cout << _hist_data.at(date);
}

bool	BtcExch::isLeapYear(int year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

bool	BtcExch::isValidDate(std::string date_str) {
	if (date_str[4] != '-' || date_str[7] != '-')
		return false;

	time_t now = time(0);
	struct tm *t = localtime(&now);
	std::istringstream date(date_str);
	int	year, month, day;
	std::istringstream (date_str.substr(0,3)) >> year;
	std::istringstream (date_str.substr(5,6)) >> month;
	std::istringstream (date_str.substr(8,9)) >> day;
	if (year < 2009 || year > t->tm_year)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2 && day > 28 && !(isLeapYear(year) && day < 30))
		return false;
	return true;
}

bool	BtcExch::isValidValue(float n) {
	if (n < 0 || n > 1000)
		return false;
	return true;
}

float	BtcExch::calc_price(std::string date, float n) {
	if (!isValidDate(date))
		throw std::runtime_error("Invalid date: " + date);
	if (!isValidValue(n))
		throw std::runtime_error("Invalid value: please enter a number between 0 and 1000");
	return (_hist_data.at(date) * n);
}
