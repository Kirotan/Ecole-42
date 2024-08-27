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
		bool	operator<(const Fixed &other);

	private :
		int					_value;
		static const int	_litt = 8;

};

		std::ostream	&operator<<(std::ostream &out, const Fixed &other);
