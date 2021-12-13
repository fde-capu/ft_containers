/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:52:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/12 09:44:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	/*
	** Creates a LIFO object based on a sequential container copy.
	** T top() -> back()
	** void push(x) -> push_back(x)
	** void pop() -> pop_back()
	*/
	template <typename T, typename Sequence = ft::vector<T> >
		class stack
		{
			protected:
				Sequence c;

			public:
				typedef typename	Sequence::value_type		value_type;
				typedef				Sequence					container_type;
				typedef typename	Sequence::size_type			size_type;

				explicit stack(const Sequence& u = Sequence()) : c(u) { }

				bool empty() const								{ return c.empty();	}
				size_type size() const							{ return c.size();	}
				typename Sequence::reference top()				{ return c.back();	}
				typename Sequence::const_reference top() const	{ return c.back();	}
				void push(const value_type& x)					{ c.push_back(x);	}
				void pop()										{ c.pop_back();		}

				inline bool operator== (stack<T, Sequence>& rhs) { return this->c == rhs.c;	}
				inline bool operator!= (stack<T, Sequence>& rhs) { return !(*this == rhs);	}
				inline bool operator<  (stack<T, Sequence>& rhs) { return this->c < rhs.c;	}
				inline bool operator<= (stack<T, Sequence>& rhs) { return !(rhs < *this);	}
				inline bool operator>  (stack<T, Sequence>& rhs) { return rhs < *this;	 	}
				inline bool operator>= (stack<T, Sequence>& rhs) { return !(*this < rhs);	}
		};
}

#endif
