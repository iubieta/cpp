/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:18:30 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/06 23:51:12 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main() {
	Base* obj;
	for (int i = 0; i < 5; i++) {
		obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
		std::cout << std::endl;
	}
}
