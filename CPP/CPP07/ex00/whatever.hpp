#pragma once

template<typename T>
void	swap(T &a, T &b){

	T	tmp;

	tmp = a;
	a = b;
	b = tmp;

}

template<typename T>
T	min(T a, T b){

	if(a < b)
		return a;
	else if(a > b)
		return b;
	else if(a == b)
		return b;
	return 0;
}

template<typename T>
T	max(T a, T b){

	if(a < b)
		return b;
	else if(a > b)
		return a;
	else if(a == b)
		return b;
	return 0;
}
