#pragma once
#include <iostream>
#include <string>
#include <map>

class BitcoinExchange{

	public :
	//Constructors
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);

	//Destructor
		~BitcoinExchange();

	//Operator surcharge
		BitcoinExchange	&operator=(BitcoinExchange const &other);

	//Public Members functions
		void		exchangeRate(char *fileName);

	private :
	//Private Members functions
		std::map<std::string, float>	createDataMap();
		const std::string				findLine();
		bool							checkFirstLineCSV(const std::string line);
		bool							checkLineCSV(const std::string line, unsigned short i);
		bool							checkDate(const std::string line, unsigned short i);
		bool							checkValue(const std::string line, unsigned short i);
		void							checkLineTXT(const std::string line);
		void							checkFirstLineTXT(const std::string line);
		void							insertElementMap(std::string line);
		void							exchangeCore(const std::string line, std::map<std::string, float> map);

	//Map of data
		std::map<std::string, float>	_map;
};
