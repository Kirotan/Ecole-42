#include "PmergeMe.hpp"
#include <bits/types/clock_t.h>
#include <cctype>
#include <ctime>
#include <ios>
#include <vector>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
	return ;
}

PmergeMe &	PmergeMe::operator=(const PmergeMe &other)
{
	this->_argv = other.get_argv();
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(char **argv) : _argv(argv)
{
	parsing();
	sort();
	return ;
}

void PmergeMe::error()
{
	std::cout << "Error" << std::endl;
	exit (1);
}

void PmergeMe::displayVector(std::vector<int> &v)
{
	std::vector<int>::iterator	it;

	std::cout << "Vector:";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::displayDq(std::deque<int> &d)
{
	std::deque<int>::iterator	it;

	std::cout << "Deque:";
	for (it = d.begin(); it != d.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

void PmergeMe::displayArray()
{
	int i = 1;
	std::cout << "Before:";
	while (_argv[i])
	{
		std::cout << " " << _argv[i];
		i++;
	}
	std::cout << std::endl;
}

void PmergeMe::parsing()
{
	int	i, j;

	i = 1;
	while (_argv[i])
	{
		j = 0;
		while (_argv[i][j])
		{
			if (isdigit(_argv[i][j]) == 0)
				error();
			j++;
		}
		vec.push_back(atoi(_argv[i]));
		dq.push_back(atoi(_argv[i]));
		i++;
	}
	displayArray();
}

void PmergeMe::sort()
{
	clock_t	start;
	clock_t	finish;

	double	time_v;
	double	time_dq;


	std::cout << "After:" << std::endl;

	start = clock();
	sortVector(0, vec.size() - 1);
	finish = clock();
	time_v = ((double) (finish - start)) / CLOCKS_PER_SEC;
	displayVector(vec);

	start = clock();
	sortDq(0, dq.size() - 1);
	finish = clock();
	time_dq = ((double) (finish - start)) / CLOCKS_PER_SEC;
	displayDq(dq);

	std::cout <<"Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << time_v << " sec." << std::endl;
	std::cout << "Time to process a range of " << dq.size() << " elements with std::deque : " << std::fixed << time_dq << " sec." << std::endl;

	return ;
}

void PmergeMe::insertionVector(int beg, int end)
{
	for (int i = beg; i < end; i++)
	{
		int temp = vec[i + 1];
		int	j = i + 1;
		while (j > beg && vec[j - 1] > temp)
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = temp;
	}
}

void PmergeMe::insertionDq(int beg, int end)
{
	for (int i = beg; i < end; i++)
	{
		int temp = dq[i + 1];
		int	j = i + 1;
		while (j > beg && dq[j - 1] > temp)
		{
			dq[j] = dq[j - 1];
			j--;
		}
		dq[j] = temp;
	}
}

void PmergeMe::mergeVector(int beg, int mid, int end)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::vector<int> left(vec.begin() + beg, vec.begin() + mid + 1);
	std::vector<int> right(vec.begin() + mid + 1, vec.begin() + end + 1);

	for (int i = beg; i <= end; i++)
	{
		if (right_i == n2)
		{
			vec[i] = left[left_i];
			left_i++;
		}
		else if (left_i == n1)
		{
			vec[i] = right[right_i];
			right_i++;
		}
		else if (right[right_i] > left[left_i])
		{
			vec[i] = left[left_i];
			left_i++;
		}
		else
		{
			vec[i] = right[right_i];
			right_i++;
		}
	}
}

void PmergeMe::mergeDq(int beg, int mid, int end)
{
	int	n1 = mid - beg + 1;
	int	n2 = end - mid;
	int	right_i = 0;
	int	left_i = 0;

	std::deque<int> left(dq.begin() + beg, dq.begin() + mid + 1);
	std::deque<int> right(dq.begin() + mid + 1, dq.begin() + end + 1);

	for (int i = beg; i <= end; i++)
	{
		if (right_i == n2)
		{
			dq[i] = left[left_i];
			left_i++;
		}
		else if (left_i == n1)
		{
			dq[i] = right[right_i];
			right_i++;
		}
		else if (right[right_i] > left[left_i])
		{
			dq[i] = left[left_i];
			left_i++;
		}
		else
		{
			dq[i] = right[right_i];
			right_i++;
		}
	}
}

void PmergeMe::sortVector(int beg, int end)
{
	if (end - beg > K)
	{
		int	mid = (beg + end) / 2;
		sortVector(beg, mid);
		sortVector(mid + 1, end);
		mergeVector(beg, mid, end);
	}
	else
		insertionVector(beg, end);
}

void PmergeMe::sortDq(int beg, int end)
{
	if (end - beg > K)
	{
		int	mid = (beg + end) / 2;
		sortDq(beg, mid);
		sortDq(mid + 1, end);
		mergeDq(beg, mid, end);
	}
	else
		insertionDq(beg, end);

}

char** PmergeMe::get_argv(void) const
{
	return (this->_argv);
}
