/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:40:35 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/30 15:07:11 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include <iostream>
#include <string>

HumanA::HumanA(std::string _name, Weapon& _weapon):
	name(_name),
	weapon(_weapon)
{}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
