#include "BitcoinExchange.hpp"

BtcExchange::BtcExchange()
{
	return;
}

BtcExchange::~BtcExchange()
{
	return;
}

BtcExchange::BtcExchange(BtcExchange const &src)
{
	*this = src;
	return;
}

//BtcExchange &BtcExchange::operator=(BtcExchange const &rhs)
//{
//	this->_btcvalue = rhs._btcvalue;

//	return (*this);
//}

BtcExchange::BtcExchange(const char *csv, char *file)
{
	_lastDate = "0000-01-01";

	std::ifstream data;

	data.open(csv, std::ios::in);
	if (!data.good())
	{
		std::cout << "probleme avec data.csv\n";
		return ;
	}
	std::string line;
	int i = 0;

	while (getline(data, line))
	{
		if (i != 0)
		{
			if (line[10] != ',')
			{
				std::cout << "Error data.csv\n";
				return ;
			}
			if (checkDate(line.substr(0, 10)))
			{
				std::cout << "Error date de data.csv\n";
				return ;
			}
			if (checkValue(line.substr(11)))
			{
				std::cout << line << std::endl;
				return ;
			}
			setmap(line);
		}
			i++;
	}
	std::string	f = "2100-01-01";
	std::string	l = "0000-01-01";

	for (std::map<std::string, float>::iterator it = _btcvalue.begin();
		it != _btcvalue.end(); it++)
	{
		if (it->first < f)
			f = it->first;
		if (it->first > l)
			l = it->first;
	}
	_firstDate = f;
	_lastDate = l;
		

	result(file);
}

int	BtcExchange::checkDate(std::string str)
{
	int day;
	int month;
	int year;

	for (int i = 0; i < 10; i++)
	{
		if ((i == 4 && str[i] == '-') || (i == 7 && str[i] == '-'))
			i++;
		if (str[i] < '0' || '9' < str[i])
			return (1);
	}
	day = std::atoi((str.substr(8, 2)).c_str());
	month = std::atoi((str.substr(5, 2)).c_str());
	year = std::atoi((str.substr(0, 4)).c_str());
	
	if (year < 1)
		return (1);
	if (month < 1 || 12 < month)
		return (1);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && 30 < day)
		return (1);
	if (month == 2 && 29 < day)
		return (1);
	if (day < 1 || 31 < day)
		return (1);
	if (_lastDate != "0000-01-01")
	{
		if (str < _firstDate)
			return (1);
		if (str > _lastDate)
		{
			std::cout << "date a la con trop grand\n";
			return (0);
		}
	}
	return (0);
}

int BtcExchange::checkValue(std::string str)
{
	int c_point = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '.')
			c_point++;
		if ((str[i] < 48 || 57 < str[i]) && str[i] != '.')
		{
			std::cout << "Error pas bonne valeur1\n";
			return (1);
		}
	}
	
	if (c_point > 1)
	{
		std::cout << "Error double '.' in data.csv\n";
		return (1);
	}
	if (c_point == 1)
	{
		float valfloat = std::atof(str.c_str());
		if (valfloat < 0)
		{
			std::cout << "Error valeur trop petite\n";
			return (1);
		}
	}
	if (c_point == 0)
	{
		int valint = std::atoi(str.c_str());
		if (valint < 0)
		{
			std::cout << "Error val trop petite\n";
			return (1);
		}
	}
	return (0);
}

int	BtcExchange::setmap(std::string str)
{
	std::string value;
	std::string date;

	date = str.substr(0, 10);
	value = str.substr(11);
	
	float f_value;

	if (value.find("."))
		f_value = std::atof(value.c_str());
	else
		f_value = static_cast<float>(std::atoi(value.c_str()));
	if (_btcvalue.count(date) > 0)
	{
		std::cout << "date existe deja\n";
		return (1);
	}
	_btcvalue[date] = f_value;
	return (0);
}

void	BtcExchange::result(char *file)
{
	std::ifstream input;

	input.open(file, std::ios::in);
	if (!input.good())
	{
		std::cout << "Error file input\n";
		return ;
	}
	std::string line;
	int i = 0;
	while(getline(input, line))
	{
		if (i != 0)
		{
			if (line.empty())
				continue;
			if (checkDate(line.substr(0, 10)))
			{
				std::cout << "Error date in file input\n";
				continue;
			}
			if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
			{
				std::cout << "Error syntax in file input\n";
				continue;
			}
			if (checkValueInput(line.substr(13)))
				continue;
			display(line);
		}
		i++;
	}
	return ;
}

int BtcExchange::checkValueInput(std::string str)
{
	int c_point = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '.')
			c_point++;
		if ((str[i] < 48 || 57 < str[i]) && str[i] != '.')
		{
			std::cout << "Error pas bonne valeur2\n";
			return (1);
		}
	}

	if (c_point > 1)
	{
		std::cout << "Error double '.' in data.csv\n";
		return (1);
	}
	if (c_point == 1)
	{
		float valfloat = std::atof(str.c_str());
		if (valfloat < 0)
		{
			std::cout << "Error valeur trop petite\n";
			return (1);
		}
		if (valfloat > 1000)
		{
			std::cout << "Error valeur trop grand\n";
			return (1);
		}
	}
	if (c_point == 0)
	{
		long check = std::atol(str.c_str());
		if (check > 2147483647)
		{
			std::cout << "valeur trop grand\n";
			return (1);
		}
		int valint = std::atoi(str.c_str());
		if (valint < 0)
		{
			std::cout << "Error val trop petite\n";
			return (1);
		}
		if (valint > 1000)
		{
			std::cout << "Error valuer trop grand\n";
			return (1);
		}
	}
	return (0);
}

void	BtcExchange::display(std::string str)
{
	std::string value;
	std::string date;

	date = str.substr(0, 10);
	value = str.substr(13);

	float f_value;

	if (value.find("."))
		f_value = std::atof(value.c_str());
	else
		f_value = static_cast<float>(std::atoi(value.c_str()));

	std::map<std::string, float>::iterator	it;
	it = _btcvalue.find(date);
	if (it == _btcvalue.end())
	{
		it = _btcvalue.begin();
		while (date > it->first && it != _btcvalue.end())
			it++;
		it--;
	}
	std::cout << date << " => " << f_value << " = "
		<< f_value *(it->second) << std::endl;
}
