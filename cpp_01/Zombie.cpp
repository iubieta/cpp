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
