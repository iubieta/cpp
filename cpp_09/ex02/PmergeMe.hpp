/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 19:34:17 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/08 23:46:32 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

typedef std::vector<int>::iterator vecIntIt;
typedef std::list<int>::iterator listIntIt;

class PmergeMe {
	private:
		std::string			_input;
		std::vector<int>	_vec;
		std::list<int>		_list;

		void	swapGroup(std::vector<int> inVector, size_t index, size_t groupSize);

	public:
		PmergeMe();
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		std::string			getInput() const;
		std::vector<int>	getVec() const;
		std::list<int>		getList() const;

		std::vector<int>	vectorFordJohnson(std::vector<int> inVector, int groupSize);
		std::list<int>		listFordJohnson();
};

#endif  
