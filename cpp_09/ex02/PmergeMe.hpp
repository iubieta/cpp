/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 19:34:17 by iubieta-          #+#    #+#             */
/*   Updated: 2026/04/02 01:18:53 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <list>
#include <string>
#include <vector>

typedef std::vector<int>	Group;
typedef std::vector<Group>	GroupVec;

class PmergeMe {
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sort();
	
	private:
		Group	_original;
		Group	_sortedVec;
		Group	_sortedList;
		double	_vecTime;	
		double	_listTime;	
	
		// Private constructor
		PmergeMe();

		// Sorting algorithm
		void	fordJohnsonVec(GroupVec &groups);
		//void fordJohnsonList();
		
		//Utils
		static size_t	jacobsthal(size_t n);
};

#endif
