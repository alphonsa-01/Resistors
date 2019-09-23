#include<iostream>
#include<vector>

#include "resistor.h"

int main()
{
	std::vector<nwacc::resistor>resistors;

	resistors.emplace_back(nwacc::resistor(62.0, 100.0,5.0));
	resistors.emplace_back(nwacc::resistor(48.0, 0.1, 0.5));
	resistors.emplace_back(nwacc::resistor(12.0, 1000.0, 0.05));
	resistors.emplace_back(nwacc::resistor(75.0, 10.0, 2));
	resistors.emplace_back(nwacc::resistor(93.0, 1000000.0,0.05));
	resistors.emplace_back(nwacc::resistor(50.0, 10000.0, 10.0));
	resistors.emplace_back(nwacc::resistor(24.0, 10.0, 0.25));
	resistors.emplace_back(nwacc::resistor(27.0, 0.1, 1.0));
	resistors.emplace_back(nwacc::resistor(83.0, 100.0, 5.0));
	resistors.emplace_back(nwacc::resistor(35.0, 10.0, 0.1));

	for (const auto& resistor : resistors)
	{
		resistor.print();
	}
	return 0;
}