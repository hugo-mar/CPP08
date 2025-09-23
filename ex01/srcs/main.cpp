/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:54:30 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/09/23 14:09:59 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

void printHeader(const char* title) {
	std::cout << "\n---------- " << title << " ----------\n"; 
}

int main() {
	
	// Test 1
	{
		printHeader("Subject test");
		try {
			Span sp = Span(5);
			
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
		
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test 2
	{
		printHeader("Exceptions test");
	
		Span sp(3);
		
		sp.addNumber(1);
		try {
			std::cout << "Shortest span on an object of " << sp.getSize() << " elements: ";
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span on an object of " << sp.getSize() << " elements: ";
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	
		sp.addNumber(5);
		sp.addNumber(10);
		try {
			std::cout << "Shortest span on an object of " << sp.getSize() << " elements: ";
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span on an object of " << sp.getSize() << " elements: ";
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		try {
			std::cout << "Attempt to had 1 element to an object that has reached his max capacity\n";
			sp.addNumber(22);
			std::cout << "UNEXPECTED ERROR, THE NUMBER WAS ADDED\n";
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test 3
	{
		printHeader("addRange with at least 10.000 numbers test ");
		
		srand(time(NULL));
		int	n(10000);

		std::vector<int> v;
		v.reserve(n);

		for (int i = 0; i < n; ++i)
			v.push_back(rand() % INT_MAX);

		Span sp(n);
		
		try{
			std::cout << "Attempting to add a range of " << v.size()
					  << " elements to an object of capacity " << sp.getCapacity()
					  << " and size " << sp.getSize()
					  << ": ";
			sp.addRange(v.begin(), v.end());
			std::cout << "OK\n";

			std::cout << "Shortest span on an object of " << sp.getSize() << " elements: ";
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << "Longest span on an object of " << sp.getSize() << " elements: ";
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		try{
			std::cout << "Attempting to add a range of " << v.size()
					  << " elements to an object of capacity " << sp.getCapacity()
					  << " and size " << sp.getSize()
					  << ": ";
			sp.addRange(v.begin(), v.end());
			std::cout << "OK\n";
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	
	return 0;
}