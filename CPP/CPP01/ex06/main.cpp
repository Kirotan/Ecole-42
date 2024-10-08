#include "Harl.hpp"

int	main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Not enought argument." << std::endl;
		std::exit (1);
	}
	if (argc > 2) {
		std::cout << "Too many argument." << std::endl;
		std::exit (1);
	}

	Harl		miniHarl;

	miniHarl.complain(argv[1]);

	return (0);
}
