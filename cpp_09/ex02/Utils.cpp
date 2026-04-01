/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:20:11 by iubieta-          #+#    #+#             */
/*   Updated: 2026/04/01 21:43:39 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <cerrno>
#include <cstdlib>
#include <limits>
#include <stdexcept>

int	parseInt(char *str) {
	errno = 0;
	char *end;
	long n = std::strtol(str, &end, 10);
	if (end == str)
		throw std::invalid_argument("Imposible to parse as Int");
	if (*end != '\0')
		throw std::invalid_argument("Non numeric characters found");
	if (errno == ERANGE)
		throw std::out_of_range("Value out of long range");
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		throw std::out_of_range("Value out of int range");
	return static_cast<int>(n);
}
