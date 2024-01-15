#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <map>

class BtcExchange
{
	public:
		BtcExchange();
		BtcExchange(const char *csv, char *file);
		BtcExchange(BtcExchange const &src);
		~BtcExchange();

//		BtcExchange &operator=(BtcExchange const &rhs);

	private:
		int	checkDate(std::string str);
		int 	checkValue(std::string str);
		int	setmap(std::string str);
		void	result(char *file);
		int 	checkValueInput(std::string str);
		void	display(std::string str);

		std::map<std::string, float>	_btcvalue;
		std::string			_firstDate;
		std::string			_lastDate;
};

#endif
