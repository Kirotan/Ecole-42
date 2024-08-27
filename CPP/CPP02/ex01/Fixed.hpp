#pragma once
#include <iostream>
#include <cmath>

class Fixed {

	public :
		Fixed(const Fixed &other);
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		Fixed &operator=(const Fixed &other);
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int	toInt(void) const;

	private :
		int					_value;
		static const int	_litt = 8;

};

		std::ostream	&operator<<(std::ostream &out, const Fixed &other);
