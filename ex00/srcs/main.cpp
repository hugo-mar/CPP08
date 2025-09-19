#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator> 			// std::distance

// Auxiliary function to print containers
template <typename C>
void printContainer(const C& c, const char* name) {

	std::cout << name << " = [ ";
	for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << ' ';
	std::cout << "]\n";
}

// Tests easyfind on a non const container (allows element modification)
template <typename C>
void testNonConst(C& c, int value, const char* name) {

	printContainer(c, name);
	std::cout << "searching for " << value << " in " << name << " (non const): ";
	try {
		typename C::iterator it = easyfind(c, value);
		std::cout << "found at position " << std::distance(c.begin(), it)
				  << " with value " << *it << '\n';
		// *it = *it * 100; 							// It's allowed
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}

// Tests easyfind on a const container (no modification allowed)
template <typename C>
void testConst(const C& c, int value, const char* name) {

	printContainer(c, name);
	std::cout << "searching " << value << " in " << name << " (const): ";
	try {
		typename C::const_iterator it = easyfind(c, value);
		std::cout << "found at position " << std::distance(c.begin(), it)
				  << " with value " << *it << '\n';
		// *it = *it * 100; 							// It's not allowed
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}

int main() {

	// Vector
	{
		int arrV[] = {1, 3, 5, 7, 9, 3};
		std::vector<int> v(arrV, arrV + (sizeof(arrV) / sizeof(arrV[0])));
		const std::vector<int> cV(v);
		testNonConst(v, 5, "vector");
		testNonConst(v, 42, "vector");
		testConst(cV, 9, "const vector");
		testConst(cV, 42, "const vector");
	}

	std::cout << "---------------------------\n";

	// List
	{
		int arrL[] = {2, 4, 6, 8, 0};
		std::list<int> l(arrL, arrL + (sizeof(arrL) / sizeof(arrL[0])));
		const std::list<int> cL(l);
		testNonConst(l, 2, "list");
		testNonConst(l, 42, "list");
		testConst(cL, 8, "const list");
		testConst(cL, 42, "const list");
	}

	std::cout << "---------------------------\n";

	// Deque
	{
		int arrD[] = {5, 5, 10, 15};
		std::deque<int> d(arrD, arrD + (sizeof(arrD) / sizeof(arrD[0])));
		const std::deque<int> cD(d);
		testNonConst(d, 5, "deque");
		testNonConst(d, 42, "deque");
		testConst(cD, 10, "const deque");
		testConst(cD, 42, "const deque");
	}

	return 0;
}
