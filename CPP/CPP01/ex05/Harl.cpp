#include "Harl.hpp"

Harl::Harl() {

	std::cout << "Harl going to hunt butterflies." << std::endl;
}

Harl::~Harl() {

	std::cout << "RIP Harl." << std::endl;
}

void	Harl::complain(std::string level) {


	void	(Harl::*function[])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	lvl[] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
		if (level == lvl[i]) {
			(this->*function[i])();
			return ;
		}
}

void	Harl::_debug(void) {

	std::cout << "PIOU PIOU" << std::endl;
}

void	Harl::_info(void) {

	std::cout << "Try to reload." << std::endl;
}

void	Harl::_warning(void) {

	std::cout << "Overheating !" << std::endl;
}

void	Harl::_error(void) {

	std::cout << "Ammunition explode *BOOM*" << std::endl;
}
