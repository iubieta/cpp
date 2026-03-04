/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:38:21 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/01 17:21:46 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "map"
#include <string>
#include <cctype>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>

class BtcExch {
	public:
		BtcExch();
		BtcExch(std::string input_file);
		BtcExch(BtcExch& other);
		BtcExch& operator=(BtcExch& other);
		~BtcExch();

		float	calc_price(std::string date, float n);
		void	printDateValue(std::string date);
	
	private:

		typedef typename std::map<std::string, float> floatmap_t;
		typedef typename std::pair<std::string, float> floatpair_t ;
		
		floatmap_t	_hist_data;

		std::string trim(std::string str);

		void		loadCsv(std::string input_file);
		floatpair_t	parseCsvLine(std::string &line);

		bool		isLeapYear(int year);
		bool		isValidDate(std::string date);
		bool		isValidValue(float n);
};

#endif // !BTC_EX_HPP
