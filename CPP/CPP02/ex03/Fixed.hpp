#pragma once
#include <iostream>
#include <cmath>

class Fixed {

	public :

		// Constructeur et destructeur
		Fixed(const Fixed &other);
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();

		// Fonction membre
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;

		// Surcharge d'operateur
		Fixed	&operator=(const Fixed &other);
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		Fixed	operator+(const Fixed &other);
		Fixed	operator-(const Fixed &other);
		Fixed	operator*(const Fixed &other);
		Fixed	operator/(const Fixed &other);
		Fixed	operator++(int value);
		Fixed	&operator++();
		Fixed	operator--(int value);
		Fixed	&operator--();

		// Fonction max min
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);


	private :
		int					_value;
		static const int	_litt = 8;

};

		std::ostream	&operator<<(std::ostream &out, const Fixed &other);
