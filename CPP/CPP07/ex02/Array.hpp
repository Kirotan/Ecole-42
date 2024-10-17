#pragma once
#include <iostream>
#include <string>

template<typename T>

class Array{

	public :
	//Constructor
		Array() : _n(0){
			std::cout << "Default constructor creates empty array." << std::endl;
			this->_array = new T[this->_n];
		}

		Array(const unsigned int n) : _n(n){
			std::cout << "Number constructor creates array of " << n << " elements." << std::endl;
			this->_array = new T[this->_n];
		}

		Array(Array const &copy) : _n(copy._n){
			std::cout << "Copy constructor called" << std::endl;
			this->_array = new T[this->_n];
			for(unsigned int i = 0; i < this->_n; i++)
				this->_array[i] = copy._array[i];
		}


	//Destructor
		~Array(){
			std::cout << "Destructor delete array." << std::endl;
			if(this->_array)
				delete [] this->_array;
		}


	//Surcharge operator =
		Array &operator=(const Array &other){

			if(this->_array)
				delete [] this->_array;
			if(this->_n != 0){
				this->_n = other._n;
				this->_array = new T[this->_n];
				for(unsigned int i = 0; i < this->_n; i++)
					this->_array[i] = other[i];
			}
			return *this;
		}


	//Surcharge operator []
		T &operator[](unsigned int index)const{
			if(index >= this->_n || this->_array == NULL){
				throw IndexException();
				// std::cout << "test" << std::endl;
			}
			return this->_array[index];
		}

	//Member function
		unsigned int	size()const{
			return this->_n;
		}


	//Exception
		class IndexException : public std::exception{
			public :
		const char*	what() const throw(){
			return "Invalid index.";
		}
		};


	private :
		unsigned int	_n;
		T				*_array;

};
