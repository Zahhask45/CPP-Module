#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <string>


class BitcoinExchange
{
private:
	std::map<std::string, float> db;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &rhs);

	void readDB();
	void parseFile(const std::string file);
	bool checkDate(const std::string &s);
};


#endif
