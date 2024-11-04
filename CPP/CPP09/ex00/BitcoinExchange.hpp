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
		bool							createDataMap();
		void							InputMap(char *fileName);
		bool							checkFirstLineCSV(const std::string line);
		bool							checkLineCSV(const std::string line, unsigned short i);
		bool							checkDate(const std::string line, unsigned short i);
		bool							checkValueCSV(const std::string line, unsigned short i);
		bool							checkValueTXT(const std::string line, unsigned short i);
		bool							checkLineTXT(const std::string line, unsigned short i);
		bool							checkFirstLineTXT(const std::string line);
		void							insertElementMap(std::string line);
		void							exchangeCore(std::string line);
		bool							isLeapYear(unsigned int year);
		unsigned int					daysInMonth(unsigned int month, unsigned int year);
		unsigned int					daysSinceYearZero(unsigned int year, unsigned int month, unsigned int day);

	//Map of data
		std::map<unsigned int, float>	_map;
};
