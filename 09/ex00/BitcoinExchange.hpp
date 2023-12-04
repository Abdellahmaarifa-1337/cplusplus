#include <iostream>
#include <ctime>
#include <map>


typedef struct tm tm;



class btcException : public std::exception {

	private:
		std::string *_msg;
	public:
		btcException(std::string *str) : _msg(str){};
		const char * what() const throw() {
			return _msg->c_str();
		};
		~btcException() throw(){delete _msg;};
};


struct Time {
	tm _time;
	Time(tm dt);
	bool operator==(const Time &t) const;
};


struct comp {
	bool operator()(const Time &tm1, const Time &tm2) const;
};


enum EXCEPTIONS {
	NO_DATA,
	EMPTY_DB,
	NEGATIVE_NUM,
	TOO_LONG,
	BAD_INPUT
};


class BitcoinExchange {
	private:
		std::map<Time, double, comp> _data;
	public:
		void eval(std::string input_file);
		void eval_raw(std::string raw);
		const Time	get_time(std::string date, char c);
		double	get_price(std::string line, char c);
		BitcoinExchange(std::string db_file);
		BitcoinExchange(BitcoinExchange &btc);
		BitcoinExchange &operator=(BitcoinExchange &btc);
		void	print_data();
		~BitcoinExchange();
};

// struct tm {
// 	int	tm_sec;		/* seconds after the minute [0-60] */
// 	int	tm_min;		/* minutes after the hour [0-59] */
// 	int	tm_hour;	/* hours since midnight [0-23] */
// 	int	tm_mday;	/* day of the month [1-31] */
// 	int	tm_mon;		/* months since January [0-11] */
// 	int	tm_year;	/* years since 1900 */
// 	int	tm_wday;	/* days since Sunday [0-6] */
// 	int	tm_yday;	/* days since January 1 [0-365] */
// 	int	tm_isdst;	/* Daylight Savings Time flag */
// 	long	tm_gmtoff;	/* offset from UTC in seconds */
// 	char	*tm_zone;	/* timezone abbreviation */
// };