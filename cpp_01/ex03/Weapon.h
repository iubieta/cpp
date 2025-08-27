/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:22:17 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/30 17:27:16 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string);
		const std::string &getType() const;
		void setType(const std::string&);
};
