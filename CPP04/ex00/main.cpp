#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "time to build\n";
	const Animal* beast = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j type = " << j->getType() << "(supposed to be Dog)" << std::endl;
	std::cout << "i type = " << i->getType() << "(Supposed to be Cat)" << std::endl;

	beast->makeSound();
	i->makeSound();
	j->makeSound();

	std::cout << "\ntime to creat WrongAnimal\n";

	const WrongAnimal *badcat = new WrongCat();

	std::cout << "badcat's type = " << badcat->getType() << "(supposed to be Cat)" << std::endl;
	badcat->makeSound();

	std::cout << "\nyou see it's OKEY\n";
	std::cout << "now it's time to Destroy\n";
	delete beast;
	delete i;
	delete j;
	delete badcat;

	return (0);
}
