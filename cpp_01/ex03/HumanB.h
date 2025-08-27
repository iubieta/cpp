/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:39:39 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/30 17:44:55 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.h"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string);
		HumanB(std::string _name, Weapon& _weapon);
		void	setWeapon(Weapon&);
		void	attack() const;
};
