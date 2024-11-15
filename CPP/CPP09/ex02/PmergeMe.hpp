#pragma once

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <deque>
#include <time.h>

class PmergeMe
{

	public:

		PmergeMe(char **argv);
		PmergeMe(PmergeMe const &src);
		PmergeMe&	operator=(PmergeMe const &assign);
		~PmergeMe();

		char**	get_argv(void) const;


	private:

		PmergeMe();

		static const int	K = 5;
		char				**_argv;
		std::deque<int>		dq;
		std::vector<int>	vec;

		void	error();
		void	displayVector(std::vector<int> &v);
		void	displayDq(std::deque<int> &d);
		void	displayArray();

		void	parsing();
		void	sort();

		void	sortVector(int beg, int end);
		void	insertionVector(int beg, int end);
		void	mergeVector(int beg, int mid, int end);

		void	sortDq(int beg, int end);
		void	insertionDq(int beg, int end);
		void	mergeDq(int beg, int mid, int end);

};
