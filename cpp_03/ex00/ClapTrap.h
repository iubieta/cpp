/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:57:54 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/28 12:59:19 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>

class	ClapTrap {
	private:
		std::string	_name;	
		int			_hitPts;	
		int			_energyPts;	
		int			_attackDmg;

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		std::string	getName() const;
		int		getHitPts() const;
		int		getEnergyPts() const;
		int		getAttackDmg() const;

		void	attack(const std::string& target);
		void	takeDamage(const unsigned int amount);
		void	beReapaired(const unsigned int amount);

		void	status() const;
};
