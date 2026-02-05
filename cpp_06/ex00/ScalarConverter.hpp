/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:19:37 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/22 21:17:58 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <string>

class	ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		~ScalarConverter();
		

	public:
		static void	convert(std::string str);
};


#endif
