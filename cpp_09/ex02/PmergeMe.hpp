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

typedef std::vector<int>		Group;
typedef Group::iterator			GroupIt ;

typedef std::vector<Group>		GroupVec;
typedef GroupVec::iterator		GroupVecIt;

typedef std::list<int>			LGroup;
typedef LGroup::iterator		LGroupIt;

typedef std::list<LGroup>		LGroupList;
typedef LGroupList::iterator	LGroupListIt;

class PmergeMe {
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		
		// Getters
		Group	getInput() const;
		Group	getSortedVec() const;
		Group	getSortedList() const;
		double	getVecTime() const;
		double	getListTime() const;
		
		// Methods
		void sort();
	
	private:
		// Atributes
		Group	_original;
		Group	_sortedVec;
		Group	_sortedList;
		double	_vecTime;	
		double	_listTime;	
	
		// Private constructor
		PmergeMe();

		// Vector implementation
		void	fordJohnsonVec(GroupVec &groups);
		void	swapGroups(GroupVec &groups);
		Group	getStraggler(GroupVec &groups);
		void	mergeGroups(GroupVec &groups);
		void	splitGroups(GroupVec &groups, GroupVec &pendChain, GroupVec &winnerChain);
		void	jacobsthalInsertion(GroupVec &pendChain, GroupVec &winnerChain, GroupVec &mainChain);
		void	insertStraggler(Group &straggler, GroupVec &mainChain);
		
		// List implementation
		void	fordJohnsonList(LGroupList &groups);
		void	swapGroups(LGroupList &groups);
		LGroup	getStraggler(LGroupList &groups);
		void	mergeGroups(LGroupList &groups);
		void	splitGroups(LGroupList &groups, LGroupList &pendChain, LGroupList &winnerChain);
		void	jacobsthalInsertion(LGroupList &pendChain, LGroupList &winnerChain, LGroupList &mainChain);
		void	insertStraggler(LGroup &straggler, LGroupList &mainChain);
		
		//Utils
		static size_t	jacobsthal(size_t i);
};

bool			groupComparator(Group a, Group b);
bool			lgroupComparator(LGroup a, LGroup b);
std::ostream	&operator<<(std::ostream &os, const PmergeMe &obj);

#endif
