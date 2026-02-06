/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:15:32 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/06 23:56:49 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {};

Base* generate(void) {
	static bool	seeded = false;
	if (!seeded) {
		std::srand(time(NULL));
		seeded = true;
	}
	int r = rand() % 3;
	switch (r) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return new A();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C pointer" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A reference" << std::endl;
		return;
	} catch (std::bad_cast&) {};
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B reference" << std::endl;
		return;
	} catch (std::bad_cast&) {};
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C reference" << std::endl;
		return;
	} catch (std::bad_cast&) {};
}
