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

#include <cstddef>
#include <list>
#include <string>
#include <vector>

typedef std::vector<int>::iterator vecIntIt;
typedef std::vector<int>::const_iterator const_vecIntIt;
typedef std::list<int>::iterator listIntIt;
typedef std::iterator_traits<vecIntIt>::difference_type diff_t;

class PmergeMe {
	private:
		std::string			_input;
		std::vector<int>	_inputVector;
		std::list<int>		_inputList;
		
		std::vector<int>	_sortedVector;
		std::list<int>		_sortedList;

		std::vector<int>	vectorFordJohnson(std::vector<int> &inVector, diff_t groupSize);
		std::list<int>		listFordJohnson();
		
		size_t				jacobsthal(size_t i);
		std::vector<int>	jacobsthalInsertion(std::vector<int> &inVector, diff_t groupSize);

	public:
		PmergeMe();
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		std::string			getInput() const;
		std::vector<int>	getInputVector() const;
		std::list<int>		getInputList() const;
		
		std::vector<int>	getSortedVector() const;
		std::list<int>		getSortedList() const;

		void				printSortedVector() const;
};

#endif  
