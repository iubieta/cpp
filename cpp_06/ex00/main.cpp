/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:18:17 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/22 21:20:23 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <algorithm>
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "error: invalid number of arguments" << std::endl;
	ScalarConverter::convert(argv[0]);
}
