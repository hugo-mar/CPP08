/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 01:30:51 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/09/19 00:27:33 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>

template<typename C>
typename C::iterator easyfind(C& c, int value) {
	
	typename C::iterator it = std::find(c.begin(), c.end(), value);
	if (it == c.end())
		throw std::runtime_error("value not found");
	return it;
}

template<typename C>
typename C::const_iterator easyfind(const C& c, int value) {

	typename C::const_iterator it = std::find(c.begin(), c.end(), value);
	if (it == c.end())
		throw std::runtime_error("value not found");
	return it;
}