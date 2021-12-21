/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:55:59 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/21 14:13:50 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

# include <bits/functexcept.h> // std::__throw*
# include "ft_utility.h" // ft::pair
# include "ft_algobase.h" // lexicographical_compare
# include "ft_iterator.h"

namespace ft
{ 
	enum _rbcolor { red = false, black = true };

	struct _node
	{
		_rbcolor			color; 
		_node*				parent;
		_node*				left;
		_node*				right;

		static _node*		leftmost_child(_node* x);
		static const _node*	leftmost_child(const _node* x);
		static _node*		rightmost_child(_node* x);
		static const _node*	rightmost_child(const _node* x);
		bool				is_right();
		bool				is_left();
		static _node*		leftmost_parent(_node* x);
		static _node*		rightmost_parent(_node* x);
		_node*				grand();
		_node*				uncle();
		_node*				sibling();
		_node*				next();
		_node*				prev();
		_node* the_only_child();
		bool has_both_children();
		bool has_two_black_children();
		void in_place_of(_node*&);
		void set_parent(_node*&);
		_node*& left_bool(bool b);
		bool has_black_bool(bool b);
		void set_child_color(bool b, _rbcolor c);
	};

	void _tree_rot_as(_node* const ref, _node* const pivot, _node*& root);
	void _tree_rot_not_as(_node* const ref, _node* const pivot, _node*& root);
	void _tree_rot_l(_node* const pivot, _node*& root);
	void _tree_rot_r(_node* const pivot, _node*& root);
	void _tree_rot_bool_l(bool b, _node* const pivot, _node*& root);

	void _tree_rebalance(_node*, _node*&);

	template<typename V>
		struct tree_node : public _node
		{ V	value; };

	template<typename V>
		struct _tree_iterator
		{
			_node* node;

			typedef V							value_type;
			typedef V&							reference;
			typedef V*							pointer;
			typedef _tree_iterator<V>			iterator;
			typedef const _tree_iterator<V>		const_iterator;
			typedef bidirectional_iterator_tag	iterator_category;
			typedef ptrdiff_t					difference_type;
			typedef tree_node<V>*				tree_ptr;
			typedef const tree_node<V>*			c_tree_ptr;

			_tree_iterator() {}

			_tree_iterator(tree_ptr x) : node(x) {}

			_tree_iterator(c_tree_ptr x) : node(const_cast<tree_ptr>(x)) {}

			_tree_iterator(const iterator& it) : node(it.node) {}

			reference operator* () const
			{ return static_cast<tree_ptr>(node)->value; }

			pointer operator-> () const
			{ return &static_cast<tree_ptr>(node)->value; }

			iterator& operator++ () 
			{ 
				node = node->next();
				return *this; 
			}

			iterator operator++ (int) 
			{
				iterator tmp = *this;
				node = node->next();
				return tmp;
			}

			iterator& operator-- ()
			{
				node = node->prev();
				return *this;
			}

			iterator operator-- (int) 
			{
				iterator tmp = *this;
				node = node->prev();
				return tmp;
			}

			inline bool operator== (const _tree_iterator<V>& y) const
			{ return this->node == y.node; }

			inline bool operator!= (const _tree_iterator<V>& y) const
			{ return this->node != y.node; }
		};

	template<typename T, typename A>
		class _tree_alloc_base 
		{
			protected:
				typedef tree_node<T>*								tree_ptr;
				typename A::template rebind<tree_node<T> >::other	allocator;

				tree_node<T>* alloc_node()
				{ return allocator.allocate(1); }

				void del_node(tree_ptr p)
				{ allocator.deallocate(p, 1); }

				void* val_pointer(tree_ptr p)
				{ return static_cast<void*>(&p->value); }

			public:
				_tree_alloc_base(const A& a) : allocator(a) {}
		};

	template<typename T, typename A>
		struct _tree_base : public _tree_alloc_base<T, A>
		{
			typedef _tree_alloc_base<T, A> base;
			_tree_base(const A& a) : base(a) {}
		};

	template	<	typename K, typename V, \
					typename C, typename A = std::allocator<V> >
		class _tree : protected _tree_base<V, A> 
		{
			private:
				_node								root;
				size_t								node_count;
				C									key_compare;
				typedef _tree_base<V, A>			base;
				typedef _node*&						node_ref;
				typedef const _node*				c_node_ptr;
				typedef const V&					c_val_ref;
				typedef const K&					c_key_ref;
				typedef K&							key_ref;
				typedef _node*						node_ptr;
				typedef const C&					c_comp_ref;
				typedef const A&					c_alloc_ref;
				typedef C							comp;
				typedef size_t						size_type;
				typedef const	_tree<K, V, C, A>&	c_tree_ref;
				typedef			_tree<K, V, C, A>&	tree_ref;
				typedef			_tree<K, V, C, A>	tree;
				typedef	const	_tree<K, V, C, A>	c_tree;
				typedef K&							KoV;
				typedef tree_node<V>				tree_node;

			public:
				typedef tree_node*						tree_ptr;
				typedef const tree_node*				c_tree_ptr;
				typedef A								allocator_type;
				typedef _tree_iterator<V>				iterator;
				typedef const _tree_iterator<V>			const_iterator;
				typedef const ft::reverse_iterator<iterator> \
					const_reverse_iterator;
				typedef ft::reverse_iterator<iterator>	reverse_iterator;

				allocator_type get_allocator() const
				{ return A(); }

			private:
				void l_attach(tree_ptr pivot, tree_ptr in)
				{
					pivot->left = in;
					in->parent = pivot;
					if (pivot == leftmost())
						leftmost() = in;
					if (pivot == &this->root)
					{
						root_node_ref() = in;
						rightmost() = in;
					}
				}

				void r_attach(tree_ptr pivot, tree_ptr in)
				{
					pivot->right = in;
					in->parent = pivot;
					if (pivot == rightmost())
						rightmost() = in;
				}

				iterator insert
				(node_ptr force_left, node_ptr u_piv, c_val_ref v)
				{
					tree_ptr in = new_node(v);
					tree_ptr piv = static_cast<tree_ptr>(u_piv);
					if (force_left || piv == &this->root \
						|| key_compare(KoV(v), key(piv)))
						l_attach(piv, in);
					else 
						r_attach(piv, in);
					++node_count;
					_tree_rebalance(in, this->root.parent);
					return iterator(in);
				}

				tree_ptr copy(c_tree_ptr x, tree_ptr dst)
				{
					tree_ptr y = clone_node(x);
					y->parent = dst;
					if (x->right)
						y->right = copy(right(x), y);
					if (x->left)
						y->left = copy(left(x), y);
					return y;
				}

				void erase(tree_ptr x)
				{
					if (!x)
						return ;
					erase(right(x));
					erase(left(x));
					destroy_node(x);
				}

				ft::pair<tree_ptr, tree_ptr>
				get_insert_position(c_val_ref v)
				{
					tree_ptr pos = tree_begin();
					tree_ptr piv = tree_end();
					while (pos)
					{
						piv = pos;
						pos = key_compare(KoV(v), key(pos)) ?
							left(pos) : right(pos);
					}
					return ft::pair<tree_ptr, tree_ptr>(pos, piv);
				}

				tree_ptr new_node(c_val_ref v, _rbcolor c = black)
				{
					tree_ptr n = this->alloc_node();
					new (this->val_pointer(n)) V(v);
					n->color = c;
					n->left = 0;
					n->right = 0;
					return n;
				}

				node_ref	root_node_ref()
				{ return root.parent; }

				c_node_ptr	root_node_ptr() const
				{ return root.parent; }

				tree_ptr	clone_node(c_tree_ptr x)
				{ return new_node(x->value, x->color); }

				void		destroy_node(tree_ptr x)
				{ this->del_node(x); }

				node_ref	leftmost()			{ return root.left; }
				c_node_ptr	leftmost()	const	{ return root.left; }
				node_ref	rightmost()			{ return root.right; }
				c_node_ptr	rightmost()	const	{ return root.right; }

				tree_ptr	tree_begin()
				{ return static_cast<tree_ptr>(root.parent); }

				c_tree_ptr	tree_begin() const
				{ return static_cast<c_tree_ptr>(root.parent); }

				tree_ptr	tree_end()
				{ return static_cast<tree_ptr>(&root); }
					
				c_tree_ptr	tree_end() const
				{ return static_cast<c_tree_ptr>(&root); }

				static c_val_ref	value(c_node_ptr cnp)
				{ return static_cast<c_tree_ptr>(cnp)->value; }

				static c_val_ref	value(c_tree_ptr ctp)
				{ return ctp->value; }

				static c_key_ref	key(c_node_ptr cnp)
				{ return KoV(value(cnp)); }

				static c_key_ref	key(c_tree_ptr ctp)
				{ return KoV(value(ctp)); }

				static tree_ptr		left(node_ptr np)
				{ return static_cast<tree_ptr>(np->left); }

				static c_tree_ptr	left(c_node_ptr cnp)
				{ return static_cast<c_tree_ptr>(cnp->left); }

				static tree_ptr		right(node_ptr np)
				{ return static_cast<tree_ptr>(np->right); }

				static c_tree_ptr	right(c_node_ptr cnp)
				{ return static_cast<c_tree_ptr>(cnp->right); }

				static node_ptr		leftmost_child(node_ptr np)
				{ return _node::leftmost_child(np); }

				static c_node_ptr	leftmost_child(c_node_ptr cnp)
				{ return _node::leftmost_child(cnp); }

				static node_ptr 	rightmost_child(node_ptr np)
				{ return _node::rightmost_child(np); }

				static c_node_ptr	rightmost_child(c_node_ptr cnp)
				{ return _node::rightmost_child(cnp); }

				tree_ref copy_full(tree_ref dst, c_tree_ref ori)
				{
					if (dst == ori)
						return dst;
					clear();
					dst.root.color = red;
					key_compare = ori.key_compare;
					root_node_ref() = copy(ori.tree_begin(), dst.tree_end());
					leftmost() = const_cast<ft::_node *>(leftmost_child(root_node_ptr()));
					rightmost() =  const_cast<ft::_node *>(rightmost_child(root_node_ptr()));
					node_count = ori.node_count;
					return dst;
				}

			public:
				_tree(c_comp_ref u_comp = C(), c_alloc_ref u_a = A())
				: base(u_a), node_count(0), key_compare(u_comp) 
				{
					this->root.color = red; 
					root_node_ref() = 0;
					leftmost() = tree_end();
					rightmost() = tree_end();
					node_count = 0;
				}

				_tree(c_tree_ref u_x) 
				:	base(u_x.get_allocator()), node_count(0),
					key_compare(u_x.key_compare)
				{
					this->root.color = red;
					root_node_ref() = copy(u_x.tree_begin(), this->tree_end());
					leftmost() = leftmost_child(root_node_ref());
					rightmost() = rightmost_child(root_node_ref());
					node_count = u_x.node_count;
				}

				~_tree() { clear(); }

				tree_ref operator= (c_tree_ref x)
				{ return copy_full(*this, x); }

				comp key_comp() const
				{ return key_compare; }

				iterator begin()
				{ return iterator(static_cast<tree_ptr>(this->root.left)); }

				const_iterator begin() const
				{
					return const_iterator(
						static_cast<c_tree_ptr>(this->root.left)
					);
				}

				iterator end()
				{ return iterator(static_cast<tree_ptr>(&this->root)); }

				const_iterator end() const
				{ return const_iterator(static_cast<c_tree_ptr>(&this->root)); }

				reverse_iterator rbegin()
				{ return reverse_iterator(end()); }

				const_reverse_iterator rbegin() const
				{ return const_reverse_iterator(end()); }

				reverse_iterator rend()
				{ return reverse_iterator(begin()); }

				const_reverse_iterator rend() const
				{ return const_reverse_iterator(begin()); }

				bool empty() const
				{ return node_count == 0; }

				size_t size() const
				{ return node_count; }

				size_type max_size() const
				{ return size_type(-1) / 80; }

				void reset_root(tree_ref t)
				{
					t.root_node_ref() = 0;
					t.leftmost() = t.tree_end();
					t.rightmost() = t.tree_end();
				}

				void copy_pointers(tree_ref dst, c_tree_ref ori)
				{
					dst.root_node_ref() = const_cast<node_ptr>(ori.root_node_ptr());
					dst.leftmost() = const_cast<node_ptr>(ori.leftmost());
					dst.rightmost() = const_cast<node_ptr>(ori.rightmost());
					dst.root_node_ref()->parent = dst.tree_end();
				}

				void swap(tree_ref t)
				{
					ft::swap(this->key_compare, t.key_compare);
					ft::swap(this->node_count, t.node_count);
					if (root_node_ptr() && t.root_node_ptr())
					{
						ft::swap(root_node_ref(), t.root_node_ref());
						ft::swap(leftmost(), t.leftmost());
						ft::swap(rightmost(), t.rightmost());
						root_node_ref()->parent = tree_end();
						t.root_node_ref()->parent = t.tree_end();
					}
					else if (!root_node_ptr() && t.root_node_ptr())
					{
						copy_pointers(*this, t);
						reset_root(t);
					}
				}

				ft::pair<iterator, bool> insert_unique(c_val_ref v)
				{
					ft::pair<tree_ptr, tree_ptr> pos_and_piv = get_insert_position(v);
					tree_ptr pos = pos_and_piv.first;
					tree_ptr piv = pos_and_piv.second;
					iterator piv_it = static_cast<iterator>(piv);
					if (!empty() && KoV(v) == key(piv))
						return ft::pair<iterator, bool>(piv_it, false); // repeated!
					if (piv_it == begin()) // left!
						return ft::pair<iterator, bool>(insert(pos, piv, v), true);
					if (key_compare(KoV(v), key(piv)))
						--piv_it;
					if (key_compare(key(piv_it.node), KoV(v)))
						return ft::pair<iterator, bool>(insert(pos, piv, v), true);
					if (!node_count)
						return ft::pair<iterator, bool>(insert(pos, piv, v), true);
					return ft::pair<iterator, bool>(piv_it, false); // repeated!
				}

				void insert_unique(iterator first, iterator last)
				{
					if (first == last)
						return ;
					insert_unique(*first);
					return insert_unique(++first, last);
				}

			private:
				void twist1(_node*& na, _node*& nb, bool dir, _node*& root)
				{
					na->color = black;
					nb->color = red;
					_tree_rot_bool_l(dir, nb, root);
					na = nb->left_bool(!dir);
				}

				void twist2(_node*& na, _node*& nb, _node*& nc)
				{
					na->color = red;
					nb = nc;
					nc = nc->parent;
				}

				void twist3(_node*& na, _node*& nb, bool dir, _node*& root)
				{
					na->left_bool(dir)->color = black;
					na->color = red;
					_tree_rot_bool_l(!dir, na, root);
					na = nb->left_bool(!dir);
				}
				
				void twist4(_node*& na, _node*& nb, bool dir, _node*& root)
				{
					na->color = nb->color;
					nb->color = black;
					na->set_child_color(!dir, black);
					_tree_rot_bool_l(dir, nb, root);
				}

				void root_adjust(_node*& na, _node*& nb, _node*& nc)
				{
					if (na == nb)
						nb = nc;
					else
						nc->in_place_of(na);
				}

				void most_adjust(_node*& na, _node*& nb)
				{
					if (leftmost() == na)
						leftmost() = na->right ? nb->leftmost_child(nb) : na->parent;
					if (rightmost() == na)
						rightmost() = na->left ? nb->rightmost_child(nb) : na->parent;
				}

				_node*& triangulate(_node*& x, _node*& y, _node*& del)
				{
					if (y == del->right)
						return y;
					x->set_parent(y->parent);
					y->parent->left = x;
					y->right = del->right;
					del->right->parent = y;
					return y->parent;
				}

				void y_replace(_node*& del, _node*& x, _node*& y, _node*& save_parent, _node*& root)
				{
					del->left->parent = y;
					y->left = del->left;
					save_parent = triangulate(x, y, del);
					root_adjust(del, root, y);
					y->parent = del->parent;
					ft::swap(y->color, del->color);
					y = del;
				}

				void proceed(_node*& del, _node*& x, _node*& y, _node*& save_parent, _node*& root)
				{
					save_parent = y->parent;
					x->set_parent(y->parent);
					root_adjust(del, root, x);
					most_adjust(del, x);
				}

				void erase_loop(_node*& x, _node*& save_parent, _node*& root)
				{
					while (x != root && (!x || x->color == black))
					{
						bool go_left = x == save_parent->left;
						_node* w = save_parent->left_bool(!go_left);
						if (w->color == red)
							twist1(w, save_parent, go_left, root);
						if (w->has_two_black_children())
							twist2(w, x, save_parent);
						else
						{
							if (w->has_black_bool(!go_left))
								twist3(w, save_parent, go_left, root);
							twist4(w, save_parent, go_left, root);
							break ;
						}
					}
					x ? x->color = black : 0;
				}

				_node* rebalance_for_erase(_node*& del, _node& header)
				{
					_node*& root = header.parent;
					_node* y = del->has_both_children() ? del->leftmost_child(del->right) : del;
					_node* x = y->has_both_children() ? y->right : y->the_only_child();
					_node* save_parent = 0;
					if (y != del)
						y_replace(del, x, y, save_parent, root);
					else
						proceed(del, x, y, save_parent, root);
					if (y->color != red)
						erase_loop(x, save_parent, root);
					return y;
				}

			public:
				void erase(iterator pos_as_it)
				{
					tree_ptr del = static_cast<tree_ptr>(rebalance_for_erase(pos_as_it.node, root));
					destroy_node(del);
					--node_count;
				}

				size_t erase(c_key_ref v)
				{
					iterator h = find(v);
					if (h == tree_end())
						return 0;
					erase(h);
					return 1;
				}

				void erase(iterator first, iterator last)
				{
					while (first != last)
						erase(first++);
				}

				void clear() 
				{
					erase(tree_begin());
					leftmost() = tree_end();
					rightmost() = tree_end();
					root_node_ref() = 0;
					node_count = 0;
				}

				const_iterator find(c_key_ref v) const
				{
					c_tree_ptr pos = tree_begin();
					while (pos)
					{
						if ((key(pos) == KoV(v)))
							return pos;
						pos = key_compare(KoV(v), key(pos)) ?
							left(pos) : right(pos);
					}
					return tree_end();
				}

				iterator lower_bound(c_key_ref v)
				{
					c_tree_ptr pos = tree_begin();
					c_tree_ptr lb = tree_end();
					bool comp;
					while (pos)
					{
						if (KoV(v) == key(pos))
							return pos;
						comp = key_compare(KoV(v), key(pos));
						lb = comp ? pos : lb;
						pos = comp ? left(pos) : right(pos);
					}
					return lb;
				}

				iterator upper_bound(c_key_ref v)
				{
					c_tree_ptr pos = tree_begin();
					c_tree_ptr lb = tree_end();
					bool comp;
					while (pos)
					{
						comp = key_compare(KoV(v), key(pos));
						lb = comp ? pos : lb;
						pos = comp ? left(pos) : right(pos);
					}
					return lb;
				}

				ft::pair<iterator, iterator> equal_range(const K& k)
				{
					return \
						ft::pair<iterator, iterator>(
							lower_bound(k), upper_bound(k)
						);
				}

				ft::pair<const_iterator, const_iterator>
				equal_range(c_key_ref k) const
				{
					return ft::pair<const_iterator, const_iterator>(
						lower_bound(k), upper_bound(k)
					);
				}
		};

	template<typename K, typename V, typename C, typename A>
		inline bool operator==
		(const _tree<K, V, C, A>& lhs, const _tree<K, V, C, A>& rhs)
		{
			if (lhs.size() != rhs.size())
				return false;
			typename ft::_tree<K, V, C, A>::iterator ls = lhs.begin();
			typename ft::_tree<K, V, C, A>::iterator le = lhs.end();
			typename ft::_tree<K, V, C, A>::iterator rs = rhs.begin();
			while (ls != le)
			{
				if (*ls != *rs)
					return false;
				ls++;
				rs++;
			}
			return true;
		}

	template<typename K, typename V, typename C, typename A>
		inline bool operator<
		(const _tree<K, V, C, A>& lhs, const _tree<K, V, C, A>& rhs)
		{
			return ft::lexicographical_compare(
				lhs.begin(), lhs.end(), rhs.begin(), rhs.end()
			);
		}

	template<typename K, typename V, typename C, typename A>
		inline bool operator!=
		(const _tree<K, V, C, A>& lhs, const _tree<K, V, C, A>& rhs)
		{ return !(lhs == rhs); }

	template<typename K, typename V, typename C, typename A>
		inline bool operator>
		(const _tree<K, V, C, A>& lhs, const _tree<K, V, C, A>& rhs)
		{ return rhs < lhs; }

	template<typename K, typename V, typename C, typename A>
		inline bool operator<=
		(const _tree<K, V, C, A>& lhs, const _tree<K, V, C, A>& rhs)
		{ return rhs > lhs; }

	template<typename K, typename V, typename C, typename A>
		inline bool operator>=
		(const _tree<K, V, C, A>& lhs, const _tree<K, V, C, A>& rhs)
		{ return lhs > rhs; }

	template<typename K, typename V, typename C, typename A>
		inline void swap
		(const _tree<K, V, C, A>& lhs, const _tree<K, V, C, A>& rhs)
		{ lhs.swap(rhs); }
}

#endif 
