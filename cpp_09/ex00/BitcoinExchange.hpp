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
#include "utils.hpp"
#include <string>
#include <cctype>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

class BtcExch {
	public:
		BtcExch();
		BtcExch(const std::string &input_file);
		BtcExch(const BtcExch& other);
		BtcExch& operator=(const BtcExch& other);
		~BtcExch();

		void	calc_price(const std::string &date, float n) const;
	
	private:

		typedef std::map<std::string, float> floatmap_t;
		typedef std::pair<std::string, float> floatpair_t ;
		typedef std::map<std::string, float>::iterator floatmapiterator_t;
		typedef std::map<std::string, float>::const_iterator const_floatmapiterator_t;
		
		floatmap_t	_hist_data;

		void		loadCsv(const std::string &input_file);
		void		parseCsvHeader(const std::string &line);
		floatpair_t	parseCsvLine(const std::string &line);
};

#endif // !BTC_EX_HPP
