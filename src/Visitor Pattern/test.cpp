#include "visitor.h"
#include <iostream>
#include <string>
#include<thread>
using namespace lsr;

namespace Visitor2 {
	void test()
	{

		std::cout << "---------visitor pattern---------\n";
		client_visitor();
		std::cout << "---------------------------------\n\n\n";
	}
}