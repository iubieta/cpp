/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:20:27 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/30 17:27:54 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include <string>

Weapon::Weapon(std::string _type)
{
	type = _type;
}

const std::string &Weapon::getType() const
{
	return type;
}

void	Weapon::setType(const std::string& _type)
{
	type = _type;
}
