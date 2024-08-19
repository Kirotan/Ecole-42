#ifndef MASTER_HPP
# define MASTER_HPP
# include "PhoneBook.class.hpp"

typedef std::string str;

void	check_argc(int argc);
void	loop(void);
void	which_command(str line, PhoneBook& PB);

#endif
