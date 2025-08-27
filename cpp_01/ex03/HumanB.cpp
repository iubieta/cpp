/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:03:27 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/30 17:46:47 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include <iostream>
#include <string>

HumanB::HumanB(std::string _name)
{
	name = _name;
	weapon = NULL;
}
HumanB::HumanB(std::string _name, Weapon& _weapon)
{
	name = _name;
	weapon = &_weapon;
}

void HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}

void HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
}

