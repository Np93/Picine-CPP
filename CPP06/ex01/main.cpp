#include <iostream>
#include "Data.hpp"


uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	Data	data1("datacenter");

	uintptr_t	test = serialize(&data1);
	
	Data	*data2 = deserialize(test);

	std::cout << "\n\n";
	std::cout << &data1 << "\n";
	std::cout << data2 << "\n";

	std::cout << data1.getValue() << std::endl;
	std::cout << (*data2).getValue() << std::endl;

	return (0);
}
