/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:46:42 by iubieta-          #+#    #+#             */
/*   Updated: 2025/06/22 20:47:57 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <string>

Zombie *newZombie(std::string name) {
	Zombie *z;
	
	z = new Zombie(name);
	return z;
}
