/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:51:47 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/21 00:05:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bits/ft_tree.h"

namespace ft
{
	_node* _node::leftmost_child(_node* x)
	{ return x->left == 0 ? x : leftmost_child(x->left); }

	const _node* _node::leftmost_child(const _node* x)
	{ return x->left == 0 ? x : leftmost_child(x->left); }

	_node* _node::rightmost_child(_node* x)
	{ return x->right == 0 ? x : rightmost_child(x->right); }

	const _node* _node::rightmost_child(const _node* x)
	{ return x->right == 0 ? x : rightmost_child(x->right); }

	bool _node::is_right()
	{ return this->parent->right == this; }

	bool _node::is_left()
	{ return this->parent->left == this; }

	_node* _node::leftmost_parent(_node* x)
	{ return x->is_right() ? leftmost_parent(x->parent) : x; }

	_node* _node::rightmost_parent(_node* x)
	{ return x->is_left() ? rightmost_parent(x->parent) : x; }

	_node* _node::grand()
	{ return this->parent->parent; }

	_node* _node::uncle()
	{ return this->parent->sibling(); }

	_node* _node::sibling()
	{ return is_left() ? this->parent->right : this->parent->left; }

	_node* _node::next()
	{
		_node* n = this;
		if (n->right == 0)
		{
			n = leftmost_parent(n);
			if (n->parent != n->right)
				n = n->parent;
			return n;
		}
		else
			return n->leftmost_child(n->right);
	}

	void _node::set_parent(_node*& new_parent)
	{
		if (&*this)
			this->parent = new_parent;
	}

	bool _node::has_two_black_children()
	{ return
			(!this->left || this->left->color == black)
		&&	(!this->right || this->right->color == black); }
	
	bool _node::has_black_bool(bool b)
	{
		return \
			(b && (!this->left || this->left->color == black))
			|| (!b && (!this->right || this->right->color == black));
	}

	void _node::set_child_color(bool b, _rbcolor c)
	{
		if (b && this->left)
			this->left->color = c;
		if (!b && this->right)
			this->right->color = c;
	}

	_node*& _node::left_bool(bool b)
	{ return b ? this->left : this->right; }

	_node* _node::prev()
	{
		_node* n = this;
		if (n->color == red && n->grand() == n)
			return n->right;
		return n->left == 0 ?
			n->rightmost_parent(n)->parent
			: n->rightmost_child(n->left);
	}

	_node* _node::the_only_child()
	{ return this->left && !this->right ? this->left : !this->left && this->right ? this->right : 0; }

	bool _node::has_both_children()
	{ return this->left && this->right; }

	void _node::in_place_of(_node*& old)
	{
		if (old->is_left())
			old->parent->left = this;
		else
			old->parent->right = this;
	}

	void _tree_rot_bool_l(bool b, _node* const pivot, _node*& root)
	{
		b ? _tree_rot_l(pivot, root) : _tree_rot_r(pivot, root);
	}

	void _tree_rot_l(_node* const pivot, _node*& root)
	{
		_node* const a = pivot->right ? pivot->right->left : 0;
		_node* const y = pivot->right;
		_node* const new_pivot = pivot->parent;

		pivot->right = a;
		if (a != 0)
			a->parent = pivot;
		if (pivot == root)
			root = y;
		else if (pivot->is_left())
			new_pivot->left = y;
		else
			new_pivot->right = y;
		y->parent = new_pivot;
		y->left = pivot;
		pivot->parent = y;
	}

	void _tree_rot_r(_node* const pivot, _node*& root)
	{
		_node* const a = pivot->left->right;
		_node* const y = pivot->left;
		_node* const new_pivot = pivot->parent;

		pivot->left = a;
		if (a != 0)
			a->parent = pivot;
		if (pivot == root)
			root = y;
		else if (pivot->is_right())
			new_pivot->right = y;
		else
			new_pivot->left = y;
		y->parent = new_pivot;
		y->right = pivot;
		pivot->parent = y;
	}

	void _tree_rot_as(_node* const ref, _node* const pivot, _node*& root)
	{
		if (ref->is_left())
			return _tree_rot_l(pivot, root);
		return _tree_rot_r(pivot, root);
	}

	void _tree_rot_not_as(_node* const ref, _node* const pivot, _node*& root)
	{
		if (ref->is_left())
			return _tree_rot_r(pivot, root);
		return _tree_rot_l(pivot, root);
	}

	void _tree_rebalance_loop(_node*& pivot, _node*& root)
	{
		if (pivot == root || pivot->parent->color == black) 
			return ;

		_node* const gd_parent = pivot->grand();
		_node* const parent = pivot->parent;
		_node* const uncle = pivot->uncle();

		if (uncle && uncle->color == red) 
		{
			parent->color = black;
			uncle->color = black;
			gd_parent->color = red;
			pivot = gd_parent;
			return _tree_rebalance_loop(pivot, root);
		}

		if (parent->is_left() == pivot->is_right())
		{
			pivot = parent;
			_tree_rot_as(pivot, pivot, root);
		}

		_tree_rot_not_as(parent, gd_parent, root);
		pivot->parent->color = black;
		gd_parent->color = red;
		return _tree_rebalance_loop(pivot, root);
	}
	
	void _tree_rebalance(_node* pivot, _node*& root)
	{
		pivot->color = red;
		_tree_rebalance_loop(pivot, root);
		root->color = black;
	}
}
