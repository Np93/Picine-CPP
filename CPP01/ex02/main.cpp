#include <iostream>
#include <string>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "text address : " << std::endl;
	std::cout << "string str address : " << &str << std::endl;
	std::cout << "stringPTR address : " << stringPTR << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;

	std::cout << "text value : " << std::endl;
	std::cout << "string str value : " << str << std::endl;
	std::cout << "using stringPTR : " << *stringPTR << std::endl;
	std::cout << "using stringREF : " << stringREF << std::endl;

	return (0);
}
