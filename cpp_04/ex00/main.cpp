/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:35:09 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include <iostream>
#include <ostream>

int main() {
	
	std::cout << "========== Constructors Test ==========" << std::endl;
	const Animal a = Animal();
	std::cout << "Type: " << a.getType() << std::endl;
	std::cout << std::endl;
	
	const Cat c = Cat();
	std::cout << "Type: " << c.getType() << std::endl;
	std::cout << std::endl;

	const Dog d = Dog();
	std::cout << "Type: " << d.getType() << std::endl;
	std::cout << std::endl;

	std::cout << "---------- Animal Pointers ----------" << std::endl;
	const Animal* ap = new Animal();
	std::cout << "Type: " << ap->getType() << std::endl;
	std::cout << std::endl;

	const Animal* cp = new Cat();
	std::cout << "Type: " << cp->getType() << std::endl;
	std::cout << std::endl;

	const Animal* dp = new Dog();
	std::cout << "Type: " << dp->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "========== Sound Test ==========" << std::endl;
	a.makeSound();
	c.makeSound();
	d.makeSound();
	ap->makeSound();
	cp->makeSound();
	dp->makeSound();
	std::cout << std::endl;


	std::cout << "========== Wrong Class Test ==========" << std::endl;
	const WrongAnimal wa = WrongAnimal();
	wa.makeSound();
	std::cout << std::endl;

	const WrongCat wc = WrongCat();
	wc.makeSound();
	std::cout << std::endl;

	const WrongAnimal* wap = new WrongAnimal();
	wap->makeSound();
	std::cout << std::endl;

	const WrongAnimal* wcp = new WrongCat();
	wcp->makeSound();
	std::cout << std::endl;
	
	std::cout << "========== Destruction Test ==========" << std::endl;
	delete ap;
	std::cout << std::endl;

	delete cp;
	std::cout << std::endl;

	delete dp;
	std::cout << std::endl;

	delete wap;
	std::cout << std::endl;

	delete wcp;
	std::cout << std::endl;


}
