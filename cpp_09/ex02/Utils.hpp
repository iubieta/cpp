/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:19:50 by iubieta-          #+#    #+#             */
/*   Updated: 2026/04/01 21:25:16 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <ostream>
#include <vector>

// FUNCTIONS ==================================================================
int	parseInt(char *input);

// TEMPLATES ==================================================================
template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i == 0)
			os << "[ ";
		if (i < vec.size() - 1)
			os << vec[i] << ", ";
		else
			os << vec[i] << " ]";
	}
	return os;
}

#endif // !UTILS_HPP
