#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "manque un fichier frerot le .txt meme donc voila\n";
		return (0);
	}
	BtcExchange btc("data.csv", av[1]);
//	system("leaks btc");
	return (0);
}
