/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:34:36 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/30 17:47:07 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.h"

class HumanA {
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string _name, Weapon& _weapon);
		void	attack() const;
};
