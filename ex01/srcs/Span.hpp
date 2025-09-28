/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:05:20 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/09/28 11:17:17 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <cstddef>

class Span
{
	
	private:
	std::vector<int>	_data;
	unsigned int		_capacity;
	
	public:
	explicit Span(unsigned int size);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int n);
	
	template <typename It>
	void	addRange(It first, It last) {
		for (; first != last; ++first)
		addNumber(*first);
	};
	
	int		shortestSpan() const;
	int		longestSpan() const;
	
	size_t			getSize() const;
	unsigned int	getCapacity() const;
};

#endif
