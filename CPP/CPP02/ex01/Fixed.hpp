#pragma once
#include <iostream>
#include <cmath>

class Fixed {

	public :
	//Constructor & Destructor
		Fixed(const Fixed &other);
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();

	//Surcharger operator
		Fixed	&operator=(const Fixed &other);

	//Getter & Setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	//Members fonctions
		float	toFloat(void) const;
		int		toInt(void) const;

	private :
		int					_value;
		static const int	_litt = 8;

};

		std::ostream	&operator<<(std::ostream &out, const Fixed &other);
