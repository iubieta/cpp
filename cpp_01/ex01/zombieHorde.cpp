/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:46:13 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/05 18:24:43 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.h"

Zombie	*zombieHorde(int n, std::string name) {
	void* tmp = operator new(sizeof(Zombie) * n);
	Zombie *horde = static_cast<Zombie*>(tmp);

	for (int i = 0; i < n; i++) {
		new (&horde[i]) Zombie(name);
		horde[i].announce();
	}
	return horde;
}
