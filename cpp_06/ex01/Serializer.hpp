/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:19:37 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/22 21:17:58 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <stdint.h>
#include <string>

struct	Data {
	int			id;
	std::string	name;
	float		value;
};

class	Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};


#endif
