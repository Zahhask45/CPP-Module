#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){this->readDB();}
BitcoinExchange::~BitcoinExchange(){}


//! NEED SOME MORE ERROR HANDLING
void BitcoinExchange::readDB(){
	
	//* ifstream only reads the file
	std::ifstream file("data.csv"); //! CAREFULL THIS NAME OR NOT IDK
	if (!file){
		std::cout << "Error opening file (missing)" << std::endl;
		throw std::exception();
	}

	std::string line;
	if (!std::getline(file, line)) {
        std::cerr << "Error: Could not read the header line!" << std::endl;
    }
	while (std::getline(file, line)){
		std::stringstream ss(line);
		std::string date, value;
		float fvalue;

		if (std::getline(ss, date, ',') && std::getline(ss, value)) {
			std::stringstream ss(value);
			ss >> fvalue;
			this->db.insert(std::pair<std::string, float>(date, fvalue));
		}
	}/* 
	std::map<std::string, float>::iterator it = db.begin();

	while (it != db.end()) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
 */
	file.close();
}


void BitcoinExchange::parseFile(const std::string arg){

	std::ifstream file(arg.c_str());
	if (!file){
		std::cout << "Error opening file (missing)" << std::endl;
		throw std::exception();
	}
	std::string line;
	if (!std::getline(file, line)) {
        std::cerr << "Error: Could not read the header line!" << std::endl;
    }
	while (std::getline(file, line)){
		std::stringstream ss(line);
		std::string date, value;
		float fvalue;

		//* REMOVE THE SPACES BEFORE AND AFTER THE '|'
		line.erase(remove(line.begin(), line.end(), ' '), line.end());


		//* READ AND PARSE THE LINE FOR NEGATIVES, WRONG DATES AND NUMBER TO HIGH(INT MAX>)
		if (std::getline(ss, date, '|') && std::getline(ss, value)) {

			std::stringstream ss(value);
			ss >> fvalue;

			//* WRONG DATES
   			if (!checkDate(date)){
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			//* NEGATIVES
			if (fvalue < 0){
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			//* LARGE NUMBER
			if (fvalue > 1000){
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}


			//* FIND THE LOWER_BOUND AKA THE CLOSEST BUT DOWN IF DATE DOES NOT EXIST IN THE DB
			std::map<std::string, float>::iterator low;
			low = db.lower_bound(date);
			if (low != this->db.begin() && low->first != date)
        		low--;


						
			std::cout << date << " => " << fvalue << " = " << low->second * fvalue << std::endl;
		}
	}
	file.close();
}

bool Leap(const int &y){
	return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)); 
}

//* DATE FORMAT YYYY-MM-DD
bool BitcoinExchange::checkDate(const std::string& s){
	int y, m, d;
    std::istringstream is(s);
    char delimiter;
    if (is >> y >> delimiter >> m >> delimiter >> d) {
		if (m < 1 || m > 12)
			return false;
		if (d < 1 || d > 31)
			return false;
		if (m == 2){
			if(Leap(y))
				return (d <= 29); 
			else
				return (d <= 28); 
		}

		if (m == 4 || m == 6 || m == 9 || m == 11)  
			return (d <= 30);
        return true;
    }
    return false;
}





