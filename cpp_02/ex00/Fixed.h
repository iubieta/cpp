/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:54:34 by iubieta-          #+#    #+#             */
/*   Updated: 2025/09/20 19:06:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class	Fixed {
	private: 
		int	_raw;
		static const int _fbits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
