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

#ifndef HARL_H
# define HARL_H

#include <string>
class Harl {
	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;

		typedef void (Harl::*Fn)() const;
		struct	Level {
			std::string	key;
			Fn	function;
		};

	public:
		Harl();
		void	complain(std::string level) const;
};

#endif // !HARL_H
