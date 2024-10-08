#pragma once
#include <string>
#include <iostream>

template<typename T>
void	iter(T *array, int length, void (*func)(T&)){

	for(int i = 0; i < length; i++){
		func(array[i]);
	}
}
