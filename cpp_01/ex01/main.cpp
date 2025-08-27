/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:51:00 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/22 14:42:35 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
	int n = 10;
	Zombie *z =	zombieHorde(n,"Zombie");
	for (int i = 0; i<n; i++) {
		std::cout << "Zombie " << i+1 << "\n";
		z[i].announce();
	}
	delete(z);
// 	for (int i = 0; i<n; i++) {
// 		std::cout << "Zombie " << i+1 << "\n";
// 		z[i].announce();
// 	}
}
