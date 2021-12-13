/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:57:35 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/13 02:47:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

template<typename K, typename V>
void check_map()
{
	title("MAP");
	title(typeid(K).name());
	title(typeid(V).name());
	title("Member types");
	check(1, typeid(typename ft::map<K, V>::key_type).name(), typeid(K).name()); 
	check(2, typeid(typename ft::map<K, V>::mapped_type).name(), typeid(V).name()); 
	check(3, typeid(typename ft::map<K, V>::value_type).name(), typeid(ft::pair<const K, V>).name()); 
	check(4, typeid(typename ft::map<K, V>::key_compare).name(), typeid(std::less<K>).name()); 
	check(5, typeid(typename ft::map<K, V>::value_compare).name(), typeid(typename ft::map<K, V>::value_compare).name());
	check(6, typeid(typename ft::map<K, V>::allocator_type).name(), typeid(std::allocator<ft::pair<const K, V> >).name());
	check(7, typeid(typename ft::map<K, V>::reference).name(), typeid(typename std::allocator<ft::pair<const K, V> >::reference).name());
	check(8, typeid(typename ft::map<K, V>::const_reference).name(), typeid(typename std::allocator<ft::pair<const K, V> >::const_reference).name());
	check(9, typeid(typename ft::map<K, V>::pointer).name(), typeid(typename std::allocator<ft::pair<const K, V> >::pointer).name());
	check(10, typeid(typename ft::map<K, V>::const_pointer).name(), typeid(typename std::allocator<ft::pair<const K, V> >::const_pointer).name());
	ft::bidirectional_iterator_tag t_bidir_tag;
	const ft::bidirectional_iterator_tag c_t_bidir_tag;
	check(11, typeid(typename ft::iterator_traits<typename ft::map<K, V>::iterator>::iterator_category).name(), typeid(t_bidir_tag).name());
	check(12, typeid(typename ft::iterator_traits<typename ft::map<K, V>::const_iterator>::iterator_category).name(), typeid(c_t_bidir_tag).name());
	check(13, typeid(typename ft::iterator_traits<typename ft::map<K, V>::reverse_iterator>::iterator_category).name(), typeid(t_bidir_tag).name());
	check(14, typeid(typename ft::iterator_traits<typename ft::map<K, V>::const_reverse_iterator>::iterator_category).name(), typeid(c_t_bidir_tag).name());
	check(15, is_reverse_iterator<typename ft::map<K, V>::reverse_iterator>::value, true);
	check(16, is_reverse_iterator<typename ft::map<K, V>::const_reverse_iterator>::value, true);
	check(17, is_reverse_iterator<typename ft::map<K, V>::iterator>::value, false);
	check(18, is_reverse_iterator<typename ft::map<K, V>::const_iterator>::value, false);
	check(19, typeid(typename ft::map<K, V>::difference_type).name(), typeid(ptrdiff_t).name());
	check(20, typeid(typename ft::map<K, V>::size_type).name(), typeid(size_t).name());
	
	title("Constructors");
	check(1, typeid(ft::map<K, V>).name(), typeid(ft::map<K, V>).name());
	check(2, typeid(ft::map<K, V, std::less<K> >).name(), typeid(ft::map<K, V, std::less<K> >).name());
	check(3, typeid(ft::map<K, V, std::less<K>, std::allocator<ft::pair<const K, V> > >).name(), typeid(ft::map<K, V, std::less<K>, std::allocator<ft::pair<const K, V> > >).name());

	ft::map<K, V> mm;
	/*            ^*/

	mm[K(7)] = V(742);
	mm[K(8)] = V(842);
	mm[K(9)] = V(942);
	mm[K(6)] = V(642);

	check(4, ft::map<K, V>(mm.find(K(8)), mm.end())[K(8)], mm[K(8)]);
	check(5, ft::map<K, V>(mm.find(K(8)), mm.end())[K(7)], V(0));
	check(6, (*ft::map<K, V>(mm.find(K(8)), mm.end()).begin()).second, V(842));
	check(6, (*(++ft::map<K, V>(mm.find(K(8)), mm.end()).begin())).second, V(942));
	check(7, (*(--ft::map<K, V>(mm.begin(), mm.end()).end())).second, V(942));
	check(8, (*(--ft::map<K, V>(mm.begin(), --mm.end()).end())).second, V(842));
	check(9, ft::map<K, V>(mm.begin(), mm.end(), std::less<K>())[K(7)], V(742));
	check(10, ft::map<K, V>(mm.begin(), mm.end(), std::less<K>(), std::allocator<ft::pair<K, V> >())[K(7)], V(742));
	check(11, ft::map<K, V>(mm)[K(8)], V(842));
	ft::map<K, V> mm_cp = mm;
	check(12, mm_cp[K(8)], mm[K(8)]);

	title("Iterators");
	check(1, (*mm.begin()).first, K(6));
	check(2, (*--mm.end()).first, K(9));
	check(3, (*mm.rbegin()).first, K(9));
	check(4, (*--mm.rend()).first, K(6));
	typename ft::map<K, V>::iterator i = mm.begin();
	check(5, (*i).first, K(6));
	check(6, (*++i).first, K(7));
	(*i).second = V(74242);
	check(7, (*i).second, V(74242));
	typename ft::map<K, V>::const_iterator ci = mm.begin();
	check(8, (*ci).first, K(6));
	typename ft::map<K, V>::reverse_iterator ri = mm.rbegin();
	check(9, (*ri).first, K(9));
	check(10, (*++ri).first, K(8));
	(*ri).second = V(84242);
	check(11, (*ri).second, V(84242));
	typename ft::map<K, V>::const_reverse_iterator cri = mm.rbegin();
	check(12, (*cri).first, K(9));

	title("Capacity");
	check(1, mm.empty(), false);
	check(2, ft::map<K, V>().empty(), true);
	check(3, mm.size(), static_cast<typename ft::map<K, V>::size_type>(4));
	check(4, mm_cp.size(), static_cast<typename ft::map<K, V>::size_type>(4));
	mm_cp[K(5)] = V(542);
	check(5, mm_cp.size(), static_cast<typename ft::map<K, V>::size_type>(5));
	check(6, ft::map<K, V>().size(), static_cast<typename ft::map<K, V>::size_type>(0));
	check(7, mm.max_size(), size_t(-1), NOT_EQUAL); // system dependent

	title("Elements");
	check(1, mm[K(8)], V(84242));
	check(2, mm[K(8)] = V(8842), V(8842));
	check(3, mm[K(7)] = V(424242), V(424242));

	title("Modifiers");
	{
		title("insert (1)");
		ft::pair<typename ft::map<K, V>::iterator, bool> new_el = mm.insert(ft::pair<K, V>(K(99), V(999)));
		check(1, (*new_el.first).first, K(99));
		check(2, (*new_el.first).second, V(999));
		check(3, new_el.second, true);
		check(4, mm[K(98)], V(0));
		check(5, mm.size(), static_cast<typename ft::map<K, V>::size_type>(6));
		ft::pair<typename ft::map<K, V>::iterator, bool> not_new = mm.insert(ft::pair<K, V>(K(8), V(888)));
		check(6, (*not_new.first).first, K(8));
		check(7, (*not_new.first).second, V(888), NOT_EQUAL);
		check(8, not_new.second, false);
		check(9, mm[K(8)], V(888), NOT_EQUAL);
		check(10, mm.size(), static_cast<typename ft::map<K, V>::size_type>(6));
	}
	{
		title("insert (2)");
		typename ft::map<K, V>::iterator new_el = mm.insert(++mm.begin(), ft::pair<K, V>(K(88), V(888)));
		check(1, (*new_el).first, K(88));
		check(2, (*new_el).second, V(888));
		check(3, mm[K(88)], V(888));
		check(4, mm.size(), static_cast<typename ft::map<K, V>::size_type>(7));
		typename ft::map<K, V>::iterator not_new = mm.insert(++mm.begin(), ft::pair<K, V>(K(8), V(888)));
		check(6, (*not_new).first, K(8));
		check(7, (*not_new).second, V(888), NOT_EQUAL);
		check(8, mm[K(8)], V(888), NOT_EQUAL);
		check(9, mm.size(), static_cast<typename ft::map<K, V>::size_type>(7));
		title("insert (3)");
		mm_cp.insert(mm.begin(), --mm.end());
		check(1, mm_cp[K(88)], V(888));
		check(2, mm_cp.size(), static_cast<typename ft::map<K, V>::size_type>(7));
		check(3, mm_cp[K(99)], V(999), NOT_EQUAL);
		check(4, mm_cp[K(99)], V());
		mm_cp.insert(mm.begin(), mm.end());
		check(5, mm_cp.size(), static_cast<typename ft::map<K, V>::size_type>(8));
		mm_cp.insert(mm.begin(), mm.end());
		check(6, mm_cp.size(), static_cast<typename ft::map<K, V>::size_type>(8));
	}
	title("erase (1)");
	mm.insert(ft::pair<K, V>(K(5), V(15))); // (preparation)
	mm.insert(ft::pair<K, V>(K(4), V(14))); // ...
	check(1, (*mm.begin()).first, K(4));
	check(2, (*mm.begin()).second, V(14));
	check(3, mm.size(), static_cast<typename ft::map<K, V>::size_type>(9));
	check(4, (*++mm.begin()).first, K(5));
	check(5, (*++mm.begin()).second, V(15));
	{
		mm.erase(++mm.begin());
		check(6, (*++mm.begin()).first, K(5), NOT_EQUAL);
		check(7, (*++mm.begin()).second, V(15), NOT_EQUAL);
		check(8, mm.size(), static_cast<typename ft::map<K, V>::size_type>(8));
		mm.erase(mm.begin());
		check(9, (*mm.begin()).first, K(6));
		check(10, (*mm.begin()).second, V(642));
		check(11, mm.size(), static_cast<typename ft::map<K, V>::size_type>(7));
		mm.erase(--mm.end());
		check(12, (*--mm.end()).first, K(99), NOT_EQUAL);
		check(13, (*--mm.end()).second, V(999), NOT_EQUAL);
		check(14, mm.size(), static_cast<typename ft::map<K, V>::size_type>(6));
	}
	mm.insert(ft::pair<K, V>(K(1), V(11))); // ...
	mm.insert(ft::pair<K, V>(K(2), V(12))); // ...
	mm.insert(ft::pair<K, V>(K(3), V(13))); // ...
	mm.insert(ft::pair<K, V>(K(4), V(14))); // ...
	mm.insert(ft::pair<K, V>(K(5), V(15))); // (preparation)
	mm.insert(ft::pair<K, V>(K(100), V(1000))); // ...
	mm.insert(ft::pair<K, V>(K(101), V(1001))); // ...
	mm.insert(ft::pair<K, V>(K(102), V(1002))); // ...
	mm.insert(ft::pair<K, V>(K(103), V(1003))); // ...
	mm.insert(ft::pair<K, V>(K(104), V(1004))); // ...
	{
		title("erase (2)");
		check(1, mm.size(), static_cast<typename ft::map<K, V>::size_type>(16));
		typename ft::map<K, V>::size_type pop_size = mm.erase(K(1));
		check(2, mm.size(), static_cast<typename ft::map<K, V>::size_type>(15));
		check(3, pop_size, static_cast<typename ft::map<K, V>::size_type>(1));
		check(4, (*mm.begin()).first, K(1), NOT_EQUAL);
		check(5, (*mm.begin()).second, V(11), NOT_EQUAL);

		pop_size = mm.erase(K(3));
		check(6, pop_size, static_cast<typename ft::map<K, V>::size_type>(1));
		check(7, mm.size(), static_cast<typename ft::map<K, V>::size_type>(14));
		check(8, (*++mm.begin()).first, K(3), NOT_EQUAL);
		check(9, (*++mm.begin()).second, V(13), NOT_EQUAL);

		pop_size = mm.erase(K(103));
		check(10, pop_size, static_cast<typename ft::map<K, V>::size_type>(1));
		check(11, mm.size(), static_cast<typename ft::map<K, V>::size_type>(13));
		check(12, (*----mm.end()).first, K(103), NOT_EQUAL);
		check(13, (*----mm.end()).second, V(1003), NOT_EQUAL);

		pop_size = mm.erase(K(104));
		check(14, pop_size, static_cast<typename ft::map<K, V>::size_type>(1));
		check(15, mm.size(), static_cast<typename ft::map<K, V>::size_type>(12));
		check(16, (*--mm.end()).first, K(104), NOT_EQUAL);
		check(17, (*--mm.end()).second, V(1004), NOT_EQUAL);

		check(18, (*--mm.end()).first, K(102));
		check(19, (*--mm.end()).second, V(1002));
		check(20, mm[K(1)], V(11), NOT_EQUAL);
		check(21, mm[K(3)], V(13), NOT_EQUAL);
		check(22, mm[K(103)], V(1003), NOT_EQUAL);
		check(23, mm[K(104)], V(1004), NOT_EQUAL);
		check(24, mm.size(), static_cast<typename ft::map<K, V>::size_type>(16));
		mm.insert(ft::pair<K, V>(K(2), V(12))); // ...
		check(25, (*mm.begin()).second, V(12), NOT_EQUAL);
		check(26, (*mm.begin()).second, V(0));
	}

	/*
		ft::map<K, V> mm;

        K: 1    V: 0
        K: 2    V: 12
        K: 3    V: 0
        K: 4    V: 14
        K: 5    V: 15
        K: 6    V: 642
        K: 7    V: 424242
        K: 8    V: 8842
        K: 9    V: 942
        K: 88   V: 888
        K: 98   V: 0
        K: 100  V: 1000
        K: 101  V: 1001
        K: 102  V: 1002
        K: 103  V: 0
        K: 104  V: 0
	*/

	title("erase (3)");
	{
		{
			ft::map<K, V> cc(mm);
			cc.erase(--cc.begin(), --cc.begin());	// 01 // ** [a  , b  , c  , d  ]
			check(1, cc.size(), static_cast<typename ft::map<K, V>::size_type>(16));
			check(2, (*cc.begin()).first, K(1));
			check(3, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(--cc.begin(), cc.end());	// 06 // *  [a  , b  , c  , d  ] *
			check(4, cc.size(), static_cast<typename ft::map<K, V>::size_type>(16));
			check(5, (*cc.begin()).first, K(1));
			check(6, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(cc.begin(), cc.begin());	// 07 //    [a**, b  , c  , d  ]
			check(7, cc.size(), static_cast<typename ft::map<K, V>::size_type>(16));
			check(8, (*cc.begin()).first, K(1));
			check(9, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(cc.begin(), ++cc.begin());	// 08 //    [a* , b* , c  , d  ]
			check(10, cc.size(), static_cast<typename ft::map<K, V>::size_type>(15));
			check(11, (*cc.begin()).first, K(2));
			check(12, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(cc.begin(), ----cc.end());	// 09 //    [a* , b  , c* , d  ]
			check(13, cc.size(), static_cast<typename ft::map<K, V>::size_type>(2));
			check(14, (*cc.begin()).first, K(103));
			check(15, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(cc.begin(), --cc.end());	// 10 //    [a* , b  , c  , d* ]
			check(16, cc.size(), static_cast<typename ft::map<K, V>::size_type>(1));
			check(17, (*cc.begin()).first, K(104));
			check(18, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(cc.begin(), cc.end());	// 11 //    [a* , b  , c  , d  ] *
			check(19, cc.size(), static_cast<typename ft::map<K, V>::size_type>(0));
			check(20, cc.empty(), true);
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(++cc.begin(), ++cc.begin()); // 12 //    [a  , b**, c  , d  ]
			check(21, cc.size(), static_cast<typename ft::map<K, V>::size_type>(16));
			check(22, (*cc.begin()).first, K(1));
			check(23, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(++cc.begin(), ----cc.end());	// 13 //    [a  , b* , c* , d  ]
			check(24, cc.size(), static_cast<typename ft::map<K, V>::size_type>(3));
			check(25, (*cc.begin()).first, K(1));
			check(26, (*++cc.begin()).first, K(103));
			check(27, (*--cc.end()).first, K(104));
			check(28, (*----cc.end()).first, K(103));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(++cc.begin(), --cc.end());	// 14 //    [a  , b* , c  , d* ]
			check(29, cc.size(), static_cast<typename ft::map<K, V>::size_type>(2));
			check(30, (*cc.begin()).first, K(1));
			check(31, (*++cc.begin()).first, K(104));
			check(32, (*--cc.end()).first, K(104));
			check(33, (*----cc.end()).first, K(1));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(++cc.begin(), cc.end());	// 15 //    [a  , b* , c  , d  ] *
			check(34, cc.size(), static_cast<typename ft::map<K, V>::size_type>(1));
			check(35, (*cc.begin()).first, K(1));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(----cc.end(), ----cc.end());	// 16 //    [a  , b  , c**, d  ]
			check(36, cc.size(), static_cast<typename ft::map<K, V>::size_type>(16));
			check(37, (*cc.begin()).first, K(1));
			check(38, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(----cc.end(), --cc.end());	// 17 //    [a  , b  , c* , d* ]
			check(39, cc.size(), static_cast<typename ft::map<K, V>::size_type>(15));
			check(40, (*cc.begin()).first, K(1));
			check(41, (*--cc.end()).first, K(104));
			check(42, (*----cc.end()).first, K(102));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(----cc.end(), cc.end());	// 18 //    [a  , b  , c* , d  ] *
			check(43, cc.size(), static_cast<typename ft::map<K, V>::size_type>(14));
			check(44, (*cc.begin()).first, K(1));
			check(45, (*--cc.end()).first, K(102));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(--cc.end(), --cc.end());	// 19 //    [a  , b  , c  , d**]
			check(46, cc.size(), static_cast<typename ft::map<K, V>::size_type>(16));
			check(47, (*cc.begin()).first, K(1));
			check(48, (*--cc.end()).first, K(104));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(--cc.end(), cc.end());	// 20 //    [a  , b  , c  , d* ] *
			check(49, cc.size(), static_cast<typename ft::map<K, V>::size_type>(15));
			check(50, (*cc.begin()).first, K(1));
			check(51, (*--cc.end()).first, K(103));
		}
		{
			ft::map<K, V> cc(mm);
			cc.erase(cc.end(), cc.end());	// 21 //    [a  , b  , c  , d  ] **
			check(52, cc.size(), static_cast<typename ft::map<K, V>::size_type>(16));
			check(53, (*cc.begin()).first, K(1));
			check(54, (*--cc.end()).first, K(104));
		}
	}

	title("swap\t");
	{
		ft::map<K, V> ma;
		ft::map<K, V> mb;

		ma[K(1)] = V(11);
		ma[K(3)] = V(22);
		ma[K(7)] = V(33);
		mb[K(11)] = V(1111);
		mb[K(13)] = V(2222);

		ma.swap(mb);
		check(1, (*ma.begin()).second, V(1111));
		check(2, (*--ma.end()).second, V(2222));
		check(3, (*mb.begin()).second, V(11));
		check(4, (*--mb.end()).second, V(33));
		check(5, ma.size(), static_cast<typename ft::map<K, V>::size_type>(2));
		check(6, mb.size(), static_cast<typename ft::map<K, V>::size_type>(3));

		ft::map<K, V> mempty;
		ma.swap(mempty);
		check(7, ma.size(), static_cast<typename ft::map<K, V>::size_type>(0));
		ma.swap(mb);
		check(8, mb.size(), static_cast<typename ft::map<K, V>::size_type>(0));
		check(9, ma.size(), static_cast<typename ft::map<K, V>::size_type>(3));
		check(10, (*ma.begin()).second, V(11));
	}

	title("clear\t");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(111)] = V(1111);
		ma[K(222)] = V(2222);
		check(1, ma.size(), static_cast<typename ft::map<K, V>::size_type>(5));
		ma.clear();
		check(2, ma.size(), static_cast<typename ft::map<K, V>::size_type>(0));
		ma.clear();
		check(3, ma.size(), static_cast<typename ft::map<K, V>::size_type>(0));
	}

	title("Observers");
	title("key_comp");
	{
		ft::map<K, V> ma;

		K x = K();
		ma[K(x + 1)] = V(11);
		ma[K(x + 2)] = V(22);
		ma[K(x + 3)] = V(33);
		ma[K(x + 6)] = V(126);
		ma[K(x + 7)] = V(127);
		ma[K(x + 8)] = V(6);

		typename ft::map<K, V>::key_compare kc = ma.key_comp();

		check(1, kc(ma[K(x + 1)], ma[K(x + 2)]), true);
		check(2, kc(ma[K(x + 2)], ma[K(x + 3)]), true);
		check(3, kc(ma[K(x + 3)], ma[K(x + 2)]), false);
		check(4, kc(ma[K(x + 3)], ma[K(x + 9)]), false);
		check(5, kc(ma[K(x + 3)], ma[K(x + 7)]), true);

		check(6, kc((*ma.begin()).first, (*++ma.begin()).first), true);
		check(7, kc((*++ma.begin()).first, (*ma.begin()).first), false);
		check(8, kc((*--ma.end()).second, (*ma.begin()).second), true);
		check(9, kc((*ma.begin()).second, (*--ma.end()).second), false);
		check(10, kc((*ma.begin()).first, (*ma.begin()).first), false);
	}
	title("value_comp");
	{
		ft::map<K, V> ma;
		ma[K(111)] = V(1111);
		ma[K(2)] = V(22);
		ma[K(3333)] = V(6);
		ma[K(3)] = V(33);
		ma[K(1)] = V(11);
		ma[K(222)] = V(2222);
		check(1, ma.value_comp()(*ma.begin(), *++ma.begin()), true);
		check(2, ma.value_comp()(*++ma.begin(), *ma.begin()), false);
		check(3, ma.value_comp()(*--ma.end(), *ma.begin()), false);
		check(4, ma.value_comp()(*ma.begin(), *--ma.end()), true);
		check(5, ma.value_comp()(*ma.begin(), *ma.begin()), false);
	}
	title("(more)\t");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(111)] = V(111);
		ma[K(112)] = V(112);
		ma[K(160)] = V(160);

		typename ft::map<K, V>::key_compare k = ma.key_comp();
		check(1, k(K(1), K(2)), true);
		check(2, k(K(2), K(1)), false);
		check(3, k(K(1), K(1)), false);

		typename ft::map<K, V>::value_compare v = ma.value_comp();
		check(4, v(ft::pair<K, V>(K(1), V(11)), ft::pair<K, V>(K(2), K(22))), true);
		check(5, v(ft::pair<K, V>(K(2), V(22)), ft::pair<K, V>(K(1), K(11))), false);
		check(6, v(ft::pair<K, V>(K(1), V(11)), ft::pair<K, V>(K(1), K(11))), false);
		check(7, v(ft::pair<K, V>(K(1), V(99)), ft::pair<K, V>(K(1), K(11))), false);
	}
	title("Operations");
	title("find\t");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(111)] = V(1111);
		ma[K(222)] = V(2222);
		ma[K(3333)] = V(6);
		check(1, (*ma.find(K(2))).second, V(22));
		check(2, (*++ma.find(K(2))).second, V(33));
		check(3, (*--ma.find(K(2))).second, V(11));
		check(4, (*ma.find(K(3333))).second, V(6));
		check(5, ma.size(), static_cast<typename ft::map<K, V>::size_type>(6));
		check(6, ma.find(K(4242)) == ma.end(), true);
		check(7, ma.size(), static_cast<typename ft::map<K, V>::size_type>(6));
	}
	title("count\t");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(111)] = V(1111);
		ma[K(222)] = V(2222);
		ma[K(3333)] = V(6);
		check(1, ma.count(K(3)), static_cast<unsigned int>(1));
		check(2, ma.count(K(4242)), static_cast<unsigned int>(0));
		check(3, ma.count(K(1)), static_cast<unsigned int>(1));
		check(4, ma.count(K(3333)), static_cast<unsigned int>(1));
		check(5, ma.count(K(4242)), static_cast<unsigned int>(0));
		check(6, ma[K(4242)] == V(4242), false);
		check(7, ma.count(K(4242)), static_cast<unsigned int>(1));
		ma[K(4242)] = V(42);
		check(8, ma.count(K(4242)), static_cast<unsigned int>(1));
	}
	title("lower_bound");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(124)] = V(1111);
		ma[K(125)] = V(2222);
		ma[K(126)] = V(6);
		check(1, *ma.lower_bound(K(1)) == *ma.begin(), true);
		check(2, *ma.lower_bound(K(7)) == *ma.begin(), false);
		check(3, *ma.lower_bound(K(2)) == *++ma.begin(), true);
		check(4, *ma.lower_bound(K(2)) > *ma.begin(), true);
		check(5, *ma.lower_bound(K(99)) > *ma.find(K(3)), true);
		check(6, *ma.lower_bound(K(99)) == *ma.find(K(124)), true);
		check(7, *ma.lower_bound(K(99)) > *ma.find(K(99)), true);
		check(8, *ma.lower_bound(K(126)) > *ma.find(K(2)), true);
		check(9, *ma.lower_bound(K(126)) == *ma.find(K(126)), true);
		check(10, ma.lower_bound(K(127)) == ma.end(), true);
		check(11, ma.lower_bound(K(77)) == ma.end(), false);
	}
	title("upper_bound");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(124)] = V(124);
		ma[K(125)] = V(125);
		ma[K(126)] = V(6);
		check(1, *ma.upper_bound(K(1)) == *++ma.begin(), true);
		check(2, *ma.upper_bound(K(7)) == *ma.begin(), false);
		check(3, *ma.upper_bound(K(2)) == *++++ma.begin(), true);
		check(4, *ma.upper_bound(K(2)) > *ma.begin(), true);
		check(5, *ma.upper_bound(K(99)) > *ma.find(K(3)), true);
		check(6, *ma.upper_bound(K(99)) == *ma.find(K(124)), true);
		check(7, *ma.upper_bound(K(99)) > *ma.find(K(99)), true);
		check(8, *ma.upper_bound(K(125)) > *ma.find(K(2)), true);
		check(9, *ma.upper_bound(K(125)) == *ma.find(K(125)), false);
		check(10, ma.upper_bound(K(126)) == ma.end(), true);
		check(11, ma.upper_bound(K(127)) == ma.end(), true);
		check(12, ma.upper_bound(K(77)) == ma.end(), false);
	}
	title("equal_range");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(124)] = V(124);
		ma[K(125)] = V(125);
		ma[K(126)] = V(6);
		check(1, ma.equal_range(K(7)).first == (ma.equal_range(K(7))).second, true);
		check(2, ma.equal_range(K(1)).first != (ma.equal_range(K(1))).second, true);
		check(3, ma.equal_range(K(1)).first == ma.find(K(1)), true);
		check(4, ma.equal_range(K(1)).second == ma.find(K(2)), true);
		check(5, ma.equal_range(K(3)).first == ma.find(K(3)), true);
		check(6, ma.equal_range(K(3)).second == ma.find(K(124)), true);
		check(7, ma.equal_range(K(126)).first == ma.find(K(126)), true);
		check(8, ma.equal_range(K(126)).second == ma.end(), true);
		check(9, ma.equal_range(K(99)).first == ma.find(K(124)), true);
		check(10, ma.equal_range(K(99)).second == ma.find(K(124)), true);
		check(11, ma.equal_range(K(127)).first == ma.end(), true);
		check(12, ma.equal_range(K(127)).second == ma.end(), true);
	}
	title("Allocator");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(111)] = V(1111);
		ma[K(222)] = V(2222);
		ma[K(3333)] = V(6);
		try
		{
			ft::pair<const K, V>* a = ma.get_allocator().allocate(42);
			check(1, 1, 1);
			ma.get_allocator().deallocate(a, 42);
			check(2, 2, 2);
			a = ma.get_allocator().allocate(420);
			check(3, 3, 3);
			ma.get_allocator().deallocate(a, 420);
			check(4, 4, 4);
		}
		catch(std::exception&e)
		{
			check(1, "get_allocator functional", "stl");
		}
	}
	title("Operators");
	{
		ft::map<K, V> ma;
		ma[K(1)] = V(11);
		ma[K(2)] = V(22);
		ma[K(3)] = V(33);
		ma[K(111)] = V(111);
		ma[K(112)] = V(112);
		ma[K(160)] = V(160);

		ft::map<K, V> mb;
		mb[K(7)] = V(77);
		mb[K(8)] = V(88);
		mb[K(9)] = V(99);
		mb[K(190)] = V(0);

		ft::map<K, V> mc;
		mc[K(10)] = V(10);
		mc[K(11)] = V(11);
		mc[K(12)] = V(12);
		mc[K(13)] = V(13);

		check(1, ma == ma, true);
		check(2, ma == mb, false);
		check(3, mb == mc, false);
		check(4, ma != ma, false);
		check(5, ma != mb, true);
		check(6, mb != mc, true);

		check(7, ma > mb, false);
		check(8, mb > ma, true);
		check(9, ma > ma, false);
		check(10, mc > mb, true);
		check(11, mb > mc, false);

		check(12, ma < mb, true);
		check(13, mb < ma, false);
		check(14, ma < ma, false);
		check(15, mc < mb, false);
		check(16, mb < mc, true);

		check(17, ma <= ma, true);
		check(18, ma <= mb, true);
		check(19, mb <= ma, false);
		check(20, mc <= mb, false);
		check(21, mb <= mc, true);

		check(22, ma >= ma, true);
		check(23, ma >= mb, false);
		check(24, mb >= ma, true);
		check(25, mc >= mb, true);
		check(26, mb >= mc, false);
	}
}

#endif
