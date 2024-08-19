# include <iostream>

void	check_argc(int argc) {

	if (argc != 1)
		std::cout << "PhoneBook does not require an argument." << std::endl;
	return ;
}
