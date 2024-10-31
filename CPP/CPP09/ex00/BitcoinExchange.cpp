#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "BitcoinExchange.hpp"

//Constructors
BitcoinExchange::BitcoinExchange(){

	if(this->createDataMap() == false)
		return;

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
void		BitcoinExchange::exchangeRate(char *fileName){

	InputMap(fileName);
}

//Private Members functions
bool	BitcoinExchange::createDataMap(){

	std::string		line;
	std::ifstream	file;
	unsigned short	i = 2;

	file.open("data.csv");
	if(!file.is_open()){
		std::cerr << "Error, can't open file." << std::endl;
		return false;
	}

	std::getline(file, line);
	if(checkFirstLineCSV(line) == false){
		file.close();
		return false;
	}
	while(std::getline(file, line)){
		if(checkLineCSV(line, i) == true){
			insertElementMap(line);
		}
		else{
			file.close();
			return false;
		}
		i++;
	}
	file.close();
	return true;
}

const std::string	BitcoinExchange::findLine(){
	return NULL;
}

bool	BitcoinExchange::checkLineCSV(const std::string line, unsigned short i){

	if (line.length() < 12){
		std::cout << "Line " << i << ". Not enought character." << std::endl;
		return false;
	}

	if (line[10] && line.at(10) != ','){
		std::cerr << "Line " << i << ". Bad format. Format must be like : YYYY-MM-DD,value" << std::endl;
		return false;
	}

	if (checkDate(line, i) == false)
		return false;
	if (checkValueCSV(line, i) == false)
		return false;

	return true;
}

void BitcoinExchange::insertElementMap(std::string line){

	// forbidden to have identical date
	std::string		valueStr;
	float			value;
	unsigned int	key;

	unsigned int			year;
	unsigned int			month;
	unsigned int			day;

	std::string	yearStr = line.substr(0, 4);
	std::string	monthStr = line.substr(5, 2);
	std::string	dayStr = line.substr(8, 2);

	year = atoi(yearStr.c_str());
	month = atoi(monthStr.c_str());
	day = atoi(dayStr.c_str());

	key = daysSinceYearZero(year, month, day);

	valueStr = line.substr(12);
	value = atof(valueStr.c_str());

	this->_map.insert(std::pair<unsigned int, float>(key, value));
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

bool	BitcoinExchange::checkDate(const std::string line, unsigned short i){

	if (line.at(4) != '-' || line.at(7) != '-'){
		std::cerr << "Line " << i << ". Bad format. Format must be like : YYYY-MM-DD,value" << std::endl;
		return false;
	}

	unsigned int			year;
	unsigned int			month;
	unsigned int			day;

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
		std::cerr << "Line " << i << ". Year must be between 0 and 2024." << std::endl;
		return false;
	}

	if (month < 1 || month > 12){
		std::cerr << "Line " << i << ". Month must be between 1 and 12." << std::endl;
		return false;
	}

	if(day <= 0){
		std::cerr << "Line " << i << ". Day can't be 0 or less."<< std::endl;
		return false;
	}

	if(day > daysInMonth[month - 1]){
		std::cerr << "Line " << i << ". Too many days for this month."<< std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::checkValueCSV(const std::string line, unsigned short i){

	unsigned int	j = 11;
	unsigned int	dotPlace = 0;
	bool			dot = false;

	if(line.at(j) == '-'){
		std::cerr << "Line " << i << ". Value can't be negative." << std::endl;
		return false;
	}
	if(line.at(j) == '+'){
		while(line.at(j) == '+')
			j++;
	}
	if(isdigit(line.at(j)) == 0){
		std::cerr << "Line " << i << ". Value must be digit only." << std::endl;
		return false;
	}

	while(line[j] && (isdigit(line.at(j)) > 0 || line.at(j) == '.')){
		if (line.at(j) == '.' && dot == true){
			std::cerr << "Line " << i << ". Value can't have more than one '.'." << std::endl;
			return false;
		}
		if(line.at(j) == '.'){
			dot = true;
			dotPlace = j;
		}
		if(isdigit(line.at(j)) == 0 && line.at(j) != '.'){
			std::cerr << "Line " << i << ". Value must be digit only." << std::endl;
			return false;
		}
		if(line[j + 1] && isdigit(line.at(j + 1)) == 0 && line.at(j + 1) != '.'){
			std::cerr << "Line " << i << ". Value must be digit only." << std::endl;
			return false;
		}
		j++;
	}

	if(dotPlace == j - 1){
		std::cout << "Line " << i << ". Point can't be at the end without number after." << std::endl;
		return false;
	}

	if (dot == true && (j - dotPlace - 1) > 2) {
		std::cerr << "Line " << i << ". Precision set after '.' is 2, not more." << std::endl;
		return false;
	}

	return true;
}


void	BitcoinExchange::InputMap(char *fileName){

	std::string		line;
	std::ifstream	file;
	unsigned short	i = 2;

	file.open(fileName);
	if(!file.is_open()){
		std::cerr << "Error, can't open file." << std::endl;
		return ;
	}

	std::getline(file, line);
	checkFirstLineTXT(line);
	while(std::getline(file, line)){
		if(checkLineTXT(line, i) == false){
			i++;
			continue;
		}
		exchangeCore(line);
		i++;
	}
	file.close();
}

void BitcoinExchange::exchangeCore(std::string line){

	std::string		valueStr;
	float			value;
	unsigned int	key;

	unsigned int	year;
	unsigned int	month;
	unsigned int	day;

	std::string	yearStr = line.substr(0, 4);
	std::string	monthStr = line.substr(5, 2);
	std::string	dayStr = line.substr(8, 2);

	year = atoi(yearStr.c_str());
	month = atoi(monthStr.c_str());
	day = atoi(dayStr.c_str());

	key = daysSinceYearZero(year, month, day);

	valueStr = line.substr(13);
	value = atof(valueStr.c_str());

	std::cout << year << "-" << month << "-" << day << " => " << value << " = " << std::endl;

	//faire la conversion ici !
}


void	BitcoinExchange::checkFirstLineTXT(const std::string line){

	std::string const	firstLineMustBe = "date | value";

	if(line.compare(firstLineMustBe) == 0)
		return ;
	else{
		std::cerr << "First line isn't correct.\nThat must be : date | value" << std::endl;
		return ;
	}
}

bool	BitcoinExchange::checkLineTXT(const std::string line, unsigned short i){

	if (line.length() < 14){
		std::cout << "Error: bad input => " << line << std::endl;
		return  false;
	}

	if (line[11] && line.at(11) != '|'){
		std::cerr << "Bad format. Format must be like : YYYY-MM-DD | value" << std::endl;
	}
	checkDate(line, i);
	if(checkValueTXT(line, i) == false)
 		return false;
	return true;
}

bool	BitcoinExchange::checkValueTXT(const std::string line, unsigned short i){

	unsigned int	j = 13;
	unsigned int	dotPlace = 0;
	bool			dot = false;

	if(line.at(j) == '-'){
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if(line.at(j) == '+'){
		while(line.at(j) == '+')
			j++;
	}
	if(isdigit(line.at(j)) == 0){
		std::cerr << "Value must be digit only." << std::endl;
		return false;
	}

	while(line[j] && (isdigit(line.at(j)) > 0 || line.at(j) == '.')){
		if (line.at(j) == '.' && dot == true){
			std::cerr << "Value can't have more than one '.'." << std::endl;
			return false;
		}
		if(line.at(j) == '.'){
			dot = true;
			dotPlace = j;
		}
		if(isdigit(line.at(j)) == 0 && line.at(j) != '.'){
			std::cerr << "Line " << i << "Value must be digit only." << std::endl;
			return false;
		}
		if(line[j + 1] && isdigit(line.at(j + 1)) == 0 && line.at(j + 1) != '.'){
			std::cerr << "Value must be digit only." << std::endl;
			return false;
		}
		j++;
	}

	if(dotPlace == j - 1){
		std::cout << "Point can't be at the end without number after." << std::endl;
		return false;
	}

	if (dot == true && (j - dotPlace - 1) > 2) {
		std::cerr << "Precision set after '.' is 2, not more." << std::endl;
		return false;
	}

	std::string		valueStr = line.substr(13);
	float	value = atof(valueStr.c_str());

	if (value < 0 || value > 1000){
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isLeapYear(unsigned int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned int	BitcoinExchange::daysInMonth(unsigned int month, unsigned int year){
	unsigned int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && isLeapYear(year)){
		return 29;
	}
	return daysPerMonth[month - 1];
}

unsigned int	BitcoinExchange::daysSinceYearZero(unsigned int year, unsigned int month, unsigned int day){
	unsigned int	totalDays = 0;

	for (unsigned int y = 0; y < year; ++y) {
		totalDays += isLeapYear(y) ? 366 : 365;
	}

	for (unsigned int m = 1; m < month; ++m) {
		totalDays += daysInMonth(m, year);
	}

	totalDays += day;

	return totalDays;
}
