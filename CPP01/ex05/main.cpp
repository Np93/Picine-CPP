#include "Harl.hpp"

int	main(void)
{
	Harl	hal;

	hal.complain("debug");
	hal.complain("not a message");
	hal.complain("info");
	hal.complain("warning");
	hal.complain("error");
	return (0);
}
