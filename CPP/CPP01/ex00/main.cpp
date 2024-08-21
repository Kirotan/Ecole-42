# include "Zombie.hpp"

int	main(void) {

	Zombie* z = newZombie("John");
	z->announce();
	delete z;
	randomChump("Paul");

	return (0);
}
