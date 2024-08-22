#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

typedef std::string str;

int	main(int argc, char **argv) {

	std::ifstream		*file;
	std::ofstream		*new_file;
	std::stringstream	buff;
	str					text;
	str					new_name;

	if (argc != 4) {
		std::cerr << "Program requires 3 arguments." << std::endl;
		exit(1);
	}

	new_name = argv[1];
	new_name.append(".replace");

	file = new std::ifstream;
	file->open(argv[1]);
	buff << file->rdbuf();
	text = buff.str();
	file->close();
	delete file;

	new_file = new std::ofstream;
	new_file->open(new_name.c_str());
	new_file->write(text.c_str(), text.size());
	new_file->close();
	delete new_file;

	return 0;
}
