/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:22:57 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/11 18:05:36 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <iostream>
#include <string>

void Harl::debug(void) const{
	std::cout 
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
		<< " ketchup burger. I really do!"
		<< "\n";
}

void Harl::info(void) const{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. You didn’t put"
		<< " enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< "\n";
}

void Harl::warning(void) const{
	std::cout
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
		<< " years whereas you started working here since last month."
		<< "\n";
}
  
void Harl::error(void) const{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< "\n";
}

Harl::Harl() {
};

void Harl::complain(std::string level_key) const{
	static const struct Level levels[] = {
		{ "DEBUG", &Harl::debug },
		{ "INFO", &Harl::info },
		{ "WARNING", &Harl::warning },
		{ "ERROR", &Harl::error },
	};
	
	for (int i = 0; i < 4; i++) {
		if (levels[i].key == level_key) {
			(this->*levels[i].function)();
			return;
		}		
	}
};

