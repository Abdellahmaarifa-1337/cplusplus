#include <iostream>
//typedef  void (Harl::*fn)(void);
class Harl
{
	private:
	typedef  void (Harl::*fn)(void);
	std::string msg[4];
	fn fnc[4];
	public:
	Harl();
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void complain(std::string level);
};