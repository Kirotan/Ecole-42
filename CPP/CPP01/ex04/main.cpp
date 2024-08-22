#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

typedef std::string str;

str	replaceAll(str &str, const std::string &from, const std::string &to);

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
	if (file->good() == false) {
		std::cerr << "File error." << std::endl;
		exit(1);
	}
	buff << file->rdbuf();
	text = buff.str();
	file->close();
	delete file;

	new_file = new std::ofstream;
	new_file->open(new_name.c_str());


	if (text.find(argv[2]) == std::string::npos) {
		std::cout << "Occurence not found." << std::endl;
		exit(1);
	}

	text = replaceAll(text, argv[2], argv[3]);
	new_file->write(text.c_str(), text.size());
	new_file->close();
	delete new_file;

	return 0;
}

str	replaceAll(str &text, const std::string &from, const std::string &to) {

	str			result;
	size_t		startPos = 0;
	size_t		foundPos;

	while((foundPos = text.find(from, startPos)) != str::npos) {
		result.append(text, startPos, foundPos - startPos);
		result.append(to);
		startPos = foundPos + from.length();
	}
	result.append(text, startPos, text.length() - startPos);
	text = result;
	return text;
}
