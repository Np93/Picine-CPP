#include "Span.hpp"

int	main(void)
{
	Span	sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 5 - 3 or 11 - 9 = 2
	std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	try
	{
		Span	sp1(1, 10, 1);	
		std::cout << sp1;
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl; // 10, it's in the constructor
		std::cout << "Longest span:  " << sp1.longestSpan() << std::endl; // 9 - 1 = 8
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;	
	}

	try
	{
		Span	sp2(1, 2000001, 10);
//		std::cout << sp2;//comment regreter son choix
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl; // 10, it's in the constructor
		std::cout << "Longest span:  " << sp2.longestSpan() << std::endl; // 2000001 - 10 = 1999990
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Span with max 0 elements
	Span	sp4(0);
	std::cout << sp4;
	try
	{
		sp4.addNumber(5);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp4.shortestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sp4.longestSpan();
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
