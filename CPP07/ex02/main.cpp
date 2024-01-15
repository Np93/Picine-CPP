#include "Array.hpp"


int	main(void)
{
	// Empty
	std::cout << std::endl << "Empty array\n";
	Array<int>	arr;
	try
	{
		std::cout << "Acessing element 0: " << arr[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		std::cout << "Assigning element 4: \n";
		arr[4] = 4;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << arr << std::endl;

	// INT
	std::cout << std::endl << "Int array\n";
	Array<int> chif(4);
	std::cout << "Before assigning: \n" << chif << std::endl;
	chif[0] = 1;
	chif[1] = 2;
	chif[2] = -64;
	chif[3] = 248;
	std::cout << "After assigning: \n" << chif << std::endl;

	// CHAR
	std::cout << std::endl << "Char array\n";
	Array<char> car(4);
	std::cout << "Before assigning: \n" << car << std::endl;
	car[0] = 'a';
	car[1] = 'b';
	car[2] = 'c';
	std::cout << "After assigning: \n" << car << std::endl;

	// FLOAT
	std::cout << std::endl << "Float array\n";
	Array<float> flo(4);
	std::cout << "Before assigning: \n" << flo << std::endl;
	flo[0] = 3.14f;
	flo[1] = -48.49f;
	flo[2] = 0.0f;
	flo[3] = 22.22f;
	std::cout << "After assigning: \n" << flo << std::endl;

	// STRING
	std::cout << std::endl << "String array\n";
	Array<std::string> stri(4);
	std::cout << "Before assigning: \n" << stri << std::endl;
	stri[0] = "First string";
	stri[1] = "Second string";
	stri[2] = "Third string";
	stri[3] = "Fourth string";
	std::cout << "After assigning: \n" << stri << std::endl;

	system("leaks Array");
	return (0);
}


