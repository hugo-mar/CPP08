/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:31:03 by hugo-mar          #+#    #+#             */
/*   Updated: 2025/09/25 23:34:34 by hugo-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	
public:
	
	// Aliases
	typedef std::stack<T, Container>						base_type;
	typedef typename base_type::container_type				container_type;		// This works, because std::stack has public alias "typedef Container container_type;"
	
	typedef typename container_type::iterator				iterator;
	typedef typename container_type::const_iterator			const_iterator;
	typedef typename container_type::reverse_iterator		reverse_iterator;
	typedef typename container_type::const_reverse_iterator	const_reverse_iterator;

	// Constructors, assignment operator and destructor
	MutantStack();
	explicit MutantStack(const container_type& init_container);
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

	// Iterators
	iterator				begin();
	iterator				end();
	const_iterator			begin() const;
	const_iterator			end() const;
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_reverse_iterator	rbegin() const;
	const_reverse_iterator	rend() const;
	
};

# include "MutantStack.tpp"

#endif