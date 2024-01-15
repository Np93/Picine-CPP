#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	int	random = std::rand() % 3;
	A	*ret0;
	B	*ret1;
	C	*ret2;

	switch(random)
	{
		case 0:
			ret0 = new A;
			std::cout << "created new A\n";
			return (static_cast<Base *>(ret0));
		case 1:
			ret1 = new B;
			std::cout << "created new B\n";
			return (static_cast<Base *>(ret1));
		case 2:
			ret2 = new C;
			std::cout << "created new C\n";
			return (static_cast<Base *>(ret2));
	}
	return (0);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A\n";
		return ;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B\n";
		return ;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C\n";
		return ;
	}
	catch (std::bad_cast &bc)
	{
	}
}

int	main()
{
	std::srand(std::time(0));
	Base *rand = generate();
	Base &rand_ref = *rand;
	
	identify(rand);
	identify(rand_ref);
	
	delete rand;
	
	return (0);
}
