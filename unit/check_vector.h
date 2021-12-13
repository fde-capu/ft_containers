/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:58:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/13 02:13:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_VECTOR_H
# define CHECK_VECTOR_H

# include <typeinfo>

template<typename T>
void check_vector()
{
	title("VECTOR");
	title("Member Types");
	check( 1, typeid(typename ft::vector<T>::value_type).name()							, typeid(T).name()					);
	check( 2, typeid(typename ft::vector<T>::allocator_type).name()						, typeid(std::allocator<T>).name()	);
	check( 3, typeid(typename ft::vector<T>::reference).name()							, typeid(T&).name()					);
	check( 4, typeid(typename ft::vector<T>::const_reference).name()					, typeid(const T).name()			);
	check( 5, typeid(typename ft::vector<T>::pointer).name()							, typeid(T*).name()					);
	check( 6, typeid(typename ft::vector<T>::const_pointer).name()						, typeid(const T*).name()			);
	check( 7, typeid(typename ft::vector<T>::iterator::value_type).name()				, typeid(T).name()					);
	check( 8, typeid(typename ft::vector<T>::const_iterator::value_type).name()			, typeid(const T).name()			);
	check( 9, typeid(typename ft::vector<T>::reverse_iterator::value_type).name()		, typeid(T).name()					);
	check(10, typeid(typename ft::vector<T>::const_reverse_iterator::value_type).name()	, typeid(const T).name()			);
	check(11, typeid(typename ft::vector<T>::difference_type).name()					, typeid(ptrdiff_t).name()			);
	check(12, typeid(typename ft::vector<T>::size_type).name()							, typeid(size_t).name()				);

	title("Constructors");
	check(1, typeid(typename ft::vector<T>()).name(), typeid(typename ft::vector<T>()).name());
	check(2, ft::vector<T>(42)[41], T(0));
	check(3, ft::vector<T>(42, 40)[41], T(40));
	check(4, ft::vector<T>(42, 40, typename ft::vector<T>::allocator_type())[41], T(40));
	ft::vector<T> xx = rnd_vec<T>(10);
	{
		check(5, ft::vector<T>(xx.begin() + 1, xx.end() - 1)[0], xx[1]);
		check(6, ft::vector<T>(xx.begin() + 1, xx.end() - 1)[7], xx[8]);
		check(7, ft::vector<T>(xx.begin() + 2, xx.end() - 2, typename ft::vector<T>::allocator_type())[1], xx[3]);
		check(8, ft::vector<T>(xx.begin() + 2, xx.end() - 2, typename ft::vector<T>::allocator_type())[4], xx[6]);
		check(9, ft::vector<T>(xx), xx);
		ft::vector<T> yy = xx;
		check(10, yy, xx);
		yy = xx;
		check(11, yy, xx);

		title("Iterators");
		{
			typename ft::vector<T>::iterator yb = yy.begin();
			typename ft::vector<T>::iterator xb = xx.begin();
			check(1, *yb, *xb);
			check(2, &*yb, &*xb, NOT_EQUAL);
			typename ft::vector<T>::const_iterator cyb = yy.begin();
			typename ft::vector<T>::const_iterator cxb = xx.begin();
			check(3, *cyb, *cxb);
			check(4, &*cyb, &*cxb, NOT_EQUAL);
		}
		{
			typename ft::vector<T>::iterator yb = yy.end() - 1;
			typename ft::vector<T>::iterator xb = xx.end() - 1;
			check(5, *yb, *xb);
			check(6, &*yb, &*xb, NOT_EQUAL);
			typename ft::vector<T>::const_iterator cyb = yy.end() - 1;
			typename ft::vector<T>::const_iterator cxb = xx.end() - 1;
			check(7, *cyb, *cxb);
			check(8, &*cyb, &*cxb, NOT_EQUAL);
		}
		{
			typename ft::vector<T>::reverse_iterator yb = yy.rbegin();
			typename ft::vector<T>::reverse_iterator xb = xx.rbegin();
			check(9, *yb, *xb);
			check(10, &*yb, &*xb, NOT_EQUAL);
			typename ft::vector<T>::const_reverse_iterator cyb = yy.rbegin();
			typename ft::vector<T>::const_reverse_iterator cxb = xx.rbegin();
			check(11, *cyb, *cxb);
			check(12, &*cyb, &*cxb, NOT_EQUAL);
		}
		{
			typename ft::vector<T>::reverse_iterator yb = yy.rend() - 1;
			typename ft::vector<T>::reverse_iterator xb = xx.rend() - 1;
			check(13, *yb, *xb);
			check(14, &*yb, &*xb, NOT_EQUAL);
			typename ft::vector<T>::const_reverse_iterator cyb = yy.rend() - 1;
			typename ft::vector<T>::const_reverse_iterator cxb = xx.rend() - 1;
			check(15, *cyb, *cxb);
			check(16, &*cyb, &*cxb, NOT_EQUAL);
		}

		title("Capacity");
		check(1, xx.capacity(), typename ft::vector<T>::size_type(16));
		check(2, xx.max_size(), size_t(-1) / sizeof(T) / 2);

		yy.resize(9);
		check(4, yy.size(), typename ft::vector<T>::size_type(9));
		check(5, yy.capacity(), typename ft::vector<T>::size_type(10));
		yy.resize(13);
		check(6, yy.size(), typename ft::vector<T>::size_type(13));
		check(7, yy.capacity(), typename ft::vector<T>::size_type(18));
		yy.resize(20);
		check(8, yy.size(), typename ft::vector<T>::size_type(20));
		check(9, yy.capacity(), typename ft::vector<T>::size_type(26));
		check(10, yy.empty(), false);
		{
			ft::vector<T> zz;
			check(11, zz.empty(), true);
		}
		yy.reserve(2);
		check(12, yy.capacity(), typename ft::vector<T>::size_type(26));
		yy.reserve(26);
		check(13, yy.capacity(), typename ft::vector<T>::size_type(26));
		yy.reserve(27);
		check(14, yy.capacity(), typename ft::vector<T>::size_type(27));

		title("Element Access");
		yy = xx;
		check(1, yy[3], xx[3]);
		yy[3] = xx[4];
		check(2, yy[3], xx[4]);
		typename ft::vector<T>::reference rr = yy[5];
		check(3, rr, xx[5]);
		rr = T();
		check(4, rr, T());
		typename ft::vector<T>::const_reference cc = yy[6];
		check(5, cc, xx[6]);

		try
		{
			typename ft::vector<T>::reference oo = yy[yy.size() * 2];
			static_cast<void>(oo);
			check(6, 1, 1);
		}
		catch(...)
		{
			check(6, "accepted out-of-range", "stl");
		}

		try
		{
			typename ft::vector<T>::reference oo = yy.at(yy.size() * 2);
			static_cast<void>(oo);
			check(7, ".at() did not check range", "stl");
		}
		catch(...)
		{
			check(7, 1, 1);
		}

		check(8, yy.at(0), xx[0]);
		check(9, yy.at(1), xx[1]);
		check(10, yy.at(7), xx[7]);
		{
			typename ft::vector<T>::const_reference oo = yy.at(4);
			check(11, oo, xx[4]);
		}
		check(12, yy.front(), xx[0]);
		check(13, yy.back(), xx[9]);
		{
			typename ft::vector<T>::const_reference oo = yy.front();
			check(14, oo, yy.front());
		}
		{
			typename ft::vector<T>::const_reference oo = yy.back();
			check(15, oo, yy.back());
		}

		title("Modidfiers");
		{
			title("- assign");
			ft::vector<T> ww = xx;
			ww.assign(5, 42);
			check(1, ww.size(), typename ft::vector<T>::size_type(5));
			check(2, ww.capacity(), typename ft::vector<T>::size_type(10));
			check(3, ww.at(0), T(42));
			check(4, ww.at(4), T(42));
			check(5, ww[5], xx[5]);
			ww.assign(10, 43);
			check(6, ww.size(), typename ft::vector<T>::size_type(10));
			check(7, ww.capacity(), typename ft::vector<T>::size_type(10));
			ww.assign(15, 44);
			check(8, ww.size(), typename ft::vector<T>::size_type(15));
			check(9, ww.capacity(), typename ft::vector<T>::size_type(15));
			ww.assign(xx.begin(), xx.end());
			check(10, ww.size(), typename ft::vector<T>::size_type(10));
			check(11, ww.capacity(), typename ft::vector<T>::size_type(15));
			check(12, ww[0], xx[0]);
			check(13, ww[4], xx[4]);
			check(14, ww[9], xx[9]);
			ww.assign(xx.begin() + 1, xx.end() - 1);
			check(15, ww[0], xx[1]);
			check(16, ww[4], xx[5]);
			check(17, ww[7], xx[8]);
			ww.assign(xx.begin() + 2, xx.end() - 2);
			check(18, ww[0], xx[2]);
			check(19, ww[4], xx[6]);
			check(20, ww[5], xx[7]);
		}

		title("- push_back");
		size_t j = 0;
		for(size_t i = 1; i < 50; i++)
		{{
			ft::vector<T> ww = rnd_vec<T>(i);
			check(1 + j++, ww.capacity(), next_sqr<T>(i));
		}}
		j = 0;
		for(size_t i = 1; i < 10000; i *= 2)
		{{
			ft::vector<T> ww = rnd_vec<T>(i);
			check(50 + j++, ww.capacity(), next_sqr<T>(i));
		}}
		j = 0;
		for(size_t i = 1; i < 100000; i *= 3)
		{{
			ft::vector<T> ww = rnd_vec<T>(i);
			check(64 + j++, ww.capacity(), next_sqr<T>(i));
		}}

		title("- pop_back");
		{
			ft::vector<T> ww = rnd_vec<T>(2);
			typename ft::vector<T>::size_type ww_cap(ww.capacity());
			check(1, ww.size(), typename ft::vector<T>::size_type(2));
			ww.pop_back();
			check(2, ww.size(), typename ft::vector<T>::size_type(1));
			ww.pop_back();
			check(3, ww.size(), typename ft::vector<T>::size_type(0));
			try
			{
				ww.pop_back();
				check(4, 1, 1);
			}
			catch (std::exception& e)
			{
				check(4, "pop_back is restricted below zero size", "stl");
			}
			check(5, ww.capacity(), ww_cap);
		}

		title("- insert");
		{
			ft::vector<T> ww = rnd_vec<T>(10);
			ft::vector<T> rr = ww;
			typename ft::vector<T>::iterator it;
			it = ww.insert(typename ft::vector<T>::iterator(ww.begin() + 0), 42);
			check(1, *it, T(42));
			check(2, ww.size(), typename ft::vector<T>::size_type(11));
			check(3, *(it + 1), rr[0]);
			check(4, *(it + 10), rr[9]);
			it = ww.insert(typename ft::vector<T>::iterator(ww.begin() + 4), 42);
			check(5, *it, T(42));
			check(6, ww.size(), typename ft::vector<T>::size_type(12));
			check(7, *(it + 1), rr[3]);
			check(8, *(it + 7), rr[9]);
		}
		{
			ft::vector<T> ww = seq_vec<T>(10);
			ww.insert(ww.begin(), 3, 42);
			check(9, ww[0], T(42));
			check(10, ww[2], T(42));
			check(11, ww[3], T(0));
			check(12, ww.size(), typename ft::vector<T>::size_type(13));
			check(13, ww.capacity(), typename ft::vector<T>::size_type(16));
		}
		{
			ft::vector<T> ww = seq_vec<T>(10);
			ww.insert(ww.begin() + 4, 6, 42);
			check(14, ww[4], T(42));
			check(15, ww[9], T(42));
			check(16, ww[10], T(4));
			check(17, ww.size(), typename ft::vector<T>::size_type(16));
			check(18, ww.capacity(), typename ft::vector<T>::size_type(16));
		}
		{
			ft::vector<T> ww = seq_vec<T>(10);
			ww.insert(ww.end(), 7, 42);
			check(19, ww[10], T(42));
			check(20, ww[16], T(42));
			check(21, ww[9], T(9));
			check(22, ww.size(), typename ft::vector<T>::size_type(17));
			check(23, ww.capacity(), typename ft::vector<T>::size_type(20));
		}
		{
			ft::vector<T> ww = rnd_vec<T>(10);
			ft::vector<T> tt = ww;
			ft::vector<T> qq = seq_vec<T>(10);
			ww.insert(ww.begin(), qq.begin() + 1, qq.begin() + 4);
			check(24, ww[0], qq[1]);
			check(25, ww[2], qq[3]);
			check(26, ww[3], tt[0]);
			check(27, ww.size(), typename ft::vector<T>::size_type(13));
			check(28, ww.capacity(), typename ft::vector<T>::size_type(16));
		}
		{
			ft::vector<T> ww = rnd_vec<T>(10);
			ft::vector<T> tt = ww;
			ft::vector<T> qq = seq_vec<T>(10);
			ww.insert(ww.begin() + 4, qq.begin() + 1, qq.begin() + 7);
			check(29, ww[4], qq[1]);
			check(30, ww[9], qq[6]);
			check(31, ww[10], tt[4]);
			check(32, ww.size(), typename ft::vector<T>::size_type(16));
			check(33, ww.capacity(), typename ft::vector<T>::size_type(16));
		}
		{
			ft::vector<T> ww = rnd_vec<T>(10);
			ft::vector<T> tt = ww;
			ft::vector<T> qq = seq_vec<T>(10);
			ww.insert(ww.end(), qq.begin() + 1, qq.begin() + 8);
			check(34, ww[10], qq[1]);
			check(35, ww[16], qq[7]);
			check(36, ww[9], tt[9]);
			check(37, ww.size(), typename ft::vector<T>::size_type(17));
			check(38, ww.capacity(), typename ft::vector<T>::size_type(20));
		}

		title("- erase\t");
		{
			ft::vector<T> ww = seq_vec<T>(10);
			typename ft::vector<T>::iterator it = ww.erase(ww.begin());
			check(1, ww[0], T(1));
			check(2, ww.size(), typename ft::vector<T>::size_type(9));
			check(3, ww.capacity(), typename ft::vector<T>::size_type(16));
			check(4, *it, T(1));
			it = ww.erase(ww.begin() + 2);
			check(5, ww[2], T(4));
			check(6, ww.size(), typename ft::vector<T>::size_type(8));
			check(7, ww.capacity(), typename ft::vector<T>::size_type(16));
			check(8, *it, T(4));
			it = ww.erase(ww.end() - 1);
			check(9, ww[6], T(8));
			check(10, ww.size(), typename ft::vector<T>::size_type(7));
			check(11, ww.capacity(), typename ft::vector<T>::size_type(16));
			check(12, *(it - 1), T(8));
		}
		{
			ft::vector<T> ww = seq_vec<T>(100);
			typename ft::vector<T>::iterator it = ww.erase(ww.begin(), ww.begin() + 3);
			check(13, ww[0], T(3));
			check(14, ww.size(), typename ft::vector<T>::size_type(97));
			check(15, ww.capacity(), typename ft::vector<T>::size_type(128));
			check(16, *it, T(3));
			it = ww.erase(ww.begin() + 22, ww.begin() + 32);
			check(17, ww[21], T(24));
			check(18, ww[22], T(35));
			check(19, ww.size(), typename ft::vector<T>::size_type(87));
			check(20, ww.capacity(), typename ft::vector<T>::size_type(128));
			check(21, *it, T(35));
			it = ww.erase(ww.begin() + 66, ww.end());
			check(22, ww.back(), T(78));
			check(23, ww.size(), typename ft::vector<T>::size_type(66));
			check(24, ww.capacity(), typename ft::vector<T>::size_type(128));
			check(25, *(it - 1), T(78));
		}

		title("- swap\t");
		{
			ft::vector<T> ww = rnd_vec<T>(100);
			ft::vector<T> ww_pre = ww;
			ft::vector<T> xx = rnd_vec<T>(100);
			ft::vector<T> xx_pre = xx;
			ww.swap(xx);
			check(1, xx, ww_pre);
			check(2, ww, xx_pre);

			title("- clear\t");
			ww.clear();
			check(1, ww.size(), typename ft::vector<T>::size_type(0));
			check(2, ww.capacity(), typename ft::vector<T>::size_type(128));
			check(3, ww.empty(), true);

			title("- allocator");
			typename ft::vector<T>::allocator_type a = xx.get_allocator();
			try
			{
				T* address = a.allocate(42);
				a.deallocate(address, 42);
				check(1, 1, 1);
			}
			catch(std::exception& e)
			{
				check(1, "failed to use allocator from get_allocator()", "stl");
			}
		}

		title("Overloads");
		{
			ft::vector<T> ww = seq_vec<T>(100);
			ft::vector<T> xx = ww;
			check(1, ww == xx, true);
			check(2, ww != xx, false);
			check(3, ww < xx, false);
			check(4, ww <= xx, true);
			check(5, ww > xx, false);
			check(6, ww >= xx, true);
			xx[42] = T(0);
			check(7, ww == xx, false);
			check(8, ww != xx, true);
			check(9, xx < ww, true);
			check(10, ww < xx, false);
			check(11, xx <= ww, true);
			check(12, xx > ww, false);
			check(13, xx >= ww, false);
			xx.resize(40);
			check(14, ww == xx, false);
			check(15, ww != xx, true);
			check(16, ww < xx, false);
			check(17, xx < ww, true);
			check(18, ww <= xx, false);
			check(19, xx <= ww, true);
			check(20, ww > xx, true);
			check(21, xx > ww, false);
			check(22, ww >= xx, true);
			check(23, xx >= ww, false);

			title("extern swap");
			{
				ft::vector<T> ww = rnd_vec<T>(100);
				ft::vector<T> ww_pre = ww;
				ft::vector<T> xx = rnd_vec<T>(100);
				ft::vector<T> xx_pre = xx;

				swap(xx, ww);
				check(1, 1, 1);
				check(2, xx, ww_pre);
				check(3, ww, xx_pre);
			}
		}
	}
}

#endif
