#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <iomanip>
#include <cstring>  

#define USE_STRICT 1

typedef std::map<Time, double>::iterator mapit;


std::string trim(std::string str) {	
	size_t start, end;
	 
	start = str.find_first_not_of(" \t\v");
	end = str.find_last_not_of(" \t\v");
	if (start == std::string::npos) return ("");
	return str.substr(start, end - start + 1);
};


void	print_date(const tm &dt){
	std::cout << dt.tm_year + 1900 << "-";
	std::cout << std::setw(2);
	std::cout << std::setfill('0');
	std::cout << dt.tm_mon  + 1 << "-";
	std::cout << dt.tm_mday ;
}


void	BitcoinExchange::print_data(){
	mapit it = _data.begin();
	while (it != _data.end())
	{
		print_date(it->first._time);
		std::cout << it->first._time.tm_mday << " ";
		std::cout << it->second << "\n";
		it++;
	}
};

Time::Time(tm dt) : _time(dt){};


bool Time::operator==(const Time &t) const {
	if (_time.tm_year == t._time.tm_year
		&& _time.tm_mon == t._time.tm_mon
		&& _time.tm_mday == t._time.tm_mday)
		return 1;
	return 0;
};


bool comp::operator()(const Time &tm1, const Time &tm2) const {
	if (tm1._time.tm_year < tm2._time.tm_year) return 1;
	else if (tm1._time.tm_year == tm2._time.tm_year)
	{
	 	if (tm1._time.tm_mon < tm2._time.tm_mon) return 1;
		else if (tm1._time.tm_mon == tm2._time.tm_mon)
	 		if (tm1._time.tm_mday < tm2._time.tm_mday) return 1;
	}
	return 0;
};


void throw_err(EXCEPTIONS excp, std::string input){
	std::string err;
	input = input.size() ? input : "[ empty ]";
	switch(excp)
	{
		case NO_DATA:
			err += "Error: No date to be found.";
			break;
		case EMPTY_DB:
			err += "Error: DB seems to be empty!";
			break;
		case NEGATIVE_NUM:
			err += "Error: not a positive number.";
			break;
		case TOO_LONG:
			err += "Error: too large a number.";
			break;
		case BAD_INPUT:
			err += "Error: bad input => ";
			err += input;
			break;
		default:
			err += "Error: unexpected Error.";
	}
	throw  btcException (new std::string(err));		
}


void BitcoinExchange::eval_raw(std::string raw)
{
	Time curr = get_time(raw, '|');
			
	mapit it = _data.upper_bound(curr);

	if (it != _data.begin())
		it--;
	else if (it == _data.end())
		throw_err(EMPTY_DB, "");
	else if (!(it->first == curr))  
		throw_err(NO_DATA, "");
	double price = get_price(raw, '|');
	if (price < 0) 
		throw_err(NEGATIVE_NUM, "");
	if (price > 1000) 
		throw_err(TOO_LONG, "");
	print_date(curr._time);
	std::cout << " => " << price << " = ";
	std::cout << price * it->second << "\n";
}


void	skip_header(std::string input_file, std::ifstream &in, bool db)
{
	std::ifstream in_test;
	std::string tmp;
	std::string key, value;
	char		sep;

	sep = db ? ',' : '|';
	in_test.open(input_file);
	if (!in_test.is_open()) throw std::exception();
	getline(in_test, tmp);
	key = trim(tmp.substr(0, tmp.find(sep)));
	value = trim(tmp.substr(tmp.find(sep) + 1, tmp.length() - tmp.find(sep)));
	if ((key == "date" && value == "value" && !db)
		|| (key == "date" && value == "exchange_rate" && db))
	{
		getline(in, tmp);
	}
	in_test.close();
}


void BitcoinExchange::eval(std::string input_file) {
	try {
		std::ifstream in;
		std::string tmp;
		in.open(input_file);
		if (!in.is_open()) throw std::exception();

		skip_header(input_file, in, false);
		while (getline(in, tmp)) {
			try {
				eval_raw(tmp);
			}
			catch(std::exception &e) {
				std::cerr << e.what() << "\n"; 
			}
		}
	}
	catch(std::exception &e) {
		std::cerr << " Error input file is currpted\n";
	}
};


double stonum(std::string numstr)
{
	double	num;
	char	*endstr;
	// check if the number is in correct format

	if (!numstr.size() 
		|| (!isdigit(numstr.front()) 
			&& numstr[0] != '+'
			&& numstr[0] != '-')
		|| !isdigit(numstr.back()))
		throw_err(BAD_INPUT, numstr);
	num = std::strtod(numstr.c_str(), &endstr);
	if (*endstr)
		throw_err(BAD_INPUT, numstr);
	return num;
}


double BitcoinExchange::get_price(std::string line, char c)
{
	std::string numstr;
	//size_t idx;

	numstr = trim(line.substr(line.find(c) + 1,	
				line.length() - line.find(c) + 1));
	return stonum(numstr);
}


const Time	BitcoinExchange::get_time(std::string line, char c){
	tm dt;

	line = trim(line.substr(0, line.find(c)));
	char *s = strptime(line.c_str(), "%Y-%m-%d", &dt);
	std::string err;
	if (!s)
		throw_err(BAD_INPUT, line);
	if (s == line.c_str() || (s && s[0]))
		throw_err(BAD_INPUT, line);
	if (USE_STRICT && line.size() < 10)
			throw_err(BAD_INPUT, line);
	return Time(dt);
};


BitcoinExchange::BitcoinExchange(std::string db_file){

	try {
		std::ifstream	db;
		std::string		tmp;

		db.open(db_file);
		if (!db.is_open()) throw std::exception();
		skip_header(db_file, db, true);
		while(std::getline(db, tmp))
		{
			tmp = trim(tmp);
			if (!tmp.size()) continue;
			this->_data.insert(
				std::pair<Time, double>(get_time(tmp, ','),
				get_price(tmp, ','))
			);
		}
		db.close();
	} catch (std::exception &e)
	{
		std::cerr << "Error: db_file is curropted\n";
		exit(1);
	}
};

BitcoinExchange::BitcoinExchange(BitcoinExchange &btc){
	this->_data = btc._data;
};

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &btc){ 
	this->_data = btc._data;
	return *this;
};

BitcoinExchange::~BitcoinExchange(){};
