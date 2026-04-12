/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 19:06:08 by iubieta-          #+#    #+#             */
/*   Updated: 2026/04/12 19:24:14 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	trim(std::string &str) {
	size_t start = str.find_first_not_of(" \r\n\t");
	str = str.substr(start);
	size_t end = str.find_last_not_of(" \r\n\t");
	str = str.substr(0, end + 1);
}
