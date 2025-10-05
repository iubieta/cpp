/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:47:47 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 17:17:44 by iubieta-         ###   ########.fr       */
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
	std::cout << a.getType() << std::endl;
	const Cat c = Cat();
	std::cout << c.getType() << std::endl;
	const Dog d = Dog();
	std::cout << d.getType() << std::endl;
	const Animal* ap = new Animal();
	std::cout << ap->getType() << std::endl;
	const Animal* cp = new Cat();
	std::cout << cp->getType() << std::endl;
	const Animal* dp = new Dog();
	std::cout << dp->getType() << std::endl;
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
	const WrongCat wc = WrongCat();
	wc.makeSound();
	const WrongAnimal* wap = new WrongAnimal();
	wap->makeSound();
	const WrongAnimal* wcp = new WrongCat();
	wcp->makeSound();
	std::cout << std::endl;
	
	std::cout << "========== Destruction Test ==========" << std::endl;
	std::cout << std::endl;
	delete ap;
	delete cp;
	delete dp;
	delete wap;
	delete wcp;


}
