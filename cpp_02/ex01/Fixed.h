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
		int	_value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(int const i);
		Fixed(float const f);
		Fixed(const Fixed& other);

		~Fixed();
		
		Fixed&			operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const value);
		int		toInt(void) const;
		float	toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
