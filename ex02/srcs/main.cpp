/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:04:44 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/09/26 00:28:37 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

void printHeader(const char* title) {
	std::cout << "\n---------- " << title << " ----------\n"; 
}

template <typename It>
void	printRange(It first, It last) {

	std::cout << "[ ";
	for (; first != last; ++first)
		std::cout << *first << " ";
	std::cout << "]\n";
}

int main() {
	
	printHeader("Basic LIFO");
	{
		MutantStack<int> mi;
		mi.push(5); mi.push(3); mi.push(1);
		std::cout << "mi "; printRange(mi.begin(), mi.end());
		std::cout << "top: " << mi.top() << '\n';
		std::cout << "* pop *\n";
		mi.pop();
		std::cout << "top: " << mi.top() << '\n';	
	}

	printHeader("Copy constructor and assignment operator");
	{
		MutantStack<int> mi1;
		mi1.push(111); mi1.push(222); mi1.push(333);
		std::cout << "Original: "; printRange(mi1.begin(), mi1.end());
		MutantStack<int> mi2(mi1);
		std::cout << "Copy constructed: "; printRange(mi2.begin(), mi2.end());
		MutantStack<int> mi3;
		mi3 = mi2;
		std::cout << "Copy assigned: "; printRange(mi3.begin(), mi3.end());
	}
	
	printHeader("Construction from container");
	{
		std::deque<int> d;
		d.push_back(0); d.push_back(2); d.push_back(4); d.push_back(6); d.push_back(8);
		MutantStack<int> md(d);
		// MutantStack<int> notOk = d;				// 'Explicit' keyword blocks this unclear line to run 
		std::cout << "MutantStack constructed from container: ";
		printRange(md.begin(), md.end());
	}
	
	printHeader("Alternative underlying container");
	{
		MutantStack<int, std::vector<int> > mv;
		mv.push(1); mv.push(2); mv.push(3); mv.push(4); mv.push(5);
		printRange(mv.begin(), mv.end());
	}
	
	printHeader("Iterator usage");
	{
		MutantStack<std::string> ms;
		ms.push("never");
		ms.push("odd");
		ms.push("or");
		ms.push("even");
		const MutantStack<std::string> cms(ms);
		
		std::cout << "Iterator: "; printRange(ms.begin(), ms.end());
		std::cout << "Reverse iterator: "; printRange(ms.rbegin(), ms.rend());
		std::cout << "Const iterator: "; printRange(cms.begin(), cms.end());
		std::cout << "Const reverse iterator: "; printRange(cms.rbegin(), cms.rend());

		*ms.begin() = "always";
		// *cms.begin() = "always"; 		// Impossible it's a const iterator;
		std::cout << "MutantStack update by iterator:"; printRange(ms.rbegin(), ms.rend());
	}

	printHeader("rbegin == top");
	{
		MutantStack<int> mi;
		mi.push(10); mi.push(20); mi.push(30); mi.push(40); mi.push(50);
		std::cout << "MutantStack: "; printRange(mi.begin(), mi.end());
		std::cout << "rbegin: " << *mi.rbegin() << '\n';
		std::cout << "top: " << mi.top() << '\n';
	}

	printHeader("Empty stack iterators");
	{
		MutantStack<int> empty;
		std::cout << "begin() == end()? " << (empty.begin() == empty.end() ? "yes" : "no") << '\n';
	}

	printHeader("Algorithm integration");
	{
		MutantStack<std::string> ms;
		ms.push("Hello"); ms.push("brave"); ms.push("world");
		printRange(ms.begin(), ms.end());
		MutantStack<std::string>::iterator it;
		std::cout << "Found cool: "; it = std::find(ms.begin(), ms.end(), "cool");
		std::cout << (it != ms.end() ? "yes" : "no") << '\n';
		std::cout << "Found brave: "; it = std::find(ms.begin(), ms.end(), "brave");
		std::cout << (it != ms.end() ? "yes" : "no") << '\n';
	}

	return 0;
}