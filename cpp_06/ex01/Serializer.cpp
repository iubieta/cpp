
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h									:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/19 18:26:31 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cstdint>
#include "Serializer.hpp"


// Constructors, destructors and operators are not implemented since this must
// be a non instantiable class 

// Private functions ===========================================================

// Public Functions ============================================================

uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
