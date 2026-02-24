/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:38:21 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/24 20:00:17 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map"
#include <string>

class BtcExch {
	private:
		std::map<std::string, float>	_hist_data;

		std::map<std::string, float> csv_to_map(std::string input_file);
		bool	isValidKey(std::string key);
		bool	isValidValue(std::string value);
		void	parseCSVline(std::map<std::string, float>&map, std::);
	
	public:
		BtcExch();
		BtcExch(std::string input_file);
		BtcExch(BtcExch& other);
		BtcExch& operator=(BtcExch& other);

		void	load_data(std::string input_file);
		void	calc_price(std::string date, int n);
};

