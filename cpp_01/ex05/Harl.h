/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:20:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/11 17:55:07 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <string>
class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
		using lvl = void (Harl::*)(void);
		std::map<std::string, lvl> levels;

	public:
		Harl();
		void	complain(std::string level);
};
