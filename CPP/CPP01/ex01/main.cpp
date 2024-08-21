# include "Zombie.hpp"

int	main(void) {

	int	N = 2;

	Zombie	*horde = zombieHorde(N, "Jean");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
