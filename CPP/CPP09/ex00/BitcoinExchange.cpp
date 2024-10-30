#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

//Constructors
BitcoinExchange::BitcoinExchange(){

	this->createDataMap();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy){this->_map = copy._map;}

//Destructor
BitcoinExchange::~BitcoinExchange(){}


//Operator surcharge
BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &other){
	if(this->_map == other._map)
		return *this;
	else
		this->_map = other._map;
	return *this;
}


//Public Members functions
void		BitcoinExchange::exchangeRate(char *argv){

	(void)argv;
}


//Private Members functions
std::map<std::string, float>	BitcoinExchange::createDataMap(){

	std::string		line;
	std::ifstream	file;

	file.open("data.csv");
	if(!file.is_open()){
		std::cerr << "Error, can't open file." << std::endl;
		return this->_map;
	}

	std::getline(file, line);
	if(checkFirstLineCSV(line) == false)
		return this->_map;
	while(std::getline(file, line)){
		if(checkLineCSV(line) == true){
			insertElementMap(line);
		}
	}
	file.close();
	return this->_map;
}

const std::string	BitcoinExchange::findLine(){
	return NULL;
}

void BitcoinExchange::insertElementMap(std::string line){

	std::string		key;
	unsigned int	value;

	(void)line;
	//check key and value then add them
	this->_map.insert(std::pair<std::string, unsigned int>(key, value));
}

bool	BitcoinExchange::checkFirstLineCSV(const std::string line){

	std::string const	firstLineMustBe = "date,exchange_rate";

	if(line.compare(firstLineMustBe) == 0)
		return true;
	else{
		std::cerr << "First line isn't correct.\nThat must be : date,exchange_rate" << std::endl;
		return false;
	}
}

bool	BitcoinExchange::checkLineCSV(const std::string line){

	unsigned int			year;
	unsigned int			month;
	unsigned int			day;

	if (line.length() < 12)
		return false;
	if (line.at(4) != '-' || line.at(7) != '-' || line.at(10) != ','){
		std::cerr << "Bad format. Format must be like : YYYY-MM-DD,value" << std::endl;
		return false;
	}

	std::string	yearStr = line.substr(0, 4);
	std::string	monthStr = line.substr(5, 2);
	std::string	dayStr = line.substr(8, 2);

	year = atoi(yearStr.c_str());
	month = atoi(monthStr.c_str());
	day = atoi(dayStr.c_str());

	unsigned int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear && month == 2) {
		daysInMonth[1] = 29;
	}

	if (year < 0 || year > 2024){
		std::cerr << "Year must be between 0 and 2024." << std::endl;
		return false;
	}

	if (month < 1 || month > 12){
		std::cerr << "Month must be between 1 and 12." << std::endl;
		return false;
	}

	if(day > daysInMonth[month - 1]){
		std::cerr << "Too many days for this month."<< std::endl;
		return false;
	}

	return false;
}

void	BitcoinExchange::checkFirstLineTXT(const std::string line){
	(void)line;
}

void	BitcoinExchange::checkLineTXT(const std::string line){
	(void)line;
}

void	BitcoinExchange::exchangeCore(const std::string line, std::map<std::string, float> map){
	(void)line;
	(void)map;
}
