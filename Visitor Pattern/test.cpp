#include "visitor.h"
#include <iostream>
#include <string>
using namespace lsr;


int main()
{

	std::cout << "---------visitor pattern---------\n";
	client_visitor();
	std::cout << "---------------------------------\n\n\n";
	std::cin.get();
	return 0;
}