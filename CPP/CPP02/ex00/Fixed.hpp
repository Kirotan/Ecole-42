#pragma once
#include <iostream>

class Fixed {

	public :
	//Constructor & Destructor
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();

	//Surcharge operator
		Fixed	&operator=(const Fixed &other);

	//Getter & Setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private :
		int					_value;
		static const int	_litt = 8;

};
