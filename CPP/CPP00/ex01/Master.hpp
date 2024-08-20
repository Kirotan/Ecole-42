#pragma once
# include "PhoneBook.class.hpp"

typedef std::string str;

void	check_argc(int argc);
int		check_if_number(str line);
void	loop(void);
void	which_command(str line, PhoneBook& PB);
void	check_eof();
