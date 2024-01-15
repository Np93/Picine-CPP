#include "easyfind.hpp"

void	ft_display_header(std::string name)
{
	std::cout << name << std::endl;
	std::cout << "-----------------------------------------\n";
}

void	ft_disInt(int i)
{
	std::cout << i << std::endl;
}

void	ft_list_tests(void)
{
	std::list<int> lst;
	for (int i = 1; i <= 10; i++)
		lst.push_back(i);
	
	ft_display_header("                  LIST");
	std::for_each(lst.begin(), lst.end(), ft_disInt);
	std::cout << "-----------------------------------------\n";

	ft_display_header("LOOKING FOR AN EXISTING ELEMENT: [7]");
	try
	{
		std::cout << easyfind(lst, 7) << "\n";
		std::cout << "-----------------------------------------\n";
		ft_display_header("LOOKING FOR A NOT EXISTING ELEMENT: [-19]");
		std::cout << easyfind(lst, -19) << "\n";
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------------------------------\n\n";
}

void	ft_vector_tests(void)
{
	std::vector<int> vec;

	for (int i = 1; i <= 7; i++)
		vec.push_back(i);

	ft_display_header("                 VECTOR");
	std::for_each(vec.begin(), vec.end(), ft_disInt);
	std::cout << "-----------------------------------------\n";

	ft_display_header("LOOKING FOR AN EXISTING ELEMENT: [4]");
	try
	{
		std::cout << easyfind(vec, 4) << "\n";
		std::cout << "-----------------------------------------\n";
		ft_display_header("LOOKING FOR A NOT EXISTING ELEMENT: [-1]");
		std::cout << easyfind(vec, -1) << "\n";
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------------------------------\n\n";
}

void	ft_array_tests(void)
{
	std::array<int, 5> arr;
	for (int i = 1; i <= 5; i++)
		arr[i - 1] = i;

	ft_display_header("                 ARRAY");
	std::for_each(arr.begin(), arr.end(), ft_disInt);
	std::cout << "-----------------------------------------\n";

	ft_display_header("LOOKING FOR AN EXISTING ELEMENT: [1]");
	try
	{
		std::cout << easyfind(arr, 1) << "\n";
		std::cout << "-----------------------------------------\n";
		ft_display_header("LOOKING FOR A NOT EXISTING ELEMENT: [10]");
		std::cout << easyfind(arr, 10) << "\n";
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------------------------------\n\n";
}

int main(void)
{
	std::cout << std::endl;
	ft_list_tests();
	ft_vector_tests();
	ft_array_tests();
	return (0);
}
