/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:18:17 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/22 21:20:23 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdint>
#include <iostream>


int main() {
	Data		d;
	Data		*ptr;
	uintptr_t	raw;

	d.id = 0;
	d.name = "My Data";
	d.value = 42.0;

	std::cout 
		<< "ORIGINAL DATA:" << std::endl
		<< "id:" << d.id << std::endl
		<< "name:" << d.name << std::endl
		<< "value:" << d.value << std::endl
		<< std::endl;

	raw = Serializer::serialize(&d);
	ptr = Serializer::deserialize(raw);
	
	std::cout 
		<< "SERIALIZED DATA:" << std::endl
		<< "id:" << ptr->id << std::endl
		<< "name:" << ptr->name << std::endl
		<< "value:" << ptr->value << std::endl
		<< std::endl
		<< "VERIFICATION:" << std::endl
		<< "Original ptr:     " << &d << std::endl
		<< "Deserialized ptr: " << ptr << std::endl
		<< "Pointers match:   " << (&d == ptr ? "✓ YES" : "✗ NO") << std::endl;
}
