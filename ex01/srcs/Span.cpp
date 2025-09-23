/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:58:04 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/09/22 22:54:25 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int n) : _data(), _capacity(n) {
	_data.reserve(_capacity);
}

Span::Span(const Span& other)
	: _data(other._data), _capacity(other._capacity) {}

Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		_data = other._data;
		_capacity = other._capacity;		
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n) {
	if (_data.size() >= _capacity)
		throw std::length_error("Insufficient capacity");
	_data.push_back(n);
}

int		Span::shortestSpan() const {
	
	if (_data.size() < 2)
		throw std::logic_error("Not enough numbers");
	
	std::vector<int> tmp(_data);
	std::sort(tmp.begin(), tmp.end());

	int best = tmp[1] - tmp[0];
	for (size_t i = 1; (i + 1) < tmp.size(); ++i) {
		if ((tmp[i + 1] - tmp[i]) < best) {
			best = tmp[i + 1] - tmp[i];
			if (best == 0 ) break;
		}
	}
	
	return best;
}

int		Span::longestSpan() const {

	if (_data.size() < 2)
		throw std::logic_error("Not enough numbers");
	
	std::vector<int>::const_iterator max = std::max_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator min = std::min_element(_data.begin(), _data.end());

	return *max - *min;
}

size_t	Span::getSize() const {
		return _data.size();
}

unsigned int	Span::getCapacity() const {
	return _capacity;
}