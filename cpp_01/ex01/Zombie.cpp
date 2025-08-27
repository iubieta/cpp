/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:43:06 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/22 20:46:35 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(std::string _name) {
	name = _name;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiinnnzzzZ...\n";
}

Zombie::~Zombie(void) {
	std::cout << name << ": Destroyed \n";
}

Zombie	*zombieHorde(int n, std::string name) {
	void* tmp = operator new(sizeof(Zombie) * n);
	Zombie *horde = static_cast<Zombie*>(tmp);

	for (int i = 0; i < n; i++) {
		new (&horde[i]) Zombie(name);
		horde[i].announce();
	}
	return horde;
}
