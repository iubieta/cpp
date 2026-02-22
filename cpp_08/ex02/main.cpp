/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:50:23 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/22 19:56:41 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

#include "MutantStack.hpp"
#include <vector>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(17);
	std::cout << vec.back() << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;

	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);

	std::vector<int>::iterator vec_it = vec.begin();
	std::vector<int>::iterator vec_ite = vec.end();
	++vec_it;
	--vec_it;
	while (vec_it != vec_ite)
	{
		std::cout << *vec_it << std::endl;
		++vec_it;
	}

	return 0;
}
