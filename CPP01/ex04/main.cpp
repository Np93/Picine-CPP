#include <iostream>
#include <iomanip>
#include <fstream>

void	ft_move(std::string *line, std::string r1, std::string r2)
{
	size_t	start_pos;

	while ((start_pos = (*line).find(r1)) != std::string::npos)
	{
		(*line).erase(start_pos, r1.length());
		(*line).insert(start_pos, r2);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4 || !argv[2] || !argv[3])
	{
		std::cout << "ERROR: programme arguments" << std::endl;
		return (0); 
	}
	std::ifstream	hall(argv[1]);
	if (!hall.is_open())
	{
		std::cout << "ERROR: file open failed" << std::endl;
		return (0);
	}
	std::string	new_file = (std::string)argv[1] + ".replace";
	std::ofstream	exite(new_file);
	if (!exite.is_open())
	{
		std::cout << "ERROR: output file not open" << std::endl;
		return (0);
	}
	std::string	read_line;
	std::string	replaced1 = argv[2];
	std::string	replace2 = argv[3];
	while (getline(hall, read_line))
	{
		ft_move(&read_line, replaced1, replace2);
		if (!std::cin.eof())
			exite << read_line << std::endl;
	}
	hall.close();
	exite.close();
	return (0);
}
