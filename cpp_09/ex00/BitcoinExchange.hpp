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

#include "map"
#include <string>

class BtcExch {
	public:
		BtcExch();
		BtcExch(std::string input_file);
		BtcExch(BtcExch& other);
		BtcExch& operator=(BtcExch& other);
		~BtcExch();

		void	load_data(std::string input_file);
		float	calc_price(std::string date, float n);
		void	printDateValue(std::string date);
	
	private:

		typedef typename std::map<std::string, float> floatMap;
		typedef typename std::pair<std::string, float> floatPair ;
		
		floatMap	_hist_data;

		std::string _trim(std::string str);

		void		_loadCsv(std::string input_file);
		floatPair	_parseCsvLine(std::string &line);

		bool		_isValidDate(std::string date);
		bool		_isValidValue(float val);
};

