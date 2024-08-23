#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

int	whichLvl(std::string level) {

	std::string	lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (level == lvl[i]) {
			return (i);
		}
	return (4);
}

void	Harl::complain(std::string level) {

	switch (whichLvl(level)) {

		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3: {
			this->_error();
			break;
		}
		default:{
			std::cerr << "Bad arguments. Choice : DEBUG | INFO | WARNING | ERROR";
			std::exit (1);
		}

	}
}

void	Harl::_debug(void) {

	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "*PIOU PIOU*" << std::endl;
	std::cout << "*PAN PAN*" << std::endl;
	std::cout << std::endl;

}

void	Harl::_info(void) {

	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Try to reload." << std::endl;
	std::cout << "Remove magazine." << std::endl;
	std::cout << std::endl;
}

void	Harl::_warning(void) {

	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Overheating !" << std::endl;
	std::cout << "*OUCH*" << std::endl;
	std::cout << std::endl;

}

void	Harl::_error(void) {

	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Ammunition explode *BOOM*" << std::endl;
	std::cout << "Dead body..." << std::endl;
	std::cout << std::endl;

}
