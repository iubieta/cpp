/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:50:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/12 18:49:50 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <iostream>
#include <string>

int	main (int argc, char **argv) {
	
	if (argc != 2)
		std::cout << "ERROR: check your arguments\n";

	Harl H;

	std::string lvl = argv[1];
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;
	for (int i = 0; i < 4; i++)
		if (lvl == levels[i])
			index = i;

	switch (index) {
		case 0:
			H.complain("debug");
			/* fall through */
		case 1:
			H.complain("info");
			/* fall through */
		case 2:
			H.complain("warning");
			/* fall through */
		case 3:
			H.complain("error");
			break;
		default:
			std::cout << "[Probably complaining...]\n";
	} 
}
