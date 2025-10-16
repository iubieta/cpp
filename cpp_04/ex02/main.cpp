/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/13 20:13:55 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Brain.h"
#include <iostream>
#include <ostream>

int main() {

	std::cout << "========== Animal construction test ==========" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "========== Animal array construction test ==========" << std::endl;
	const Animal* animals[10];
	for (int idx = 0; idx < 10; idx++)
	{
		if (idx < 5)
			animals[idx] = new Dog();
		else
			animals[idx] = new Cat();
	}
	std::cout << std::endl;
	for (int idx = 0; idx < 10; idx++)
		delete animals[idx];
	
	std::cout << "========== Brain copy Test ==========" << std::endl;
	Brain b1;
	Brain b2;
	
	b1.setIdea(1, "locura");
	std::cout << "B1[1]: " << b1.getIdea(1) << std::endl;
	b2 = b1;
	std::cout << "B2[1]: " << b2.getIdea(1) << std::endl;
	std::cout << "Changing B2[1] to 'cordura'" << std::endl;
	b2.setIdea(1, "cordura");
	std::cout << "B1[1]: " << b1.getIdea(1) << std::endl;
	std::cout << "B2[1]: " << b2.getIdea(1) << std::endl;
	std::cout << std::endl;

	std::cout << "========== Brain Copy Test from Cat ==========" << std::endl;
	Cat c1;
	Cat c2;
	c1.setIdea(0, "I want to eat");
	c2 = c1;
	std::cout << "C1[0]: " << c1.getIdea(0) << std::endl;
	std::cout << "C2[0]: " << c2.getIdea(0) << std::endl;
	std::cout << "Changing C2[0] to 'I want to sleep'" << std::endl;
	c2.setIdea(0, "I want to sleep");
	std::cout << "C1[0]: " << c1.getIdea(0) << std::endl;
	std::cout << "C2[0]: " << c2.getIdea(0) << std::endl;
	std::cout << std::endl;
	
	std::cout << "========== Brain Copy Test from Dog ==========" << std::endl;
	Dog d1;
	Dog d2;
	d1.setIdea(0, "I want to eat");
	d1.setIdea(99, "I want to die");
	d2 = d1;
	std::cout << "d1[0]: " << d1.getIdea(0) << std::endl;
	std::cout << "d2[0]: " << d2.getIdea(0) << std::endl;
	std::cout << "d1[99]: " << d1.getIdea(99) << std::endl;
	std::cout << "d2[99]: " << d2.getIdea(99) << std::endl;
	std::cout << "Changing d2[0] to 'I want to sleep'" << std::endl;
	d2.setIdea(0, "I want to sleep");
	std::cout << "Changing d2[100] to 'I dont want to die'" << std::endl;
	d2.setIdea(99, "I dont want to die");
	std::cout << "d1[0]: " << d1.getIdea(0) << std::endl;
	std::cout << "d2[0]: " << d2.getIdea(0) << std::endl;
	std::cout << "d1[99]: " << d1.getIdea(99) << std::endl;
	std::cout << "d2[99]: " << d2.getIdea(99) << std::endl;
	std::cout << std::endl;
	
	std::cout << "========== Animal pointer ==========" << std::endl;
	Animal* a1 = new Dog();
	Animal* a2 = new Cat();
	a1->makeSound();
	a2->makeSound();
	delete a1;
	delete a2;
	std::cout << std::endl;
	
	// std::cout << "========== Animal instance ==========" << std::endl;
	// Animal a = Animal();
	// a.makeSound();
	// std::cout << std::endl;

	std::cout << "========== END ==========" << std::endl;
}
