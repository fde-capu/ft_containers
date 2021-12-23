/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stress.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:51:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/23 12:38:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "unit_main.h"
# include <cstdlib> // rand()

# define N 300000
# define C 500
# define X 10
# define V 5

void check_stress()
{
	Chronometer chrono;

	ft::map<int, int> m;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m.insert(ft::make_pair(rand(), rand()));
	} std::cout << N << " map inserts" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m[rand()];
	} std::cout << N << " map accesses" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m[rand()] = rand();
	} std::cout << N << " map change values" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < V; i++) {
		ft::map<int, int> foo = m;
	} std::cout << V << " map copies" << chrono << std::endl;

	ft::map<int, int> foo;
	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		foo.swap(m);
	} std::cout << N << " map swaps" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m.find(rand());
	} std::cout << N << " map finds rand" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m.erase(rand());
	} std::cout << N << " map erases rand" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m.insert(ft::make_pair(i, rand()));
	} std::cout << N << " map linear inserts" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m.find(random_int(0, N));
	} std::cout << N << " map finds scope" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		m.erase(random_int(0, N));
	} std::cout << N << " map erases scope" << chrono << std::endl;

	ft::map<int, ft::map<int, int> > mm;

	std::cout << chrono.start(); for (int i = 0; i < X; i++) {
		mm.insert(ft::make_pair(i, m));
	} std::cout << X << " map-of-map inserts" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < X; i++) {
		mm.erase(i);
	} std::cout << X << " map-of-map erase" << chrono << std::endl;


	ft::set<int> s;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		s.insert(rand());
	} std::cout << N << " set inserts rnd " << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		s.erase(rand());
	} std::cout << N << " set erases rand " << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		s.insert(i);
	} std::cout << N << " set inserts linear" << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		s.erase(random_int(0, N));
	} std::cout << N << " set erases scope " << chrono << std::endl;


	ft::vector<int> v;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		v.push_back(rand());
	} std::cout << N << " vector push_backs rnd " << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		v.push_back(i);
	} std::cout << N << " vector push_backs linear " << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		v[rand()];
	} std::cout << N << " vector access rnd " << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		v[random_int(0, N)];
	} std::cout << N << " vector access scope " << chrono << std::endl;

	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		v.pop_back();
	} std::cout << N << " vector pop_backs " << chrono << std::endl;

	ft::vector<int> vec_foo;
	std::cout << chrono.start(); for (int i = 0; i < N; i++) {
		v.swap(vec_foo);
	} std::cout << N << " vector swaps " << chrono << std::endl;

	ft::vector<ft::vector<int> > vv;
	std::cout << chrono.start(); for (int i = 0; i < C; i++) {
		vv.push_back(rnd_vec<int>(C));
	} std::cout << C << "x" << C << " vector-of-vector " << chrono << std::endl;

}
